#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"memo.h"

void edit() {
	struct Data *cur = NULL;
	int num;
	char buf[255];
	puts("수정할 글 번호:");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL) {
		puts("새 글 입력");
		scanf("%s", buf);
		strcpy(cur->buf, buf);
		strcat(cur->buf, "\n");
	}
	else {
		puts("not found");
	}
}

void del() {
	struct Data *cur = NULL;
	int num;
	puts("삭제할 글 번호:");
	scanf("%d", &num);
	cur = search(num);
	if (cur != NULL) {
		if (cur->prev == NULL) {
			if (cur->next == NULL) {
				free(cur);
				head = NULL;
				tail = NULL;
			}
			else {
				head = head->next;
				head->prev = NULL;
				free(cur);
			}
		}
		else if (cur->next == NULL) {
			tail = tail->prev;
			tail->next = NULL;
			free(cur);
		}
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
		}
	}
	else {
		puts("not found");
	}
}