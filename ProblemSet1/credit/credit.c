// libraries
#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool check_valid(long n);
void check_type(long n, int length);
int get_length(long n);
int main(void)
{
    long n = get_long("Number: ");
    if (check_valid(n) == true)
    {
        int x = get_length(n);
        check_type(n, x);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_valid(long n)
{
    // prompt the user for the number
    // get the sum of the alternate digit
    bool isAlternatedigit = false;
    int sum = 0;
    int sum_mul = 0;
    while (n > 0)
    {
        if (isAlternatedigit == true)
        {
            int digit_mul = n % 10;
            digit_mul *= 2;
            if (digit_mul > 9)
            {
                digit_mul = digit_mul / 10 + digit_mul % 10;
            }
            sum_mul = sum_mul + digit_mul;
        }
        if (isAlternatedigit == false)
        {
            int digit = n % 10;
            sum = sum + digit;
        }
        isAlternatedigit = !isAlternatedigit;
        n = n / 10;
    }
    int valid_number = sum + sum_mul;
    if (valid_number % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_length(long n)
{
    int length = 0;
    while (n > 0)
    {
        length = length + 1;
        n /= 10;
    }
    return length;
}
// get the 2 first digit
void check_type(long n, int length)
{
    int first_number = n / pow(10, length - 2);
    if (length == 15 && (first_number == 34 || first_number == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && 50 < first_number && first_number < 56)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && 40 <= first_number && first_number <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
