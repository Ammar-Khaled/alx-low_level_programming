#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: the size of the array.
 *
 * Return: a pointer to the newly created hash table.
 * If something went wrong, function should return NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_node_t **array;
	unsigned long int i;

	table = malloc(sizeof(shash_table_t));
	if (!table)
		return (NULL);

	array = malloc(size * sizeof(shash_node_t *));
	if (!array)
	{
		free(table->shead);
		free(table->stail);
		free(table->array);
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = NULL;
	}

	table->size = size;
	table->array = array;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * add_node_in_DLL - add the node in the right place
 * in the sorted list
 * @ht: the hash table
 * @key: the key
 * @new_node: the new node
 */
void add_node_in_DLL(shash_table_t *ht, const char *key, shash_node_t *new_node)
{
	shash_node_t *ptr, *pre_ptr;

	pre_ptr = ptr = ht->shead;
	while (ptr != NULL)
	{
		if (strcmp(key, ptr->key) < 0)
		{
			new_node->sprev = ptr->sprev;

			if (ptr == ht->shead)
			{
				/*add the new node at the begining of the sorted list*/
				ht->shead = new_node;
			}
			else /*add the new node at any position within the sorted list*/
			{
				ptr->sprev->snext = new_node;
			}

			ptr->sprev = new_node;
			new_node->snext = ptr;

			return;
		}

		pre_ptr = ptr;
		ptr = ptr->snext;
	}

	/* here, ptr is NULL which means that either
	* we should add the new node at the end of the sorted list
	* or it will be the only node in its list
	*/
	new_node->sprev = pre_ptr;
	new_node->snext = NULL;

	if (ht->shead)	/*case 1*/
	{
		pre_ptr->snext = new_node;
	}
	else	/*case 2*/
	{
		ht->shead = new_node;
	}

	ht->stail = new_node;
}

/**
 * shash_table_set - adds an element to the sorted hash table.
 * @ht: the hash table you want to add or update the key/value to.
 * @key: the key, that can not be an empty string
 * @value: the value associated with the key. it is duplicated and can be empty
 *
 * In case of collision, function adds new node at the beginning of the list
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long idx;
	shash_node_t *new_node, *ptr;

	if (!ht)
		return (0);

	if (*key == '\0' || !key)
		return (0);

	idx = key_index((unsigned char *)key, ht->size);
	ptr = ht->array[idx];

	/*if `key` is already exists, just update its corresponding value.*/
	while (ptr)
	{
		if (strcmp(ptr->key, key) == 0)
		{
			free(ptr->value);
			ptr->value = strdup(value);
			return (1);
		}
		ptr = ptr->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	add_node_in_DLL(ht, key, new_node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 *
 * Return: value associated with element, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long idx;
	shash_node_t *ptr;

	if (!ht)
		return (NULL);

	if (*key == '\0' || !key)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	ptr = ht->array[idx];

	while (ptr)
	{
		if (strcmp(ptr->key, key) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a hash table using the sorted linked list.
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *ptr;
	char *separator;

	if (!ht)
		return;

	printf("{");
	separator = "";
	for (ptr = ht->shead; ptr; ptr = ptr->snext)
	{
		printf("%s'%s': '%s', ", separator, ptr->key, ptr->value);
		separator = ", ";
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse order
 * using the sorted linked list.
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *ptr;
	char *separator;

	if (!ht)
		return;

	printf("{");
	separator = "";
	for (ptr = ht->stail; ptr; ptr = ptr->sprev)
	{
		printf("%s'%s': '%s', ", separator, ptr->key, ptr->value);
		separator = ", ";
	}

	printf("}\n");
}

/**
 * shash_table_delete- deletes a sorted hash table.
 * @ht: is the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long i;
	shash_node_t *cur, *prev;

	if (!ht)
		return;

	/*free lists*/
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			cur = ht->array[i];
			while ((prev = cur) != NULL)
			{
				cur = cur->next;
				free(prev->key);
				free(prev->value);
				free(prev);
			}
		}
	}

	/*free the table*/
	free(ht->array);
	free(ht);
}
