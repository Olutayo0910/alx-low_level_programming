#include "hash_tables.h"

/*
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 *
 * This function prints the contents of a hash table. It prints each key-value
 * pair enclosed in curly braces and separated by commas. If the hash table is
 * empty or NULL, it prints an empty pair of curly braces.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char com_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (com_flag == 1)
				printf(", ");

			node = ht->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			com_flag = 1;
		}
	}
	printf("}\n");
}
