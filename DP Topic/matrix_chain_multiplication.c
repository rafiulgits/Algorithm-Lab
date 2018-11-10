#include <stdio.h>

/**
    @author Rafiul

    @param data store the sub problem solution
    @param INF large value indicate for infinite
*/

const static int INF = 10e7;
int data[20][20];


/// function prototypes
int min_cost(int arr[], int len);

/// driver function
int main()
{
    int arr[] = {2,3,6,4,5};

    printf("%d\n", min_cost(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}

/**
    function will return the minimum calculation needed to solution
    a particular matrix chain multiplication process.

    @param arr matrices orders array
    @param len matrices orders array length
    @return minimum cost for this particular matrices chain multiplication
*/
int min_cost(int arr[], int len)
{
    int i, j, k, l; // for indexing

    /// number for matrix will be multiplied
    for(l=2; l<len; l++)
    {
        /// first matrix index
        for(i=0; i<len-l; i++)
        {
            /// final matrix index
            j = i+l;

            /// set final matrix solution value INFINITE
            data[i][j] = INF;

            /// intermediate matrix index
            for(k=i+1; k<j; k++)
            {
                /// possible new solution
                int temp = data[i][k]+data[k][j]+arr[i]*arr[j]*arr[k];

                /// check for updating
                if(data[i][j] > temp)
                    data[i][j] = temp;
            }
        }
    }

    /// return the solution
    return data[0][len-1];
}
