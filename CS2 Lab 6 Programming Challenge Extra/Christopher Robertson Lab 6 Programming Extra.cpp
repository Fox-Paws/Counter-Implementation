#include <iostream>
using namespace std;

class Counter
{
private:
	int counter;
	int limit;
public:
	Counter();
	void setLimit(int);
	int getCount();
	int getLimit();
	void reset();
	void incr1();
	void incr10();
	void incr100();
	void incr1000();
	bool overflow();
};

int main()
{
	bool success;
	Counter count;
	char choice;
	int limIn,
		input;

	cout << "Enter a limit for the counter (1-9999):";
	cin >> limIn;
	count.setLimit(limIn);

	do
	{
		cout << "The current value of the counter is: " << count.getCount() << " and the limit of the counter is: "
			<< count.getLimit() << endl
			<< "Enter (a) for cents; (i) for dimes; (d) for dollars; (f) for tens of dollars;\n"
			<< "(r) for the reset function; (s) to set counter and (q) to quit: ";
		cin >> choice;

		switch (choice)
		{
			case 'a':
			{
				cout << "Enter (1-9) to increment:";
				cin >> input;
				for (int i = 0; i < input; i++)
				{
					count.incr1();
				}
				break;
			}
			case 'i':
			{
				cout << "Enter (1-9) to increment:";
				cin >> input;
				for (int i = 0; i < input; i++)
				{
					count.incr10();
				}
				break;
			}
			case 'd':
			{
				cout << "Enter (1-9) to increment:";
				cin >> input;
				for (int i = 0; i < input; i++)
				{
					count.incr100();
				}
				break;
			}
			case 'f':
			{
				cout << "Enter (1-9) to increment:";
				cin >> input;
				for (int i = 0; i < input; i++)
				{
					count.incr1000();
				}
				break;
			}
			case 'r':
			{
				count.reset();
				break;
			}
			case 's':
			{
				cout << "Enter a limit for the counter (1-9999):";
				cin >> limIn;
				count.setLimit(limIn);
				break;
			}
			default:
			{
				break;
			}
		}
		if (count.overflow())
		{
			cout << "You've exceeded " << count.getLimit() << " which is the limit of the counter by "
				<< (count.getCount() - count.getLimit()) << ". Counter being reset to 0.";
		}
	} while (choice != 'q');
	return 0;
}

Counter::Counter()
{
	counter = 0;
	limit = 9999;
}

void Counter::setLimit(int lim)
{
	if (lim < 0 || lim > 9999)
	{
		cout << "You've tried to set counter to an illegal value.\n"
			<< "Setting counter to a limit of 9999 by default.\n";
		limit = 9999;
	}
	else
	{
		limit = lim;
	}
	reset();
}

int Counter::getCount()
{
	return counter;
}

int Counter::getLimit()
{
	return limit;
}

void Counter::reset()
{
	counter = 0;
}

void Counter::incr1()
{
	counter++;
}

void Counter::incr10()
{
	counter += 10;
}

void Counter::incr100()
{
	counter += 100;
}

void Counter::incr1000()
{
	counter += 1000;
}

bool Counter::overflow()
{
	if (counter > limit)
	{
		counter = 0;
		return true;
	}
	else
	{
		return false;
	}
}