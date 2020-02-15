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
    node*fast=head;
    while(fast!=NULL or fast->next!=NULL){
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

int length(node* head){
    if(head==NULL){
        return 0;
    }
    int l;
    l=length(head->next)+1;
    return l;
}

void deleteathead(node *&head){
    if(head==NULL){
        return;
    }
    node *temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

void deleteinmiddle(node *&head,int p){
    node* temp=head;
    node* prev=NULL;
    for(int i=1;i<=p;i++){
        prev =temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node * head=NULL;
    int n;
    cin>>n;
    int i=0,d;
    while(i<n){
        cin>>d;
        insertattail(head,d);
        i++;
    }
    //input has been taken now
    
    node *current;
    current=head;
    int current_length=1;
    int l=length(head);
    //finding first occurence of an odd number bcz that will be our first node so head should point to that
    while((current->data&1)!=1){
        temp=current;
        insertattail(head,current->data);
        current=current->next;
        current_length++;
    }
    
    head=current;
    
    current=current->next;
    
    int pos=1;
    
    while(current_length<l){
        if((current->data&1)==0){
            temp=current;
            insertattail(head,current->data);
            current=current->next;
            deleteinmiddle(head, pos);
            
        }
        else{
            pos++;
            current=current->next;
        }
        current_length++;
    }
    
    print(head);
    return 0;
}
