#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int count = 0;
struct node{
	struct node* prev;
	int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node* next;
}*h,*temp,*temp1,*temp2,*temp4;
void create()
{
    int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = new node;
    temp->prev = NULL;
    temp->next = NULL;
    cout << "Enter ssn : ";
    cin >> ssn;
    cout << "Enter name :";
    cin >> name;
    cout << "Enter department :";
    cin >> dept;
    cout << "Enter designation :";
    cin >> desg;
    cout << "Enter salary : ";
    cin >> sal;
    temp->ssn = ssn;
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg,desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
void insertbeg()
{
    if (h == NULL) {
        create();
        h = temp;
        temp1 = h;
    }

    else {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void insertend()
{
    if (h == NULL) {
        create();
        h = temp;
        temp1 = h;
    }
  
    else {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
void displaybeg()
{
	temp2 = h;
	if (temp2 == NULL)
	{
		cout << "List is empty";
		return;
	}
	while(temp2 != NULL)
	{
		cout << temp2->ssn<<"\n";
		cout << temp2->name<<"\n";
		cout << temp2->dept<<"\n";
		cout << temp2->desg<<"\n";
		cout << temp2->sal<<"\n";
		cout << temp2->phno<<"\n";
		temp2 = temp2->next;
	}
	cout << "Number of employees : "<<count<<endl;
}
int deleteend()
{
	struct node* temp;
	temp = h;
	if (temp == NULL)
	{
		cout << "List is empty";
		return 0;
	}
	if (temp->next == NULL)
	{
		cout << temp->ssn;
		cout << temp->name;
		cout << temp->dept;
		cout << temp->desg;
		cout << temp->sal;
		cout << temp->phno;
		delete [] temp;
		h = NULL;
	}
	else 
	{
		temp = temp1;
		temp2 = temp1->prev;
		temp2->next = NULL;
		cout << temp->ssn;
		cout << temp->name;
		cout << temp->dept;
		cout << temp->desg;
		cout << temp->sal;
		cout << temp->phno;
		delete [] temp;
		temp1 = temp2;
	}
	count --;
	return 0;	
}
int deletebeg()
{
	struct node*temp;
	temp = h;
	if (temp == NULL)
	{
		cout << "List is empty";
		return 0;
	}
	if (temp->next == NULL)
	{
		cout << temp->ssn;
		cout << temp->name;
		cout << temp->dept;
		cout << temp->desg;
		cout << temp->sal;
		cout << temp->phno;
		delete [] temp;
		h = NULL;
	}
	else
	{
		h = h->next;
		h->prev = NULL;
		cout << temp->ssn;
		cout << temp->name;
		cout << temp->dept;
		cout << temp->desg;
		cout << temp->sal;
		cout << temp->phno;
		delete [] temp;
	}
	count --;
	return 0;
}
void employerDetails()
{
	int ch,n,i;
	h = NULL;
	temp = temp1 = NULL;
	cout << "----------MENU----------"<<"\n";
	cout <<"1.create a dll of n employee"<<"\n";
	cout <<"2.display from the begining "<<"\n";
	cout <<"3.insert at the end "<<"\n";
	cout <<"4.delete at the end"<<"\n";
	cout <<"5.insert at the begining"<<"\n";
	cout <<"6.delete at the begining "<<"\n";
	cout <<"7.to show dll as queue"<<"\n";
	cout <<"8.Exit"<<"\n";
	cout <<"--------------------------"<<"\n";
	while (1){
		cout << "enter choice :";
		cin >>ch;
		
		switch(ch){
			case 1:
				cout << "Enter the number of employees ";
				cin >>n;
				for (i =0;i<n;i++){
					insertend();
				}
				break;
			case 2:
				displaybeg();
				break;
			case 3:
				insertend();
				break;
			case 4:
				deleteend();
				break;
			case 5:
				insertbeg();
				break;
			case 6:
				deletebeg();
				break;
			case 7:
				cout << "to show dll as queue";
				cout << "perform insert and ";
				cout << "deletion operation by";
				cout << "calling insertbeg() and";
				cout << "deleteend() respectively";
				break;
			case 8:
				exit(0);
			default:
				cout << "Wrong Choice ";
		}
	}
}
int main()
{
	employerDetails();
	return 0;
}





















