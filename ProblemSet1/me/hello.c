// libraries
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "); // get input user
    printf("hello, %s\n", name);                    // print hello user
}
