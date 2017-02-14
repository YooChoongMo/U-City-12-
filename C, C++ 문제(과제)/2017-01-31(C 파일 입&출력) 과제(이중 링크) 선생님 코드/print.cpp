#include<stdio.h>
#include"memo.h"

void printA() {
	struct Data *cur = NULL;
	cur = head;
	while (cur != NULL) {
		printf("%d\t%s\n", cur->num, cur->buf);
		cur = cur->next;
	}
}

void printB() {
	struct Data *cur = NULL;
	cur = tail;
	while (cur != NULL) {
		printf("%d\t%s\n", cur->num, cur->buf);
		cur = cur->prev;
	}
}