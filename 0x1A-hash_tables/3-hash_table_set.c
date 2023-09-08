#include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table
 * @ht: the hash table to add the key/value to
 *  @key: The key of the hash table
 *  @value: Value associated with the key
 *
 *  Returns: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *dup_value;
	hash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	dup_value = (value != NULL) ? strdup(value): NULL;
	if (dup_value == NULL)
		return (0);

	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = dup_value;
			return (1);
		}
		temp = temp->next;
	}

    /*if Key doesn't exist in the bucket, create a new node*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(dup_value);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(dup_value);
		free(new_node);
		return (0);
	}
	new_node->value = dup_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
