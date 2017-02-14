#include<stdio.h>
#include"memo.h"

struct Data* search(int num) {
	struct Data *cur = head;
	while (cur != NULL) {
		if (num == cur->num) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}