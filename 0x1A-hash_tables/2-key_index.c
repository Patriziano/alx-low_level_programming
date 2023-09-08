#include "hash_tables.h"

/**
 *key_index - function that returns the index of a key
 *@key: The key of the function
 *@size: size of the hash table
  *
  * Returns: Index in which the key should be stored
  */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = hash_djb2(key);
	unsigned long int index = hash % size;
	return (index);
}
