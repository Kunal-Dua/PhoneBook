#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string>
using namespace std;

void insertnode();
void deletenode();
void display();
int menu();

struct node
{
	int phonenumber;
	char name[15];
	char emailid[20];
	struct node* link;
};
struct node* START = NULL;
struct node * createnode()
{
	struct node* t;
	t = new struct node;
	t->link = NULL;
	return t;
}
void insertnode()
{
	struct node* temp,*t;
	temp = createnode();
	cout << "Enter contact name";
	cin >> temp->name;
}