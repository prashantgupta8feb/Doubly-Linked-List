#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
};
node * head = NULL;
node* getnewnode(int x){
	node* newnode = new node();
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void InsertAtHead(int data){
	node* newnode=getnewnode(data);
	if(head==NULL){
		head=newnode;
		return;
	}
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
	}
void InsertAtTail(int data){
	node* temp= head;
	node* newnode= getnewnode(data);
	while(head==NULL){
		head=newnode;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=head;
}
void print(){
	node* temp=head;
	cout<<"Forward : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void printReverse(){
	node* temp=head;
	if(temp==NULL)return;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	cout<<"Reverse : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}
int main(){
	head=NULL;
	InsertAtHead(22);print();//printReverse();
	InsertAtHead(20);print();//printReverse();
	InsertAtTail(33);print();//printReverse();
	InsertAtTail(44);print();printReverse();
	InsertAtTail(25);print();
	cout<<head->data;
}
