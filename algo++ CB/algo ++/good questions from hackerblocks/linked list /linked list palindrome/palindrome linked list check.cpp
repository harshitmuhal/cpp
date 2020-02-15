#include<iostream>
using namespace std;

class node{
public:
    long int data;
    node *next;
    node(long int d=0):data(d),next(NULL){}
    
};
void insertathead(node* &head,long int d){
    if(head==NULL){
        head =new node(d);
        return;
    }
    node *n=new node(d);
    n->next=head;
    head= n;
}
void insertattail(node *&head,long int d){
    if(head==NULL){
        insertathead(head, d);
    }
    else{
        node* temp=head;
        node * prev=NULL;
        while(temp!=NULL){
            prev =temp;
            temp=temp->next;
        }
        node* n=new node(d);
        prev->next=n;
        delete temp;
        prev=NULL;
        delete prev;}
}

node* midpoint(node * head){
    node* slow=head;
    node*fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void reverse_iteratively(node* &head){
    
    node* temp=NULL;
    node* current=head;
    node* prev=NULL;
    while(current!=NULL){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* head=NULL;
    long int n;
    cin>>n;
    long int i=0;
    long int d;
    while(i<n){
        cin>>d;
        insertattail(head,d);
        i++;
    }
    node*mid =midpoint(head);
    node *head2=mid->next;
    mid->next=NULL;
    reverse_iteratively(head2);
    int f=-1;
    while(head!=NULL and head2!=NULL){
        if(head->data!=head2->data){
            f=-1;
            break;
        }
        else{
            f=0;
            head=head->next;
            head2=head2->next;
        }
    }
    if(f==-1){
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }

    return 0;
    }
