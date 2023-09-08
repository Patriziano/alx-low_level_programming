#include "hash_tables.h"

/**
 * hash_table_print - Print the contents of a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *node;
	char *blank;

	if (ht == NULL)
		return;

	printf("{");
	blank = "";

	for (idx = 0; idx < ht->size; idx++)
	{
		node = ht->array[idx];
		while (node != NULL)
		{
			printf("%s'%s': '%s'", blank,  node->key, node->value);
			blank = ", ";
			node = node->next;
		}
	}
	printf("}\n");
}
