#include<stdio.h>
#include<stdlib.h>

/*
    For sample take 20 elements sized pair variables.
    Where they combined with a key and a value
*/
#define SIZE 20

/*
    This time Item value will be a single Data instead of an integer.
    Data will carry two different element; id and phone.
*/
struct Data
{
    int id;
    int phone;

};
/*
    A Pair structure for hold a value for any particular key.
    To create an object of this this structure use pointer.
    First define a pointer of this type:
    >>struct Item *i;
    Then allocated needed size memory for this pointer using type cast
    >>i = (struct Item) malloc(sizeof(struct Item));
    To access the parameters use '->'. i->key, i->value->id, i->value->phone.

*/
struct Item
{
    int key;
    struct Data* value;
};

/*
    declare an array of Item structure of defined size
*/
struct Item* HashTable[SIZE];


/*
    prototypes of functions.
    1. generateHashIndex function will generate an unique index for any particular key
    2. getHashIndex will return the generated hash index for any particular key
    3. add function will create a new pair in hash table
    4. showHashTable will display the entire hash table with hash index and pair variables.
*/
int generateHashIndex(int key);
int getHashIndex(int key, int id, int phone);
void add(int key, int id, int phone);
void showHashTable();

/*
    ::::::::  Main Function  :::::::::
*/
int main()
{
    add(1, 89,1234);
    add(90, 12, 32424);
    add(12,7, 23424);
    add(8,45,12345);
    add(4,34,0000);

    showHashTable();

    printf("Query: ");
    int key, id, phone;
    scanf("%d %d %d",&key, &id, &phone);
    printf("Hash Index: %d\n",getHashIndex(key, id, phone));
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
int getHashIndex(int key, int id, int phone)
{
    /*
        Linear search for access the hash table index for any particular key.
        For no result this function will return -1
    */
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(HashTable[i] == NULL)
            continue;
        if(HashTable[i]->key == key)
        {
            if(HashTable[i]->value->id==id, HashTable[i]->value->phone==phone)
                return i;
        }
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
        if(HashTable[i] == NULL)
        {
            printf("%d. (__ : {_:_})\n",i);
        }
        else
        {
            printf("%d. (%d : {%d:%d})\n",i,HashTable[i]->key,HashTable[i]->value->id,
                   HashTable[i]->value->phone);
        }
    }
}
void add(int key, int id, int phone)
{
    /*
        To create a new pair first allocated needed memory.
        Then set the key and value and then generate a hash index
        and set in hash table with this hash index.
    */
    struct Data* newData = (struct Data*)malloc(sizeof(struct Data));
    newData->id = id;
    newData->phone = phone;

    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem->key = key;
    newItem->value = newData;

    int hashIndex = generateHashIndex(key);
    while(HashTable[hashIndex] != NULL)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }

    HashTable[hashIndex] = newItem;
}
