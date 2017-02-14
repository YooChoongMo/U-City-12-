#include<stdio.h>
#include<stdlib.h>
#include"memo.h"

void stop() {
	while (head != NULL){
		if (head == tail) {
			printf("%d 메모리해제\n", head->num);
			free(head);
			head = NULL;
		}
		else {
			head = head->next;
			printf("%d 메모리해제\n", head->prev->num);
			free(head->prev);
			head->prev = NULL;
		}
	}
	tail = NULL;
}