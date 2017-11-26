#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "Ch12_A6_queue.h"
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

static bool newcustomer(double x);    // czy dotar³ ju¿ nastêpny klient?

int Chapter_12_Assignment6()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// przygotowanie symulacji
	std::srand(std::time(0));  // inicjalizacja generatora liczb losowych

	cout << "Studium przypadku: bankomat Banku Stu Kas\n";

	int qs = random(20,30);
	double perhour = random(30, 40);

	Ch12_A6::Item temp;                 // dane nowego klienta
	long turnaways = 0;        // liczba klientów odes³anych z kolejki
	long customers = 0;        // liczba klientów przyjêtych do kolejki
	long served = 0;           // liczba klientów obs³u¿onych w symulacji
	
	long sum_line = 0;         // ³¹czna liczba oczekuj¹cych
	int wait_time = 0;         // czas do zwolnienia bankomatu
	long line_wait = 0;        // ³¹czny czas oczekiwania
	
	long sum_line2 = 0;			//total amount of customres waiting in line2
	int wait_time2 = 0;  		//time to free ATM2
	long line2_wait = 0;		//total wait time of line2




	do
	{
		if (perhour == 0) { cout << "\aERROR: max queue length too big! Lowering.\n"; qs--; perhour = random(20, 35); };
		cout << "\n\nMaximum queue length: " << qs << '\n';
		Ch12_A6::Queue line(qs);            // w kolejce mo¿e stan¹æ do qs klientów
		Ch12_A6::Queue line2(qs);
		cout << "Simulated time: " << TRIAL_PERIOD << '\n';
		long cyclelimit = MIN_PER_HR * TRIAL_PERIOD;       // liczba cykli
		cout << "Average amount of clients per hour: " << perhour-- << '\n'
			<<"----------------------------------------------------------------------\n";
		double min_per_cust;       // œredni odstêp czasowy pomiêdzy klientami
		min_per_cust = MIN_PER_HR / perhour;

		turnaways = customers = served = sum_line = wait_time = line_wait = sum_line2 = wait_time2 = line2_wait = 0;

		// rozpoczêcie symulacji
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // mamy nowego chêtnego
			{
				if (line.isfull() && line2.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);        // czas przybycia = nr cyklu
					if (line2.queuecount() < line.queuecount()) { line2.enqueue(temp); } else line.enqueue(temp);     // do³¹czenie klienta do kolejki
				};
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);        // nastêpny do obs³u¿enia
				wait_time = temp.ptime();   // czas obs³ugi = wait_time
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time <= 0 && !line2.isempty())
			{
				line2.dequeue(temp);        // nastêpny do obs³u¿enia
				wait_time2 = temp.ptime();   // czas obs³ugi = wait_time
				line2_wait += cycle - temp.when();
				served++;
			};
			if (wait_time > 0) wait_time--;
			if (wait_time2 > 0) wait_time2--;
			sum_line += line.queuecount();
			sum_line2 += line2.queuecount();
		}

		// zestawienie wyników
		if (customers > 0)
		{
			cout << "Customers Accepted:\t" << customers << endl;
			cout << "Customers Served:\t" << served << endl;
			cout << "Customers Turned away:\t" << turnaways << endl;
			cout << "Average Queue length: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout << "\tATM1: " << (double)sum_line / cyclelimit
				<< "\tATM2: "<<(double)sum_line2 / cyclelimit << endl;
			cout << "Average wait time:"
				<<"\tATM1: " << (double)line_wait / served 
				<< "\tATM2:" << (double)line2_wait / served << " minute/s\n"
				<< "----------------------------------------------------------------------\n";
		}
		else
			cout << "No clients!\n";
	/*
		if (customers > 0)
		{
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
	*/
	} while (((((double)line_wait+(double)line2_wait )/2)/ served) >= 1.0);

	cout << "\n\n\aIf max queue length is " << qs << " two ATMs can serve " << (double)perhour << " clients per hour in wait time " << (double)line_wait / served << "(ATM1) and " << (double)line2_wait / served << "(ATM2), " << ((((double)line_wait+(double)line2_wait )/2)/ served) << "(Average).\n";
	_getch();
	return 0;
}

// x = œredni odstêp czasowy (w minutach) pomiêdzy potencjalnymi klientami
// jeœli wartoœæ zwracana to true, w danej minucie pojawi³ siê klient
static bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}

/*
6. The Bank of Heather would like to know what would happen if it added a second
ATM. Modify the simulation in this chapter so that it has two queues.Assume that
a customer will join the first queue if it has fewer people in it than the second
queue and that the customer will join the second queue otherwise.Again,find a
value for number of customers per hour that leads to an average wait time of one
minute.(Note:This is a nonlinear problem in that doubling the number of ATMs
doesn’t double the number of customers who can be handled per hour with a one
minute wait maximum.)
*/