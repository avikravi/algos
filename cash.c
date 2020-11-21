#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    /* instantiate dollars variable for input */
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0.00);
    
    /* start calculations */
    /* only using quarters, dimes, nickels, pennies */
    int cents = round(dollars * 100);
    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = (cents - (quarters * 25) - (dimes * 10)) / 5;
    int pennies = (cents - (quarters * 25) - (dimes * 10) - (nickels * 5));
    int coins = quarters + dimes + nickels + pennies;
    
    /* print answer */
    printf("%d\n", coins);
}