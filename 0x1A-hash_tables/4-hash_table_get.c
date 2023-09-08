#include "hash_tables.h"


/**
 * hash_table_set - Add or update an element in the hash table.
 * @ht: The hash table.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}

	return (NULL);
}
