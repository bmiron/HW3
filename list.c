#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* hold = head;
	int sorted = 0;

	//Otherwise, iterate through the list and attempt to insert the new element
	while(hold->next != NULL && !sorted){
		if(hold->next->index > new_element->index && hold->index < new_element->index){
			new_element->next = hold->next;
			hold->next = new_element;
			sorted = 1;
		}

		hold = hold->next;
	}

	//If you were not able to insert the element, it goes at the end or the beginning
	if(hold->next == NULL && !sorted){
		if(hold->index < new_element->index){
			hold->next = new_element;
			new_element->next = NULL;
			sorted = 1;
		}

		else if(head->index > new_element->index){
			new_element->next = head;
			head = new_element;
			sorted = 1;
		}
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* holdnext = head->next;
	list_t* hold = head;
	list_t* hold_prev = NULL;

	if(head->next == NULL){
		return head;
	}

	while(hold != NULL){
		holdnext = hold->next;
		hold->next = hold_prev;

		hold_prev = hold;
		hold = holdnext;
	}

	head = hold_prev;

	return head;
}

