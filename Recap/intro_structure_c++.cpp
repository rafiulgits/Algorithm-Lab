#include<stdio.h>
#include<algorithm>

using namespace std;

/*
    Football structure will carry two integer variable.
    One default constructor defined with two arguments.
    operation boolean function will take another Football
    structure object and compare with the current.This method
    will use for order this structure objects with any used parameter.
*/
struct Football
{
    int shot;
    int goal;
    Football(int shot, int goal)
    {
        /*
            'this' keyword is use for point this current structure.
            initial the structure object with passed parameters.
        */
        this->shot = shot;
        this->goal = goal;
    }

    bool operator<(const Football obj)
    {
        /*
            this logic says that current goal will always be greater then
            other belows; more precisely this logic for descending order
            by using goal quantity.
        */
        return obj.goal < goal;
    }

};

/*
    Cricket structure object will carry two integer variable.
    A default constructor use for initial an object copy of
    Cricket structure.
    Cricket structure does not have any comparison function.
*/
struct Cricket
{
    int ball;
    int run;

    Cricket(int ball, int run)
    {
        this->ball = ball;
        this->run = run;
    }
};

/*
    this boolean function is defined for compare between two
    cricket structure objects. This function will be used for
    sorting an array of cricket structure objects.
*/
bool compare(Cricket player1, Cricket player2)
{
    return player2.ball > player1.ball;
}

int main()
{
    /*
        create an array of football player then find out the array
        size and sort it. after these print the sorted array
    */
    Football footballPlayers[] = {{10,0},{21,4},{9,5},{16,3}};
    int fbLen = sizeof(footballPlayers)/sizeof(footballPlayers[0]); // length of this array
    sort(footballPlayers, footballPlayers+fbLen); // sort the array
    puts("Football players top performance by goal");
    /*
        *** iterator for loop C++ 11 or letter supported
    */
    for(Football player : footballPlayers)
        printf("\tShot: %2d ::: Goal: %d\n",player.shot,player.goal);

    puts("\n ~~~~~~~~~~~~~~~~~~~~~~~~");

    /*
        create an array of cricket players, find the length and sort the
        array with defined boolean function which will use for comparison
        between this array object with a defined manner.
        then print out the sorted array.
    */
    Cricket cricketPlayers[] = {{120,45},{78,45},{245,123},{180,40}};
    int cLen = sizeof(cricketPlayers)/sizeof(cricketPlayers[0]);
    sort(cricketPlayers,cricketPlayers+cLen, compare);// sort the array with compare boolean function
    puts("Cricket player performance by lowest ball played");
    for(Cricket player : cricketPlayers)
        printf("\tBall: %3d ::: Run: %3d\n",player.ball,player.run);

    return 0;
}
