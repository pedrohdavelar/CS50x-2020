//Necessary headers
#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_money(void); //function placeholders
int conv_money(float);
int count_coins(int);

//main function
int main(void)
{
    float f_money; //we initialize our money variable
    int i_money; //and our money expressed as a # of pennies
    f_money = get_money(); //then get our money just as expected. double value, positive
    i_money = conv_money(f_money); //and convert our money to an integer value
    printf("%i\n", count_coins(i_money)); //finally, we simply print the # of coins calculated by function count_coins
}

float get_money(void) //get_money should ask the user for a float value and only return a positive value
{
    float money;
    do
    {
        money = get_float("How much change is owed? ");
    }
    while (money <= 0);
    return money;
}

int conv_money(float f_mon) //simple function just to convert our money from a float value to a # of pennies
{
    int i_mon;
    i_mon = round(f_mon * 100);
    return i_mon;
}

int count_coins(int i_mon)  //Biggest problem: how to count our coins?
{
    int coins = 0;
    while (i_mon >= 25) //first we iterate for 25c
    {
        i_mon -= 25;
        coins ++;
    }
    while (i_mon >= 10) //then we iterate for 10c
    {
        i_mon -= 10;
        coins ++;
    }
    while (i_mon >= 5) //then 5c
    {
        i_mon -= 5;
        coins ++;
    }
    while (i_mon >= 1) //finally for 1c
    {
        i_mon -= 1;
        coins ++;
    }
    return coins;     
}
