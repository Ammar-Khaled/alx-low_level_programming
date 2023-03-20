#include "dog.h"
#include <string.h>
#include <stdlib.h>
/**
 * new_dog - creates a new dog.
 * @name: name for the new dog
 * @age: age for the new dog
 * @omner: omner for the new dog
 *
 * Return: pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	char *name_cp;
	char *owner_cp;
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (!d || !name || !owner)
		return (NULL);

	name_cp = malloc(strlen(name) + 1);
	if (!name_cp || !(name_cp = strcpy(name_cp, name)))
	{
		free(d);
		return (NULL);
	}

	owner_cp = malloc(strlen(owner) + 1);
	if (!owner_cp || !(owner_cp = strcpy(owner_cp, owner)))
	{
		free(d);
		free(name_cp);
		return (NULL);
	}

	d->name = name_cp;
	d->age = age;
	d->owner = owner;

	return (d);
}
