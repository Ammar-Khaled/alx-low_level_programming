#include <stdio.h>
#include "dog.h"

/**
 * print_dog -  prints a struct dog
 * @d: pointer to the struct dog to be printed
 */
void print_dog(struct dog *d)
{
	if (!d)
		return;

	if (d->name)
		printf("Name: %s\n", d->name);
	else
		printf("Name: (nil)\n");

	if (d->age)
		printf("Name: %f\n", d->age);
	else
		printf("Name: (nil)\n");

	if (d->owner)
		printf("Name: %s\n", d->owner);
	else
		printf("Name: (nil)\n");
}
