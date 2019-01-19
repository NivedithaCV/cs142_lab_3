//DOUBLE LINKED LIST
//Library
#include<iostream>
using namespace std;

class Node		//class for node
{
	public:		
	int data;	//data
	Node*next;	//pointer to next node
	Node*prev;	//pointer to previous node
	Node(int value)//constructor that will make the pointer to null
	{
	next=NULL;
	prev=NULL;
	data=value;
	}
};

class DLL
{
	public:
	Node*head;
	
	DLL()
{
	head=NULL;	//initial value
	
}
	void insert(int value)
	{
	Node *temp=new Node(value);	//create a new node
	if (head==NULL)			//check if empty list
{	head=temp;
	}
	else				//if not empty
	{
	Node*current=head;
	while(current->next!=NULL)
		current=current->next;	//moving forward
		current->next=temp;	//linking to the list
		temp->prev=current;
	}
}
	void display()
	{
	Node*current=head;		//pointing to the current node
	Node*last;
	cout<<"Print in oder :";
	while(current!=NULL)
	{
		cout<<current->data<<"->";
		last=current;			//store the current in last(to catch the tail to print in reverse)
		current=current->next;		//move forward
	}
	cout<<"null"<<endl;
	cout<<"print in reverse oder:";
	while(last!=NULL)
	{
	cout<<last->data<<"->";
	last=last->prev;			//move backwards
	}
	cout<<"null"<<endl;
	}

	void insertAt(int pos,int value)
	{
	
	Node*temp=new Node(value);		//making new node
	Node*current=head;			//ponting to head
	
	if(pos==1)				//if to be inserted firsr
	{
	temp->next=head;			//linking new to head
	head->prev=temp;			//pointing previous head to new
	head=temp;}				//making new node as head
	else{			//else
	int i=2;
	
	while(i<pos)
	{
	current=current->next;
	i++;
	}
	
	temp->next=current->next;//pointing next
	temp->prev=current;
	current->next=temp;
	temp->next->prev=temp;
	}}
	
	
	
	int countItems()
{
	Node*current=head;int i=0;
	while(current!=NULL)
{
	i++;				//counting elements
	current=current->next;
}
	return(i);			//returning total number of elements
}
	void delet()
	{
	Node*current=head;
	Node*last;
	while(current->next!=NULL)	//stoping the loopat the end
	{
	last=current;			//storing the adress of the last node
	current=current->next;}		//moving forward
	
	last->next=NULL;		//pointing to null
	current->prev=NULL;}
	

	void deletAt(int pos,int lst)
	{
	Node*current=head;
	if(pos==1)		//condition to delete he first element
	{
	
	Node*temp=head;		
	head=current->next;	//making the next node as head
	temp=NULL;		
	delete temp;		//dleting the temp from heap
	}
		else if(pos==lst)
		{Node*last;
		while(current!=NULL)		//deleting from the last
		{
		last=current;
		current=current->next;
		}
		Node*temp=last;
		temp->prev->next=NULL;		
		last=NULL;		//deleting fom heap
		delete temp;
		}
			else if(pos>lst)	//printing message when position exceeds
			{
			cout<<"Linked list does not have that many elements"<<endl;
			}	
		else		//deleting from any position
		{
		int i=2;
		while(i<pos)
		{
		current=current->next;
		i++;
		}
		Node*temp=current->next;	//removing pointers from and to other nodes
		current->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		}
		
	}
};

int main()
{
DLL dll1;	//object
int a,b,c;	
dll1.insert(1);	//inseting nodes
dll1.insert(2);
dll1.insert(3);
dll1.insert(4);
dll1.display();//display
c=dll1.countItems();
cout<<"give the position and the value"<<endl;
cin>>a;
cin>>b;
if(a<=c){		//checking limit of inserting
dll1.insertAt(a,b);	//inserting at position
dll1.display();}
else
{
cout<<"Linked list doesnot have that many elements"<<endl;
}
cout<<"number of elements after inserting new node"<<dll1.countItems();
dll1.delet();		//deleting from last position
dll1.display();
cout<<"number of elements after delete at last"<<dll1.countItems()<<endl;
a=dll1.countItems();	//counting number of elements
cout<<"delete at"<<endl;
cin>>c;
dll1.deletAt(c,a);	//deleting at position
dll1.display();
return 0;

}
