#include <iostream>

int main()
{

    int i = 87613307;
    while (1)
    {
        int num = i * (11 * 17);
        if (1 == num % 2 and 2 == num % 3 and 1 == num % 4 and 5 == num % 6 and 4 == num % 7 and 1 == num % 8 and 2 == num % 9 and 9 == num % 10 and 5 == num % 12 and 10 == num % 13 and 11 == num % 14 and 14 == num % 15 and 9 == num % 16 and 11 == num % 18 and 18 == num % 19 and 9 == num % 20 and 11 == num % 21 and 15 == num % 23 and 17 == num % 24 and 9 == num % 25 and 23 == num % 26 and 20 == num % 27 and 25 == num % 28 and 16 == num % 29 and 29 == num % 30 and 27 == num % 31 and 25 == num % 32 and 11 == num % 33 and 17 == num % 34 and 4 == num % 35 and 29 == num % 36 and 22 == num % 37)
        {
            print(num);
            break;
        }
        ++i;
    }

    return 0;
}
