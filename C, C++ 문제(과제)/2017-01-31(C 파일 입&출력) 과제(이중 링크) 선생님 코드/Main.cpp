#include<stdio.h>
#include "memo.h"
struct Data *head = NULL, *tail=NULL;
char *path = "files/a.txt";
void main() {
	init();
	puts("추가전");
	printA();
	add("gg\n");
	add("hhh\n");
	add("iii\n");
	puts("추가후");
	printA();
	edit();
	printA();
	del();
	del();
	del();
	del();
	fileWrite();
	stop();
}