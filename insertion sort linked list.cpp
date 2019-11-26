#include<iostream>
#include<cstring>
using namespace std;
class node {
public:
    int d;
    node *next;
};
node *head=NULL;
node *end_=NULL;
void insert(int d){
    node *temp=new node;
    temp->d=d;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        end_=head;
    }
    else{
        end_->next=temp;
        end_=temp;
    }
}
node *head2=NULL;node *end2=NULL;

void push(node *keynode){
    if(head2==NULL){
        keynode->next=NULL;
        head2=keynode;
        return;
    }
    if(head2->d>keynode->d){
        keynode->next=head2;
        head2=keynode;
        return;
    }
    node *current=head2;
    while(current->next!=NULL && current->next->d<keynode->d){
        current=current->next;
    }
    keynode->next=current->next;
    current->next=keynode;
}
void insertionsort(){
    node *current=head,*next=NULL;
    while(current!=NULL){
        next=current->next;
        push(current);
        current=next;
    }
}
void display(node *head2){
    node *temp=head2;
    while(temp!=NULL){
        cout<<temp->d<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main(){
    insert(4);
    insert(1);
    insert(7);
    insert(2);
    insert(6);
    display(head);
    insertionsort();
    display(head2);
    return 0;
}
