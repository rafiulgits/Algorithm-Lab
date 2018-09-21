#include<stdio.h>

// macros
#define or ||
#define is ==

// Item structure will carry two integer variable one for item weight and another value
struct Item
{
    int value;
    int weight;
};

// maximum weight of the beg
const int max_weight = 45;

// static integer variables for traverse
static int index, weight;

// function prototypes
int max_of(int item1, int item2);
int _01_knapsack_dp(struct Item items[], int length);

// main function
int main()
{
    // create an array of items and find out the length of the array
    struct Item items[] = {{60,30},{50,10},{100,25},{60,15}};
    int length = sizeof(items)/sizeof(items[0]);

    // print out the result by calling 0-1 Knapsack function
    printf("Max cost: %d \n",_01_knapsack_dp(items, length));

}

int _01_knapsack_dp(struct Item items[], int length)
{
    /*
        Dynamic Programming:
            A table of 2D array that will contain every item index and
            associated weights value (cost)

            table model:

            0 0 0 0 0 0
            0 x x x x x
            0 x x x x x
            0 x x x x X <-max

    */
    int arr[length+1][max_weight+1];

    // traverse the table row
    for(index=0; index<=length; index++)
    {
        // traverse the table column
        for(weight=0; weight<=max_weight; weight++)
        {
            // from model : first row and first column value = 0
            if(weight is 0 or index is 0)
                arr[index][weight] = 0;

            /*
                if current item weight cross the weight of this index
                then set the previous one's value here. #DP concept
            */
            else if(items[index-1].weight > weight)
                arr[index][weight] = arr[index-1][weight];

            /*
                if current item can take then chose the better one;
                whether taking this item can cost much greater then the
                previous selected.

                max_of function helps to find out this
            */
            else
                arr[index][weight] = max_of(items[index-1].value+
                                            arr[index-1][weight-items[index-1].weight],
                                            arr[index-1][weight]);
        }
    }

    // return the maximum value
    return arr[length][max_weight];
}

// check the maximum between two integers
int max_of(int item1, int item2)
{
    return (item1 > item2 ? item1 : item2);
}
