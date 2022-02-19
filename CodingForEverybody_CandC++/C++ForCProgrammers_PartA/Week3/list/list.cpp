// List Elements
// Matthew Yough
// 04 January 2022

#include <iostream>
using namespace std;

class list_element
{
public:
	list_element(int n = 0, list_element* ptr = 0):d(n),next(ptr){}
	int d;
	list_element* next;
};

class list
{
public:
	list():head(0),cursor(0){}
	list(const int* arr, int n);
	list(const list& lst);//copy constructor
	void prepend(int n);
	int get_element(){return cursor->d;}
	void advance(){cursor=cursor->next;}
	void print();
	~list(); //delete
private:
	list_element* head;
	list_element* cursor;
};

void list::prepend(int n)
{
	if (head==0)
		cursor = head = new list_element(n,head);
	else
		head = new list_element(n,head);
}

void list::print()
{
	list_element* h = head;
	while(h != 0)
	{
		cout<<h->d<<",";
		h = h -> next;
	}
	cout<<"###"<<endl;
}

list::list(const list& lst)
{
	if(lst.head == 0)
	{
		head = 0;
		cursor = 0;
	}
		else
		{
			cursor=lst.head;
			list_element* h = new list_element();
			list_element* previous;
			head = h;
			h->d = lst.head->d;
			previous = h;
			for(cursor = lst.head; cursor != 0;)
			{
				h = new list_element();
				h->d = cursor->d;
				previous->next = h;
				cursor = cursor->next;
				previous = h;
			}
		} 
}

list::~list()
{
	for(cursor = head; cursor !=0;)
	{
		cursor = head->next;
		delete head;
		head = cursor;
	}
}

int main(void)
{

	list a,b;
	/*int data[10] = {3,4,6,7,-3,5};
	list d(data, 6);
	list e(data, 10);*/
	a.prepend(9);
	a.prepend(8);
	cout<<"list a"<<endl;
	a.print();
	for(int i = 0; i < 40; ++i)
	{
		b.prepend(i*i);
	}
	cout<<"list b"<<endl;
	b.print();
	/*list c(b);
	c.print();
	d.print();
	e.print();*/

	system("pause");
}