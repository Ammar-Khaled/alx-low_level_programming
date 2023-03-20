#include "dog.h"
#include <string.h>
#include <stdlib.h>
/**
 * new_dog - creates a new dog.
 * @name: name for the new dog
 * @age: age for the new dog
 * @owner: omner for the new dog
 *
 * Return: pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (!d || !name || !owner)
	{
		free(d);
		return (NULL);
	}

	d->name = malloc(strlen(name) + 1);
	d->name = strcpy(d->name, name);
	if (!d->name)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(strlen(owner) + 1);
	d->owner = strcpy(d->owner, owner);
	if (!d->owner)
	{
		free(d);
		free(d->name);
		return (NULL);
	}

	d->age = age;

	return (d);
}
