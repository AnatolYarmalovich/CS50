#include <stdio.h>
#include "../cs50lib/cs50.h"

int calculate_quarters(int cash);
int calculate_dimes(int cash);
int calculate_nickels(int cash);
int calculate_pennies(int cash);
int get_cents();
int change_calculate(int cash);


int main(void) {
    int cash = get_cents();
    int result = change_calculate(cash);
    printf("%i\n", result);
}

int get_cents()
{
    int cash;
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    return cash;
}

int change_calculate(int cash)
{
    int coins = 0;
    int money = cash;

    while (calculate_quarters(money) > 0)
    {
        money -= 25;
        coins ++;
    }

    while (calculate_dimes(money) > 0)
    {
        money -= 10;
        coins ++;
    }

    while (calculate_nickels(money) > 0)
    {
        money -= 5;
        coins ++;
    }

    while ((calculate_pennies(money))> 0)
    {
        money -= 1;
        coins ++;
    }

    return coins;
}

int calculate_quarters(int cash)
{
    return cash / 25;
}

int calculate_dimes(int cash)
{
    return  cash / 10;
}

int calculate_nickels(int cash)
{
    return cash / 5;
}

int calculate_pennies(int cash)
{
    return cash / 1;
}