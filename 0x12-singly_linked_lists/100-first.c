#include <stdio.h>

void print_message_before_main() __attribute__((constructor));

void print_message_before_main()
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
