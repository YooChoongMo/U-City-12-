#include<stdio.h>
#include<stdlib.h>
#include"memo.h"

void stop() {
	while (head != NULL){
		if (head == tail) {
			printf("%d �޸�����\n", head->num);
			free(head);
			head = NULL;
		}
		else {
			head = head->next;
			printf("%d �޸�����\n", head->prev->num);
			free(head->prev);
			head->prev = NULL;
		}
	}
	tail = NULL;
}