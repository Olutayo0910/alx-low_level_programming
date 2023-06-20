#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Return: Pointer to the newly created dog (dog_t)
 *         NULL if memory allocation fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	tabdog_t *new_dog;
	tabchar *new_name, *new_owner;
	tabint name_len, owner_len;

	/* Calculate the lengths of name and owner strings */
	name_len = strlen(name) + 1;
	owner_len = strlen(owner) + 1;

	/* Allocate memory for the new dog structure */
	new_dog = malloc(sizeof(tabdog_t));
	if (new_dog == NULL)
		return (NULL);

	/* Allocate memory for the name and owner strings */
	new_name = malloc(name_len * sizeof(tabchar));
	new_owner = malloc(owner_len * sizeof(tabchar));
	if (new_name == NULL || new_owner == NULL)
	{
		free(new_dog);
		free(new_name);
		free(new_owner);
		return (NULL);
	}

	/* Copy the name and owner strings */
	strncpy(new_name, name, name_len);
	strncpy(new_owner, owner, owner_len);

	/* Assign the copied strings to the new dog structure */
	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;

	return (new_dog);
}
