#ifndef SORT_H
#define SORT_H

/*--LIBRARIES--*/
#include <stdlib.h>
#include <stdio.h>

/*--STRUCT--*/
/**
 * struct listint_s - linked list node
 *
 * @n: integer value stored in the node
 * @prev: pointer to the previous list element
 * @next: pointer to the next list element
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*--FUNCTION PROTOTYPES--*/
/*--function to bubble sort integer array--*/
void bubble_sort(int *array, size_t size);

/*--function for printing the integer array--*/
void print_array(const int *array, size_t size);

/*--function for printing the list of integers--*/
void print_list(const listint_t *list);

/*--function to sort an integer doubly linked list with insertion sort--*/
void insertion_sort_list(listint_t **list);

/*--selection sort function for sorting integer array--*/
void selection_sort(int *array, size_t size);

#endif
