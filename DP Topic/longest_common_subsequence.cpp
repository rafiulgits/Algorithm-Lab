#include<string>
#include<iostream>

using namespace std;

/*
    Define two string:
    For this program string1 >= string2
    this condition need for dynamic programming table manage.
    string are constant for a particular program
*/
const string str1 = "ABCD";
const string str2 = "BC";

// constant length of two strings
const int len1 = str1.length();
const int len2 = str2.length();

// function prototypes
void lcs();

// driver function
int main()
{
    // call the function
    lcs();

    return 0;
}
void lcs()
{
    /*
        2D array for manage dynamic programming table for memorize.
        For this problem initial solution is 0. So make all index
        initial value 0.
        >> int array[] = {};
        this syntax make this happen
        alternative:
            >> memset(array,0,sizeof(array));
            >> fill(array, array+sizeof(array),0);
    */
    int table[len1+1][len2+1] = {};

    // iterate longer length string :: string1 for this program
    for(int i=1; i<=len1; i++)
    {
        // iterate second string
        for(int j=1; j<=len2; j++)
        {
            /*
                whether current index of string1 and string2 item match each
                other then set table value for this two index
                previous diagonal index + 1;
                otherwise set the maximum of corresponding row neighbor item
                and corresponding column item.
            */
            if(str1.at(i-1) == str2.at(j-1))
                table[i][j] = table[i-1][j-1]+1;
            else
                table[i][j] = max(table[i-1][j],table[i][j-1]);
        }
    }


    /// iterate the subsequence string
    // define a string with length
    string seq(table[len1][len2], '$');

    // iterate the table
    for(int i=len1,j=len2,index=table[len1][len2]; i!=0 && j!=0; )
    {
        if(str1.at(i-1) == str2.at(j-1))
        {
            // set the char in corresponding index
            seq.at(index-1) = str1.at(i-1);
            i--;
            j--;
            index--;

        }
        // check current value comes from which neighbor
        else if(table[i][j-1] < table[i-1][j])
            i--;
        else
            j--;
    }
    cout <<"LCS: "<<seq<<"("<<seq.length()<<")"<<endl;

}
