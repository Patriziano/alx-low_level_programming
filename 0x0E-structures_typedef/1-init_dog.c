#include "dog.h"
#include <stddef.h>

/**
*init_dog - initializes a variable of type struct dog
*@d: pointer to the dog
*@name: name of the dog
*@age: age of the dog
*@owner: owner of the dog
*
*init_dog - this function initializes the variable of type struct dog,
*accessing each element of the variable
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}

}
