#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "queue.h"
#include "ctime"
#include "cstdlib"

/*
-Time to wait <1min
-Find: amount of customers per minute that causes time to wait <1m
-use 100h trial period (6000min).
*/
const int MIN_PER_HR = 60;
const int MAX_TIME_TO_WAIT = 1;
const int TRIAL_PERIOD = 100 * MIN_PER_HR;

bool newcustomer(double x);    // czy dotar� ju� nast�pny klient?

int Chapter_12_Assignment5()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// przygotowanie symulacji
	std::srand(std::time(0));  // inicjalizacja generatora liczb losowych

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	cout << "Podaj maksymaln� d�ugo�� kolejki: ";
	int qs;
	cin >> qs;
	Queue line(qs);            // w kolejce mo�e stan�� do qs klient�w

	cout << "Podaj symulowany czas (w godzinach): ";
	int hours;                 // liczba godzin symulacji
	cin >> hours;
	// symulacja z jednominutow� rozdzielczo�ci�
	long cyclelimit = MIN_PER_HR * hours;       // liczba cykli

	cout << "Podaj �redni� liczb� klient�w na godzin�: ";
	double perhour;            // �rednia liczba nowych klient�w na godzin�
	cin >> perhour;
	double min_per_cust;       // �redni odst�p czasowy pomi�dzy klientami
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;                 // dane nowego klienta
	long turnaways = 0;        // liczba klient�w odes�anych z kolejki
	long customers = 0;        // liczba klient�w przyj�tych do kolejki
	long served = 0;           // liczba klient�w obs�u�onych w symulacji
	long sum_line = 0;         // ��czna liczba oczekuj�cych
	int wait_time = 0;         // czas do zwolnienia bankomatu
	long line_wait = 0;        // ��czny czas oczekiwania

							   // rozpocz�cie symulacji
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))  // mamy nowego ch�tnego
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);        // czas przybycia = nr cyklu
				line.enqueue(temp);     // do��czenie klienta do kolejki
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);        // nast�pny do obs�u�enia
			wait_time = temp.ptime();   // czas obs�ugi = wait_time
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	// zestawienie wynik�w
	if (customers > 0)
	{
		cout << " liczba klient�w przyj�tych: " << customers << endl;
		cout << "liczba klient�w obs�u�onych: " << served << endl;
		cout << " liczba klient�w odes�anych: " << turnaways << endl;
		cout << "    �rednia d�ugo�� kolejki: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "    �redni czas oczekiwania: "
			<< (double)line_wait / served << " minut\n";
	}
	else
		cout << "Brak klient�w!\n";

	cout << "Gotowe!\n";

	return 0;
}

// x = �redni odst�p czasowy (w minutach) pomi�dzy potencjalnymi klientami
// je�li warto�� zwracana to true, w danej minucie pojawi� si� klient
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
/*
5. The Bank of Heather has performed a study showing that ATM customers won�t
wait more than one minute in line.Using the simulation from Listing 12.10,find a
value for number of customers per hour that leads to an average wait time of one
minute.(Use at least a 100-hour trial period.)
*/