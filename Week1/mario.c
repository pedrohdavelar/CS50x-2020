#include <cs50.h>
#include <stdio.h>

//declaring functions to be used
void printline(int l, int h);
void printblock(int n);
void printspace(int n);

int main(void)
{
    int h; //height of the pyramid
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 ||  h > 8); //pool for height until a positive integer smaller than is input
    
    for (int i = 1; i <= h; i++) //print h lines. starting i as 1 so it works well with printspace() and printblock()
    {
        printline(i, h);
    }
}

//print the line n of the piramid with height h
void printline(int n, int h)
{
    printspace(h - n);
    printblock(n);
    printf("\n");
}

//print n `#` blocks 
void printblock(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

//print n ` ` spaces
void printspace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }  
}
