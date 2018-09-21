/*
    This program will show how to sort a structure object in c with the
    help of c build in sort function and user define bubble sort function.
    c build in sort function is qsort contain by the stdlib header
*/
#include<stdio.h>
#include<stdlib.h>

/*
    create a structure name Football the will carry two integers.
*/
struct Football
{
    int shot;
    int goal;

};

/*
    function prototypes:

        compare function is used for qsort function. compare function arguments
        must design in this way. then inside the function variables should
        transform to their actual type.

        sort array is a defined function that will take the structure array and
        its length and use bubble sort for sorting them.
*/
int compare(const void *a, const void *b);
void sortArray(struct Football players[], size_t len);


int main()
{
    /*
        create an array of Football structure with initial values.
        then find out the array length.
    */
    struct Football players[] = {{10,2},{13,5},{5,1},{9,0},{11,6}};

    /*
        sizeof(obj) will return a size_t which is actually an integer.
        this size_t len can be int len.
    */
    size_t len = sizeof(players) / sizeof(players[0]);

    /*
        qsort function take 4 arguments.
            >array
            >length or items in the array
            >size of each element of the array
            >compare function in a defined way

    */
    qsort(players, len, sizeof(struct Football),compare);

    /*
        display ascending orders array with goal
        then sort in descending order with goal by bubble and display
    */
    puts("Players goal in ascending order");
    int index;
    for(index = 0; index < len; index++)
    {
        printf("\tGoal: %2d ::: Shot: %2d\n",players[index].goal, players[index].shot);
    }
    puts("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    puts("Players goal in descending order");
    sortArray(players, len);
    for(index = 0; index < len; index++)
    {
        printf("\tGoal: %2d ::: Shot: %2d\n",players[index].goal, players[index].shot);
    }
}

/*
    :::::::::  Function defining area  ::::::::::::::
*/
int compare(const void *a, const void *b)
{
    /*
        transform arguments to their actual type.

        type_cast *pointer = (type_cast*)argument;
    */
    struct Football *p1 = (struct Football*)a;
    struct Football *p2 = (struct Football*)b;

    /*
        logical part of comparison. ascending order with the value
        of goal parameter.
    */
    int dif = p1->goal - p2->goal;
    if(dif > 0) return -1;
    return 1;
}

/*
    Bubble sort function:
    Descending order with the value of goal parameter
*/
void sortArray(struct Football players[], size_t len)
{
    int i,j;
    struct Football temp;
    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(players[i].goal > players[j].goal)
            {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}
