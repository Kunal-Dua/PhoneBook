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
	getline(cin, temp->name);
	cout << "Enter contact phonenumber";
	cin >> temp->phonenumber;
	cout << "Enter contact email id";
	getline(cin, temp->emailid);
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
void display()
{
	struct node* d;
	d = START;
	cout << "Phone book contents";
	cout << "Name";
	cout << "Phone Number";
	cout << "Email ID";
	while (d!=NULL)
	{
		cout << d->name;
		cout << d->phonenumber;
		cout << d->emailid;
		d = d->link;
	}
}
int menu()
{
	int ans;
	cout << "Enter 1:-To add contents to phonebook";
	cout << "Enter 2:-To delete contents of phonebook";
	cout << "Enter 3:- To display contents of phonebook";
	cout << "Enter 4:- To Exit";
	cin >> ans;
	return ans;
}