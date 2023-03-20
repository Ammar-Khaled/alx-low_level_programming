#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - frees a dog struct
 * @d: pointer to the dog struct to be freed
 */
void free_dog(dog_t *d)
{
	free(d);
}
