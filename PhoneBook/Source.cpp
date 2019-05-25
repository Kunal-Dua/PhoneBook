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
	string name;
	string emailid;
	//char name[15];
	//char emailid[20];
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
	getline(cin, t->name);
	cout << "Enter contact phonenumber";
	cin >> t->phonenumber;
	cout << "Enter contact email id";
	getline(cin, t->emailid);
	if (START==NULL)
	{
		START = temp;
	}
	else
	{
		t = START;
		while (t!=NULL)
		{
			t = t->link;
		}
		temp = t;
	}
}