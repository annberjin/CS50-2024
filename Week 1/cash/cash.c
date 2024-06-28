#include <stdio.h>
#include <cs50.h>

int get_change(void);
void calc_quarters(int change);

int main(void) 
{
	int change_owed = get_change();
	calc_quarters(change_owed);

}

int get_change(void) 
{
	int change;
	do 
	{
		change = get_int("Change owed: ");
	}
	while (change < 1);
	return change;
}


void calc_quarters(int change)
{
	int counter = 0;
	int div = change / 25;
	change -= 25 * div;
	counter += div;

	div = change / 10;
	change -= 10 * div;
	counter += div;

	div = change / 5;
	change -= 5 * div;
	counter += div;

	div = change / 1;
	change -= 1 * div;
	counter += div;

	printf("%i", counter);
}
