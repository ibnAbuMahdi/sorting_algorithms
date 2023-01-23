#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/* Data structures */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Functions prototype */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/*void sort_deck(deck_node_t **deck);*/

void quicksort(int *, int, int, int);

int partition(int *, int, int, int);

void swap(int *, int *);

void swap_head(listint_t **, listint_t **, listint_t **);

void swap_tail(listint_t **, listint_t **, listint_t **);

void mergesort(int *, int, int);

void merge(int *, int, int, int);

void print_sub_array(int *, int, int);

void rearrange(int *, int *, int, int);


#endif /* SORT_H */
