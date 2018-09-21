/*
    Fractional Knapsack:
        pick high price item from the item list
        it is possible to pick item fractionally.
            available = 5unit item weight 7unit; so
            it is possible to pick 5unit
*/
#include<stdio.h>
#include<stdlib.h>

/*
    set my beg max weight 45 unit
    for loop indexing i
*/
const int MAX_WEIGHT = 45;
static int i;

/*
    item structure will carry two integer
    item weight and value of this weight
*/
struct Item
{
    int weight;
    int value;
};

/*
    structure object compare function for sorting

    >find out the value of per unit item
    >then compare which one's per unit is higher then another
*/
int compare(const void *a, const void *b)
{
    struct Item *i1 = (struct Item*)a;
    struct Item *i2 = (struct Item*)b;

    float ratio1 = (float) i1->value/i1->weight;
    float ratio2 = (float) i2->value/i2->weight;

    if(ratio1 > ratio2) return -1;
    return 1;
}

int main()
{
    /*
        create a list of items to pick
        then find out the list length.
    */
    struct Item items[] = { {20,80},{10,50},{30,90},{10,20} };
    size_t len = sizeof(items) / sizeof(items[0]);

    /*
        sort with built-in function qsort by passing needed arguments
        @see https://github.com/avoidcloud/Algorithm-Lab/blob/master/Recap/intro_structure_c.c
    */
    qsort(items,len, sizeof(struct Item), compare);

    /*
        initialization of my current beg and cost
    */
    int knapWeight = 0;
    float cost = 0.0f;

    /*
        traverse the sorted array
            if beg can take current index item whole then take the whole
            otherwise take as much beg can hold or remain
    */
    for(i=0; i<len; i++)
    {
        if(knapWeight+items[i].weight <= MAX_WEIGHT)
        {
            knapWeight += items[i].weight;
            cost += items[i].value;
        }
        else
        {
            int availableKnapWeight = MAX_WEIGHT - knapWeight;
            float perWeightValue = (float)items[i].value/items[i].weight; // per unit value
            cost += (perWeightValue*availableKnapWeight); // cost of available weight beg can pick
            knapWeight = MAX_WEIGHT;
            break; // as beg is filled up; so, no need to check others
        }
    }
    printf("Max Cost for %d weight: %.2f\n",MAX_WEIGHT, cost);
}
