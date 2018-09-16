#include<stdio.h>
#include<stdlib.h>

/*
    For sample take 20 elements sized pair variables.
    Where they combined with a key and a value
*/
#define SIZE 20
/*
    A Pair structure for hold a value for any particular key.
    To create an object of this this structure use pointer.
    First define a pointer of this type:
    >>struct Item *i;
    Then allocated needed size memory for this pointer using type cast
    >>i = (struct Item) malloc(sizeof(struct Item));
    To access the parameters use '->'. i->key and i->value.

*/
struct Item
{
    int key;
    int value;
};

/*
    declare an array of Item structure of defined size
*/
struct Item* hashTable[SIZE];


/*
    prototypes of functions.
    1. generateHashIndex function will generate an unique index for any particular key
    2. getHashIndex will return the generated hash index for any particular key
    3. add function will create a new pair in hash table
    4. showHashTable will display the entire hash table with hash index and pair variables.
*/
int generateHashIndex(int key);
int getHashIndex(int key);
void add(int key, int value);
void showHashTable();

/*
    ::::::::  Main Function  :::::::::
*/
int main()
{
    add(1, 89);
    add(90, 12);
    add(12,7);
    add(8,45);
    add(4,34);

    showHashTable();

    printf("Hash index of key %d: %d\n",4,getHashIndex(4));
}

/*
    ::::::::: Function defining area :::::::::
*/
int generateHashIndex(int key)
{
    /*
        Here we use this hash function for our has table where
        linear probing will apply for any collision.
    */
    key *= key;
    key %= SIZE;

    return key;
}
int getHashIndex(int key)
{
    /*
        Linear search for access the hash table index for any particular key.
        For no result this function will return -1
    */
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(hashTable[i] == NULL)
            continue;
        if(hashTable[i]->key == key)
            return i;
    }
    return -1;
}
void showHashTable()
{
    /*
        Display the entire hash table in this format:
        hash index. (key : value)
    */
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(hashTable[i] == NULL)
        {
            printf("%d. (__ : __)\n",i);
        }
        else
        {
            printf("%d. (%d : %d)\n",i,hashTable[i]->key, hashTable[i]->value);
        }
    }
}
void add(int key, int value)
{
    /*
        To create a new pair first allocated needed memory.
        Then set the key and value and then generate a hash index
        and set in hash table with this hash index.
    */
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem->key = key;
    newItem->value = value;

    int hashIndex = generateHashIndex(key);
    while(hashTable[hashIndex] != NULL)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }

    hashTable[hashIndex] = newItem;
}
