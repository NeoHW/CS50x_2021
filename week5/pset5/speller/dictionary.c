// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5000;

// Hash table
node *table[N];

// size of dictionary loaded
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // create a temp pointer 
    node *cursor = NULL;
    
    // hash function 
    int index = hash(word);
    
    for (cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++))) // use toupper to make hash case-insensitive
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c // hash << 5 means times 2^5
    }
    
    // to get a hash number lower than N
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *file_pointer = fopen(dictionary, "r");
    
    // check if return value is NULL
    if (file_pointer == NULL)
    {
        return false;   
    }
    
    // create a temp buffer to store scanned strings from fscanf
    char buffer[LENGTH + 1];
    
    // read strings from file
    while (fscanf(file_pointer, "%s", buffer) != EOF)
    {
        // create a new node
        node *n = malloc(sizeof(node));
        //make sure malloc succeeded in getting memory
        if (n == NULL)
        {
            return false;
        }
        // copy string from buffer to n
        strcpy(n->word, buffer);
        n->next = NULL;
        
        // hash the word
        int index = hash(buffer); // can use n->word too?
        
        // insert node into hash table
        // if first word in table[index]
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        // if not first word in table[index]
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        
        // keep track of number of words loaded
        word_count++;
    }
    //close file
    //dont have to use free(n) as fclose clean up any resources created by fopen.
    fclose(file_pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // return word_count that was done in load function
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
    }
    // return true must put outside of for loop if not it will only
    // unload words starting with "a" , and return true. 
    return true;
}
