#include<vector>
#include<stdio.h>

#define SIZE 20

using namespace std;

/*
    Using Class instead of structure as because of this is C++ and
    class is more easy to use then structure pointers.All parameters
    of this class is under public access protocol.
*/
class Item
{
public:
    int key;
    int value;
};

/*
    Vector array of defined size will allow us to make this chaining
    functionality more easily.
*/
vector<Item> HashTable[SIZE];

/*
    function prototypes
*/
void add(int key, int value);
void showHashTable();
void hashQuery(int key, int value);
int generateHashIndex(int key);

/*
    ::::::::::: main function :::::::::::::::
*/
int main()
{
    add(16,80);
    add(4,1);
    add(36,45);

    showHashTable();

    int key, value;
    scanf("%d %d",&key, &value);
    hashQuery(key, value);

    return 0;
}
/*
    :::::::::: function defining area ::::::::::::::
*/
void add(int key, int value)
{
    Item newItem;
    newItem.key = key;
    newItem.value = value;

    int hashIndex = generateHashIndex(key);
    HashTable[hashIndex].push_back(newItem);
}
void showHashTable()
{
    for(int i=0; i<SIZE; i++)
    {
        printf("Hash Index: %d\n",i);
        for(int j=0; j<HashTable[i].size(); j++)
        {
            printf("\t(%d : %d)\n",HashTable[i][j].key,HashTable[i][j].value);
        }
        puts("");
    }
}
int generateHashIndex(int key)
{
    key *= key;
    key %= SIZE;

    return key;
}
void hashQuery(int key, int value)
{
    int hashIndex = generateHashIndex(key);
    if(HashTable[hashIndex].empty())
    {
        puts("Key is not available");
        return;
    }
    else
    {
        for(int i=0; i<HashTable[hashIndex].size(); i++)
        {
            if(HashTable[hashIndex][i].key == key && HashTable[hashIndex][i].value == value)
            {
                printf("Hash Index: %d & Chain Index: %d\n",hashIndex, i);
                return;
            }
        }
    }
    puts("Pair is not available");
}
