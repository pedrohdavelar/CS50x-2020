#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name;
    printf("hello, world\n");
    name = get_string("What is your name? ");
    printf("hello, %s!\n", name);
}
