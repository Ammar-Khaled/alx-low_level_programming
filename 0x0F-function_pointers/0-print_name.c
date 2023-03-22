
/**
 * print_name - prints a name.
 * @name: the name to be printed
 * @f: pointer to the function that should print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
