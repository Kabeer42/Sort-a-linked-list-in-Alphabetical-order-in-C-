#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Node{
	public:
	string name;
	int age ;
	int race ;
	int Breeds;
	float Bones ;
	int strength;
	int weight;
	string feed;
	Node *next;
	
	void input (string name,int age ,int race,int Breeds,float Bones ,int strength,int weight,string feed);
	void bubbleSort(Node Name,int size);
		void sortedInsert(Node* newnode);
		
};
int size =0;
Node *Head ,*tail,*sorted ;

Node *NewNode(string name,int age ,int race,int Breeds,float Bones ,int strength,int weight,string feed ){
	Node *Name = new Node() ;
	Name->name = name;
	 Name->age=age;
	 Name->Bones=Bones;
	 Name->strength=strength;
	 Name->Breeds=Breeds;
	 Name->feed=feed;
	 Name->race=race;
	 Name->weight=weight;
	 Node *next=NULL;
	 return Name ;
}
//inserting a Node in Linked list
 void input(string name,int age ,int race,int Breeds,float Bones ,int strength,int weight,string feed ){
  	size ++;
  	Node *Name = NewNode(name, age ,race,Breeds,Bones ,strength,weight,feed ) ;
	
  	if (Head == NULL){
  		Head = Name ;
	  }
	  else 
  	{
  	Node* temp = Head;
  	while(temp->next != NULL){
  		
  		temp = temp->next;
  	}
  		temp->next = Name ;
  		tail=Name ;
		  }
	  }
  
int i=0;
//Swap a Node by pointer
void Swap(Node*& a, Node*& b){
	Node* temp = a;
	a = b;
	b = temp;
}
						
void bubbleSort(){
  
	Node *ptr=NULL,*cur=Head;
   while (cur!=NULL)
   {
   	ptr=cur->next;
	while (ptr != NULL){
   	
   	int i=0;
   	int Ascii1 = int (cur->name.at(i));
   	int Ascii2 = int (ptr->name.at(i));
	
	  if(Ascii1 > Ascii2) { 
  	cout<<"cur->name  " << cur->name<<endl;
	cout <<"ptr->name  "<< ptr->name<<endl;
	  
              if (cur ==Head){
              	Head = Head->next;
			  }
			  swap(cur,ptr);
	  cout<<"cur->name  " << cur->name<<endl;
		cout <<"ptr->name  "<< ptr->name<<endl;
            } ptr=ptr->next; 
		}
		cur =cur->next;
	}
   }
	
	void sortedInsert(Node* newnode)
	{
		if (sorted == NULL || sorted->name.at(0) >= newnode->name.at(0)) {
			newnode->next = sorted;
			sorted = newnode;
		}
		else {
			Node* current = sorted;
			while (current->next != NULL && current->next->name.at(0) < newnode->name.at(0)) {
				current = current->next;
			}
			newnode->next = current->next;
			current->next = newnode;
		}
	}
	void insertionSort(Node* headref)
	{
		sorted = NULL;
		Node* current = headref;
		while (current != NULL) {
			Node* next = current->next;
			sortedInsert(current);
			current = next;
		}
		Head = sorted;
	}
	// to display a linked List 
void print() {
	Node* temp = Head;
	while (temp != NULL){
	cout << i+1 <<" "<< temp ->name<<endl ;
    cout << " Age : "<< temp -> age<<endl ;
    cout <<" Race : "<< temp -> race <<endl ;
    cout << " Breeds : "<< temp->Breeds <<endl ;
	cout << " Bonds : "<< temp->Bones<<endl ;
    cout << " strength : "<< temp->strength<<endl ;
    cout << " weight : "<< temp->weight <<endl ;
    cout << " feed : "<< temp->feed <<endl ;
    cout << endl;
		temp = temp->next;
		i++;
	}
	}

int main(){
	Head= NULL;
	input ("Horese",25 ,88,400,205,15,300,"90% dry matters");
	input ("Camel",50 ,65,4,0 ,3,960,"89% dry Matters");
	input ("Cow",20 ,40,71,2.4 ,88,720,"30 kilo ");
	input ("Buffallo",25,56,10,200,05,800,"30 Kg/day");
	insertionSort(Head);
	print();
return 0;
}

