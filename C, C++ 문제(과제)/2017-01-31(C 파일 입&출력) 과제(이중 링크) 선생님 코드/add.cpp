#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "memo.h"

void add(char *str) {	
	struct Data *bmp = (struct Data*)malloc(sizeof(struct Data));
	strcpy(bmp->buf, str);
	if (head == NULL) {
		bmp->num = 1;
		head = bmp;
		bmp->prev = NULL;
	}else{
		bmp->num = tail->num + 1;
		tail->next = bmp;
		bmp->prev = tail;
	}
	tail = bmp;
	tail->next = NULL;
}