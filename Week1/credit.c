#include <stdio.h>
#include <cs50.h>

//being lazy didn`t work, so lets convert some of that mess of code into functions!
int sum_digits(int);

int main(void)
{
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;
    int d5 = 0;
    int d6 = 0;
    int d7 = 0;
    int d8 = 0;
    int d9 = 0;
    int d10 = 0;
    int d11 = 0;
    int d12 = 0;
    int d13 = 0;
    int d14 = 0;
    int d15 = 0;
    int d16 = 0;
    long card;
    do
    {
        card = get_long("What is your credit card number? ");
    }
    while (card < 0 || card > 9999999999999999); //ensuring that our credit card number is at least positive AND has at max 16 digits 
//if you can`t solve it, just brute force it =D

//each digit can be obtained by subtracting the card number by 10 times the position of the digit (eg: for the 1st digit, subract by 1000 0000 0000 0000 ) and then count the number of
//subtractions. They will be the number of the digit. Stupid? Yes, but if it works, it ain`t stupid
//Digit 1
    while (card >= 1000000000000000) //we count our i variable up until our card number becomes less than 1000 0000 0000 0000
    {
        card -= 1000000000000000; //we subtract the card by 1000 0000 0000 0000
        d1++; //and add 1 to our first digit
    }
//digit 2
    while (card >= 100000000000000) //now with 14 zeroes xD
    {
        card -= 100000000000000; //we subtract the card by 100 0000 0000 0000
        d2++; //and add 1 to our first digit
    }
//digit 3
    while (card >= 10000000000000) //now with 13 zeroes xD
    {
        card -= 10000000000000; //we subtract the card by 10 0000 0000 0000
        d3++; //and add 1 to our first digit
    }
    //digit 4
    while (card >= 1000000000000) //now with 12 zeroes xD
    {
        card -= 1000000000000; //we subtract the card by 1 0000 0000 0000
        d4++; //and add 1 to our first digit
    }
//digit 5
    while (card >= 100000000000) //now with 11 zeroes xD
    {
        card -= 100000000000; //we subtract the card by 1000 0000 0000
        d5++; //and add 1 to our first digit
    }
//digit 6
    while (card >= 10000000000) //now with 10 zeroes xD
    {
        card -= 10000000000; //we subtract the card by 100 0000 0000
        d6++; //and add 1 to our first digit
    }        
//digit 7
    while (card >= 1000000000) //now with 9 zeroes xD
    {
        card -= 1000000000; //we subtract the card by 10 0000 0000
        d7++; //and add 1 to our first digit
    }        
//digit 8
    while (card >= 100000000) //now with 8 zeroes xD
    {
        card -= 100000000; //we subtract the card by 1 0000 0000
        d8++; //and add 1 to our first digit
    }        
//digit 9
    while (card >= 10000000) //now with 7 zeroes xD
    {
        card -= 10000000; //we subtract the card by 1000 0000
        d9++; //and add 1 to our first digit
    }        
//digit 10
    while (card >= 1000000) //now with 6 zeroes xD
    {
        card -= 1000000; //we subtract the card by 100 0000
        d10++; //and add 1 to our first digit
    }        
//digit 11
    while (card >= 100000) //now with 5 zeroes xD
    {
        card -= 100000; //we subtract the card by 10 0000
        d11++; //and add 1 to our first digit
    }        
//digit 12
    while (card >= 10000) //now with 4 zeroes xD
    {
        card -= 10000; //we subtract the card by 1 0000
        d12++; //and add 1 to our first digit
    }        
//digit 13
    while (card >= 1000) //now with 3 zeroes xD
    {
        card -= 1000; //we subtract the card by 1000
        d13++; //and add 1 to our first digit
    }        
//digit 14
    while (card >= 100) //now with 2 zeroes xD
    {
        card -= 100; //we subtract the card by 100
        d14++; //and add 1 to our first digit
    }        
//digit 15
    while (card >= 10) //now with 1 zero xD
    {
        card -= 10; //we subtract the card by 10
        d15++; //and add 1 to our first digit
    }        
//digit 16
    while (card >= 1) //now with 1 zero xD
    {
        card -= 1; //we subtract the card by 1
        d16++; //and add 1 to our first digit
    }        
//Before the shenanigans below, lets check which brand the card is; also a bool variable is created to know if the brand was detected. this will be explained later
    string brand = "";
    bool detected = false;
    if (d2 == 3 && (d3 == 4 || d3 == 7)) //Amex
    {
        brand = "AMEX";
        detected = true;
    }
    else if (d1 == 5 && (d2 == 1 || d2 == 2 || d2 == 3 || d2 == 4 || d2 == 5)) //Mastercard
    {
        brand = "MASTERCARD";
        detected = true;
    }
    else if (d1 == 4) //Visa
    {
        brand = "VISA";
        detected = true;
    }
//Lets now add some simple debugging to see if everything is working as expected. card should now be zero and d1..d16 should print the respective digits.
//    printf("card should now be zero. card is: %li\n", card);
//    printf("d1 %i d2 %i d3 %i d4 %i d5 %i d6 %i d7 %i d8 %i d9 %i d10 %i d11 %i d12 %i d13 %i d14 %i d15 %i d16 %i\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16);
//It f*****g works! Commenting because i don`t want to erase these two lines.
//Now finally for the algorithm
//first the cases in which the digits multiplied by 2 end up bigger than 10

    d1 *= 2;
    if (d1 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d1 = sum_digits(d1);
    }
    d3 *= 2;
    if (d3 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d3 = sum_digits(d3);
    }
    d5 *= 2;
    if (d5 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d5 = sum_digits(d5);
    }
    d7 *= 2;
    if (d7 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d7 = sum_digits(d7);
    }    
    d9 *= 2;
    if (d9 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d9 = sum_digits(d9);
    }    
    d11 *= 2;
    if (d11 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d11 = sum_digits(d11);
    }    
    d13 *= 2;
    if (d13 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d13 = sum_digits(d13);
    }    
    d15 *= 2;
    if (d15 >= 10) //if the digit result in double digits, then we sum the digits. Boy, this was uglier before....
    {
        d15 = sum_digits(d15);
    }    
    int valid = 0; //this will hold the result of the validity calculation.
    valid = d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + d10 + d11 + d12 + d13 + d14 + d15 + d16;
//moar debugging
//    printf("d1 %i d2 %i d3 %i d4 %i d5 %i d6 %i d7 %i d8 %i d9 %i d10 %i d11 %i d12 %i d13 %i d14 %i d15 %i d16 %i\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16);
//    printf("valid: %i\n", valid);
//at last....
    if (valid % 10 != 0 || detected == false) //the card isn`t valid OR the brand wasn`t detected
    {
        printf("INVALID\n");
    }
    else //checksum is valid and a brand was detected. Victory!
    {
        printf("%s\n", brand);
    }
}
// this function will be used to evaluate the sum of the digits in the case that the digit multiplied by 2 is bigger than 10
int sum_digits(int number) 
{
    int i = 0;    
    while (number >= 10)
    {
        number -= 10;
        i++;
    }
    while (number >= 1)
    {
        number--;
        i++;
    }
    return i;
}
        

