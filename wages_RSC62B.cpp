#include<iostream>
#include <ctime>
#include <cstdlib>

#define MAX_NUMBERS 50

using namespace std;

struct Wage
{
    int position;
    int wage;
};

int* generate_wages();
int get_average_wage(int* wages);
int get_below_average_count(int* wages, int average);
bool is_below_average(int wage, int average);
struct Wage get_highest_wage(int* wages);
struct Wage get_lowest_wage(int* wages);

int main()
{
    srand(time(NULL));

    int *wages;
    struct Wage highest_wage;
    struct Wage lowest_wage;
    int average = 0;
    int below_average_count = 0;

    wages = generate_wages();

    /* Output format for the wages' list */
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        cout << i+1 << " => " << wages[i] << " EUR" << endl;
    }

    average = get_average_wage(wages);
    lowest_wage = get_lowest_wage(wages);
    highest_wage = get_highest_wage(wages);

    /* Output format for the average, etc */
    cout << "\n\nThe average of the wages: " << average << " EUR" << endl << endl;
    cout << "The highest wage: \n" << (highest_wage.position +  1)<< " => " << highest_wage.wage << " EUR" << endl << endl;
    cout << "The lowest wage: \n" << (lowest_wage.position +  1) << " => " << lowest_wage.wage << " EUR" << endl << endl;

    /* Showing  how many people who have wage below the average*/
    below_average_count = get_below_average_count(wages, average);
    cout << "There are " << below_average_count << " people who have wage under the average.\n";

    /* Print the list for people who have wage below the average*/
    cout << "\nPeople with wage below average: " << endl;

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        if (is_below_average(wages[i], average))
        {
            cout << i+1 << " => " << wages[i] << " EUR" << endl;
        }
    }

    system("PAUSE");

    return 0;
}


int* generate_wages()
{
    static int numbers[MAX_NUMBERS];

    srand(time(NULL));

    /* Generate number between 150 and 1000 */
    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        numbers[i] = 150 + (rand() % 851);
    }
    return numbers;
}

int get_average_wage(int* wages)
{
    int average = 0, sum = 0;

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        /* Calculating the sum in order to get the average at the end */
        sum += wages[i];
    }
    /* Calculating the average */
    average = sum / MAX_NUMBERS;

    return average;
}

/* Convert the value to boolean */
bool is_below_average(int wage, int average)
{
    if (wage < average)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Highest wages */
struct Wage get_highest_wage(int* wages)
{
    static struct Wage highest_wage;

    highest_wage.wage = wages[0];
    highest_wage.position = 0;

    for (int i = 1; i < MAX_NUMBERS; i++)
    {
        if (wages[i] > highest_wage.wage)
        {
            highest_wage.wage = wages[i];
            highest_wage.position = i;
        }
    }

    return highest_wage;
}

/*Lowest wages*/
struct Wage get_lowest_wage(int* wages)
{

    static struct Wage lowest_wage;

    lowest_wage.wage = wages[0];
    lowest_wage.position = 0;


    for (int i = 1; i < MAX_NUMBERS; i++)
    {
        if (wages[i] < lowest_wage.wage)
        {
            lowest_wage.wage = wages[i];
            lowest_wage.position = i;
        }
    }

    return lowest_wage;
}

/* Below the average */
int get_below_average_count(int* wages, int average)
{
    int below_average_count = 0;

    for (int i = 0; i < MAX_NUMBERS; i++)
    {
        if (is_below_average(wages[i], average))
        {
            below_average_count++;
        }
    }

    return below_average_count;
}
