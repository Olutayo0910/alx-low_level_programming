#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - Creates a new dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the newly created dog (dog_t).
 *         NULL if memory allocation fails or name/owner is NULL.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_len = 0, owner_len = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[name_len])
		name_len++;

	while (owner[owner_len])
		owner_len++;

	new_dog = malloc(sizeof(*new_dog));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name = malloc((name_len + 1) * sizeof(char));
	new_dog->owner = malloc((owner_len + 1) * sizeof(char));

	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog->owner);
		free(new_dog);
		return (NULL);
	}

	for (i = 0; i < name_len; i++)
		new_dog->name[i] = name[i];
	new_dog->name[i] = '\0';

	new_dog->age = age;

	for (i = 0; i < owner_len; i++)
		new_dog->owner[i] = owner[i];
	new_dog->owner[i] = '\0';

	return (new_dog);
}
