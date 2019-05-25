#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string>
using namespace std;

void insertnode();
void deletenode();
void searchnode();
void display();
int menu();

int serialnumber=0;
struct node
{
	int sno=0;
	string name, emailid, phonenumber;
	
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
void insertnode()//to insert node at end of database
{
	struct node* temp,*t;
	char hou, sta, cit, nation;
	temp = createnode();
	serialnumber++;
	temp->sno = serialnumber;
	cout << "Enter information about the contact\n";
	fflush(stdin);
	cout << "Enter contact name ";
	cin.ignore();
	getline(cin, temp->name);
	fflush(stdin);
	cout << "Enter contact phone number ";
	getline(cin, temp->phonenumber);
	fflush(stdin);
	cout << "Enter contact email id ";
	getline(cin, temp->emailid);
	fflush(stdin);
	if (START==NULL)
	{
		START = temp;
	}
	else
	{
		t = START;
		while (t->link != NULL)
		{
			t = t->link;
		}
		t->link = temp;
	}
}
void deletenode()//to delete any node 
{
	if (START==NULL)
	{
		cout << "No contacts in phone book" << endl;
		return;
	}
	char ph[9];
	cout << "Enter phone number to be deleted ";
	cin >> ph;
	struct node* t,* del;
	struct node* temp, * prev;
	if (START->phonenumber==ph)
	{
		cout << "Contact with phone number " << ph << " deleted" << endl;
		del = START;
		START == NULL;
		delete del;
		return;
	}
	else
	{
		temp = START;
		prev = temp;
		while (temp != NULL && temp->phonenumber != ph)//looking for previous node of node to be deleted to deleted
		{
			prev = temp;
			temp = temp->link;
		}
		if (temp == NULL)//phone number not in database
		{
			cout << "No contact with phone number " << ph << " is present in the database" << endl;
			return;
		}
		prev->link = temp->link;
		delete temp;//freeing memory
		delete prev;//freeing memory
		cout << "Contact deleted successfully" << endl;
	}
}
void searchnode()//to search any node
{
	if (START == NULL)
	{
		cout << "No numbers present in the phone book" << endl;
		return;
	}
	char ph[9];
	cout << "Enter phone number to be found ";
	cin >> ph;
	struct node* t;
	t = START;
	if (START->phonenumber==ph)
	{
		cout << "Phone book contents" << endl;
		cout << "Sno.\t";
		cout << "Name\t";
		cout << "Number\t";
		cout << "Email ID\t";
		cout << endl;
		cout << t->sno << "\t";
		cout << t->name << "\t";
		cout << t->phonenumber << "\t";
		cout << t->emailid << "\t";
	}
	else
	{
		while (t->link != NULL)
		{
			if (ph == t->phonenumber)
			{
				cout << "Phone book contents" << endl;
				cout << "Sno.\t";
				cout << "Name\t";
				cout << "Number\t";
				cout << "Email ID\t";
				cout << endl;
				cout << t->sno << "\t";
				cout << t->name << "\t";
				cout << t->phonenumber << "\t";
				cout << t->emailid << "\t";
			}
			t = t->link;
		}
		cout << "Contact deleted " << ph << endl;
	}
}
void display()//to display the linked list
{
	struct node* d;
	d = START;
	if (START==NULL)
	{
		cout << "No items in phone book\n";
		return;
	}
	cout << "Phone book contents"<<endl;
	cout << "Sno.\t\t";
	cout << "Name\t\t";
	cout << "Number\t\t";
	cout << "Email ID\t\t";
	while (d!=NULL)
	{
		cout << endl;
		cout << d->sno << "\t\t";
		cout << d->name<<"\t\t";
		cout << d->phonenumber<<"\t\t";
		cout << d->emailid<<"\t\t";
		d = d->link;
	}
}
int menu()
{
	int ans;
	cout << "Enter 1:-To add contents to phonebook"<<endl;
	cout << "Enter 2:-To delete contents of phonebook"<<endl;
	cout << "Enter 3:- To display contents of phonebook"<<endl;
	cout << "Enter 4:- To search contents of phonebook" << endl;
	cout << "Enter 5:- To Exit"<<endl;
	cin >> ans;
	return ans;
}
int main()
{
	cout << "Welcome to Phone Book"<<endl;
	while (1)
	{
		switch (menu())
		{
		case 1:
			insertnode();
			break;
		case 2:
			deletenode();
			break;
		case 3:
			display();
			break;
		case 4:
			searchnode();
			break;
		case 5:
			cout << "Exiting"<<endl;
			int getch();
			exit(1);
		default:
			cout << "Wrong input" << endl;
			exit(1);
		}
		_getch();
		system("cls");
	}
	_getch();
	return 0;
}