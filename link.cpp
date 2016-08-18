#include <iostream>
using namespace std;

struct node{
 int data;
 node *next;
};
//func1
void insert(node*root,int data){
	 node *tmp = new node;
	 // new node creation data entry , address null
     tmp->data = data;
     tmp->next = NULL;
     //empty condtn
	if(root == NULL) {
    	root = tmp;
	} 
    // traversing the list making new node and link last node to new data 
	node *current = root;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = tmp;

}
//func 2
node *inserth(node*root,int data){
	 node *tmp = new node;
	  // new node creation data entry , address null
     tmp->data = data;
     tmp->next = NULL;
	if(root == NULL) {
    	root = tmp;
    	//root->next=NULL;
	} 
	// new link node tmp addressing it from headto root
    tmp->next=root;
    return tmp;
	
}
//func3
node *insertp(node*root,int data,int pos){
	 node *tmp = new node;
     tmp->data=data;
     tmp->next=NULL;
     if(pos==0){
     	tmp->next=root;
     	root=tmp;
     	return root;
	 }
	 // tarverse the node topos
	 node *tmp1=root;
	 for(int i=0; i<pos-1;i++)
	 tmp1=tmp1->next;	 
	 // linking new node to that pos
	tmp->next=tmp1->next;
	tmp1->next=tmp;
	return root;
}
int main(){
	node *root= new node;
	root->next=NULL;
	root->data=5;
	insert(root,42);//at last or tail
	root=inserth(root,33);//at beginning
	root=insertp(root,45,1);// at second postn
	node *c=new node;
	c=root;
	while(c!=NULL){
		cout<<c->data<<endl;
		c=c->next;
	}
	return 0;
}
