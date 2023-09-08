#include "hash_tables.h"

/**
 * create_node - Create a new hash node.
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = (value != NULL) ? strdup(value) : NULL;
	if (value != NULL && new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - Add or update an element in the hash table.
 * @ht: The hash table.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *temp, *new_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = (value != NULL) ? strdup(value) : NULL;
			if (value != NULL && temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

    /* Key doesn't exist, create a new node and add it to the bucket*/
	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
