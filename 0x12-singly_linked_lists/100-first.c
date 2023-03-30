#include <stdio.h>

void print_message_before_main(void) __attribute__((constructor));

/**
 * print_message_before_main - constructor function that is excuted before main
 */
void print_message_before_main(void)
{
	printf("You're beat! and yet, you must allow,\n
		I bore my house upon my back!\n");
}
