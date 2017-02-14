#pragma once
struct Data {
	int num;
	char buf[255];
	struct Data *prev;
	struct Data *next;
};
extern char *path;
extern struct Data *head;
extern struct Data *tail;
void init();
void fileWrite();
void add(char *str);
struct Data* search(int num);
void edit();
void del();
void stop();
void printA();
void printB();