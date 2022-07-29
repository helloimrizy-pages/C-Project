#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#define MAX_NUMBERS 20

int* generate_numbers()
{
    int number;

    /* Here we will store the unique numbers that can be divided by 2 or 5*/
    static int numbers[MAX_NUMBERS];

    /* Here we will store the numbers already seen */
    int seen[201];

    srand(time(NULL));


    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        while (true)
        {
            /* generate number between 1 and 200: */
            number = rand() % 200 + 1;

            /* check if the number is already taken */
            if (seen[number] == 1)
            {
                continue;
            }
            /* check if the number can be divided by 2 or 5 */
            if ((number % 2 == 0 ) || (number % 5 == 0))
            {
                seen[number] = 1;
                numbers[i] = number;
                break;
            }
        }
    }

    return numbers;
}

int main()
{
    int *numbers;

    numbers = generate_numbers();

    cout << "Generated numbers: " << endl;
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;

    system("PAUSE");
    return 0;
}
