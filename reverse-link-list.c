#include <stdio.h>
#include <stdlib.h>

typedef struct list {

	int value;
	struct list *next;

} list;

void print_list(list *head){
	for (; head != NULL; head = head->next) {
		printf("[%d]->", head->value);
	}
	printf("NULL\n");
}

list *reverse_linked_list(list *head) {
	if (!head) return head;
	list *next = head->next;
	list *reversed = head;
	reversed->next = NULL;
	while (next != NULL) {
		list *tmp = next;
		next = next->next;
		tmp->next = reversed;
		reversed = tmp;
	}
	//print_list(reversed);
	return reversed;
}

int main(void){
	
	list l3 = {3, NULL};
	list l2 = {2, &l3};
	list l1 = {1, &l2};
	list l0 = {0, &l1};

	l0.value = 0;
	l1.value = 1;
	l2.value = 2;
	l3.value = 3;
	l0.next = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = NULL;

	print_list(&l0);
	list *list_new = reverse_linked_list(&l0);
	print_list(list_new);
}
