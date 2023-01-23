#include "sort.h"

/**
 * cocktail_sort_list - implement the cocktail sort algorithm on doubly\
 * linked list @list
 *
 * @list: address of the pointer to the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail = NULL, *head = *list;

	if (list && *list)
		while (1)
		{
			int swapped = 0;

			while (head->next)
			{
				int moved = 0;

				if (head->n > head->next->n)
				{
					swap_head(list, &head, &tail);
					moved = swapped = 1;
					print_list(*list);
				}
				if (!moved)
					head = head->next;
			}
			if (!swapped)
				break;
			swapped = 0;
			while (tail->prev)
			{
				int moved = 0;

				if (tail->n < tail->prev->n)
				{
					swap_tail(list, &head, &tail);
					moved = swapped = 1;
					print_list(*list);
				}
				if (!moved)
					tail = tail->prev;
			}
			if (!swapped)
				break;
		}
}

/**
 * swap_head - swap tail
 * @list: the list
 * @head: the head node
 * @tail: the tail node
 */

void swap_head(listint_t **list, listint_t **head, listint_t **tail)
{
	listint_t *temp1 = (*head)->next;
	listint_t *temp = *head;
	listint_t *temp2 = (*head)->next->next;

	if ((*head)->prev)
		(*head)->prev->next = temp1;
	temp1->prev = (*head)->prev;
	temp1->next = temp;
	temp->prev = temp1;
	if (temp2)
		temp2->prev = temp;
	temp->next = temp2;

	*head = temp;

	*tail = temp1;
	if (temp1->prev == NULL)
		*list = temp1;
}

/**
 * swap_tail - swap tail
 * @list: the list
 * @head: the head node
 * @tail: the tail node
 */

void swap_tail(listint_t **list, listint_t **head, listint_t **tail)
{
	listint_t *temp1 = (*tail)->prev;
	listint_t *temp = *tail;
	listint_t *temp2 = (*tail)->prev->prev;

	if ((*tail)->next)
		(*tail)->next->prev = temp1;
	temp1->next = (*tail)->next;
	temp1->prev = temp;
	temp->next = temp1;
	if (temp2)
		temp2->next = temp;
	temp->prev = temp2;

	*tail = temp;
	*head = temp1;
	if (temp->prev == NULL)
		*list = temp;
}
