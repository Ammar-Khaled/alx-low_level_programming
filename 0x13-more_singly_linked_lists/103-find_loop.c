#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list by Floyd’s Cycle-Finding Algorithm
 * @head: pointer to the list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *S, *F;

	S = F = head;

	while (S && F && F->next)
	{
		S = S->next;
		F = F->next->next;
		if (S == F)	/* then there is a loop */
		{
			S = head;
			while (S != F)
			{
				S = S->next;
				F = F->next;
			}
			/* now when S and F meet again, they are at the start of the loop */
			return (S);
		}
	}

	return (NULL);
}
