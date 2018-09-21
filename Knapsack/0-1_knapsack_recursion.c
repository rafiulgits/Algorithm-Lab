#include<stdio.h>

// macros
#define or ||
#define is ==

// structure that will carry two integers, per items weight and its value
struct Item
{
    int value;
    int weight;
};

// function prototypes
int max_of(int item1, int item2);
int _01_knapsack(struct Item items[], int remain_weight, int remain_item);

// main function
int main()
{
    // create an array of Item
    struct Item items[] = {{60,30},{50,10},{100,25},{60,15}};

    // length of this array
    int total_item = sizeof(items)/sizeof(items[0]);

    // defined maximum weight that the beg can hold
    const int max_weight = 45;

    // print the maximum amount by calling 0-1 Knapsack function
    printf("Max cost: %d\n", _01_knapsack(items, max_weight, total_item));

    return 0;
}

/*
    0-1 Knapsack function check all possible combinations for those items
    and will find out the optimum result or more precisely highest cost
    combination
*/
int _01_knapsack(struct Item items[], int remain_weight, int remain_item)
{
    /*
        this condition will check whether any item remain for checking
        or the beg has remain weight.

        If there is no item left to make combination or beg is filled
        then we have zero cost here. so this condition will return 0

        ::::: base condition for this recursion ::::::
    */
    if(remain_item is 0 or remain_weight is 0)
        return 0;

    /*
        if next index item has greater weight then beg has available weight
        then it goes for next item check
    */
    if(items[remain_item-1].weight > remain_weight)
        return _01_knapsack(items, remain_weight, remain_item-1);

    /*
        if any of above condition does not satisfied then it means this beg
        can carry the current item. so for make combination here the program
        will check whether any better option available or not. it calls two
        recursion: one for take this item and go for next combination and another
        for without taking this item and search for better combination

        max_of function will give the answer which one is better for this recursion call
        every step of recursion this function will provide the optimum answer and
        help 0-1 Knapsack function to reach the best combination.
    */
    return  max_of( (items[remain_item-1].value +
                    _01_knapsack(items, remain_weight-items[remain_item-1].weight, remain_item-1) ),
                    _01_knapsack(items, remain_weight, remain_item-1) );

}

// return maximum value between two integer
int max_of(int item1, int item2)
{
    return (item1 > item2 ? item1 : item2);
}
