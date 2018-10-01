#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// define a constant item array
const int arr[] = {10,2,1,3,5,4,6,9,8};

// function prototype
void lis();

// driver function
int main()
{
    // call the LIS function
    lis();

    return 0;
}

// function defining area
void lis()
{
    // find out the array size
    int len = sizeof(arr)/sizeof(arr[0]);

    // to store current items LIS number
    int ans[len+1];

    // initially every items LIS = 1
    fill(ans, ans+len+1, 1);

    // define a 1D vector to store all items increasing sequences
    vector<int>seq[len];

    // first items LIS = 1;
    seq[0].push_back(1);

    // iterate from second items of the array
    for(int i=1; i<len; i++)
    {
        // check current's previous
        for(int j=0; j<i; j++)
        {
            // if current is smaller or equal to any of previous
            if(arr[j] >= arr[i])
                continue;
            // is current item's LIS is not less then previous value
            if(ans[j]+1 <= ans[i])
                continue;
            // set the current item's LIS value
            ans[i] = ans[j]+1;
            // push into corresponding array
            seq[i].push_back(arr[j]);
        }
        // push the current as the last item
        seq[i].push_back(arr[i]);
    }

    /// presentation
    cout << "Array: ";
    for(int i=0; i<len; i++)
        cout << arr[i] <<" ";
    cout << endl << endl<<"Solution: "<<endl;
    for(int i=0; i<len; i++)
    {
        cout << "Item "<<arr[i] <<" ("<<seq[i].size()<<"): ";
        for(int j=0; j<seq[i].size(); j++)
            cout << seq[i][j]<<" ";
        cout << endl;
    }
}
