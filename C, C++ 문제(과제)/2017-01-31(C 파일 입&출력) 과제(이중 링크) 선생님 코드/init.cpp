#include<stdio.h>
#include"memo.h"

void init() {
	char buf[255];
	FILE *fp = fopen(path, "r");
	while (fgets(buf, 255, fp) != NULL) {
		add(buf);
	}
	fclose(fp);
}

void fileWrite() {
	FILE *fp = fopen(path, "w");
	struct Data *cur = head;
	while (cur != NULL) {
		fputs(cur->buf, fp);
		cur = cur->next;
	}
	fclose(fp);
}