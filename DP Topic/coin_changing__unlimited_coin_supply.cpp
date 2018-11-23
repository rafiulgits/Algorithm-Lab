/*
    stdio for standard I/O operation with format
    algorithm for fill function
*/
#include<stdio.h>
#include<algorithm>

/// defining a large value as infinite
#define INFINITE 10e7

using namespace std;

int main()
{
    /*
        define some coins that have unlimited supply and a target
        amount that should be make with this coins combinations.
        Sort the coins array before use, as for getting incremental value.
    */
    int coins[] = {3,1,2};
    const int target = 8;

    /// find out the length of this coins array
    size_t len = sizeof(coins)/sizeof(coins[0]);

    /// sort the array
    sort(coins, coins+len);

    /*
        For dynamic programing concept apply, a table must needed to manage
        the sub-problems solution. So, make a 1D array of target+1 size for
        manage 0 - target amount making solution and initially fill them with
        infinite. Amount 0 can make with 0 combination of any coins, so, make
        it zero after filling infinite.
    */
    unsigned int coin_table[target+1];

    fill(coin_table,coin_table+target+1, INFINITE);

    coin_table[0] = 0;


    /*
        loop through all coin in table and try to find minimum combination to
        make the current coin amount.
    */
    for(int money=0; money<=target; money++)
    {
        for(int i=0; i<len; i++)
        {
            /// next coin from supply is greater then current coin in table
            if(money < coins[i])
                break;
            /// set minimum value for current coin amount making in table
            if(coin_table[money] > coin_table[money-coins[i]]+1)
                coin_table[money] = coin_table[money-coins[i]]+1;
        }
    }

    /*
        print the targeted index value as the minimum combination for make this
        amount with those coins supply.
    */
    printf("Minimum coins for making %d: %d\n",target,coin_table[target]);

    return 0;
}
