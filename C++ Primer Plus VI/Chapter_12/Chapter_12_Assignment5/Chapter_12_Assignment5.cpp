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
const int TRIAL_PERIOD = 100;

bool newcustomer(double x);    // czy dotar³ ju¿ nastêpny klient?

int Chapter_12_Assignment5()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// przygotowanie symulacji
	std::srand(std::time(0));  // inicjalizacja generatora liczb losowych

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";
	
	int qs = 20;
	double perhour=random(20,25);
	
	Item temp;                 // dane nowego klienta
	long turnaways = 0;        // liczba klientów odes³anych z kolejki
	long customers = 0;        // liczba klientów przyjêtych do kolejki
	long served = 0;           // liczba klientów obs³u¿onych w symulacji
	long sum_line = 0;         // ³¹czna liczba oczekuj¹cych
	int wait_time = 0;         // czas do zwolnienia bankomatu
	long line_wait = 0;        // ³¹czny czas oczekiwania




	do
	{
		cout << "\n\nMaximum queue length: " << qs << '\n';
		Queue line(qs);            // w kolejce mo¿e stan¹æ do qs klientów
		cout << "Simulated time: " << TRIAL_PERIOD << '\n';
		long cyclelimit = MIN_PER_HR * TRIAL_PERIOD;       // liczba cykli
		cout << "Average amount of clients per hour: " << perhour-- << '\n';
		double min_per_cust;       // œredni odstêp czasowy pomiêdzy klientami
		min_per_cust = MIN_PER_HR / perhour;

		// rozpoczêcie symulacji
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // mamy nowego chêtnego
			{
				if (line.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);        // czas przybycia = nr cyklu
					line.enqueue(temp);     // do³¹czenie klienta do kolejki
				}
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);        // nastêpny do obs³u¿enia
				wait_time = temp.ptime();   // czas obs³ugi = wait_time
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}

		// zestawienie wyników
		if (customers > 0)
		{
			cout << "\nCustomers:\n";
			cout << "Customers Accepted:\t" << customers << endl;
			cout << "Customers Served:\t" << served << endl;
			cout << "Customers Turned away:\t" << turnaways << endl;
			cout << "Average Queue length:\t";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout << (double)sum_line / cyclelimit << endl;
			cout << "Average wait time: "
				<< (double)line_wait / served << " minute/s\n";
		}
		else
			cout << "No clients!\n";
	} while (((double)line_wait / served) >= 1.0);
	cout << "ready!\n";
	_getch();
	return 0;
}

// x = œredni odstêp czasowy (w minutach) pomiêdzy potencjalnymi klientami
// jeœli wartoœæ zwracana to true, w danej minucie pojawi³ siê klient
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
/*
5. The Bank of Heather has performed a study showing that ATM customers won’t
wait more than one minute in line.Using the simulation from Listing 12.10,find a
value for number of customers per hour that leads to an average wait time of one
minute.(Use at least a 100-hour trial period.)
*/