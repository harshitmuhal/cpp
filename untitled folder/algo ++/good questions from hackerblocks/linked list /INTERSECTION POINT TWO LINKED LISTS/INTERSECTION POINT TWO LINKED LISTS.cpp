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

long int length(node* head){
    
    long int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    long int n;
    cin>>n;
    long int i=0;
    long int d;
    while(i<n){
        cin>>d;
        insertattail(head1,d);
        i++;
    }
    cin>>n;
    i=0;
    while(i<n){
        cin>>d;
        insertattail(head2,d);
        i++;
    }
    long int l1,l2;
    l1=length(head1);
    l2=length(head2);
    long int diff=max(l1,l2)-min(l1,l2);
    node* t,*q;
    if(l1>l2){
        t=head1;
        q=head2;
    }
    else{
        t=head2;
        q=head1;
    }
    for(long int i=1;i<=diff;i++){
        t=t->next;
    }
    int f=-1;
    while(t!=NULL and q!=NULL){
        if(t->data==q->data){
            cout<<t->data;
            f=0;
            break;
        }
        t=t->next;
        q=q->next;
    }
    if(f==-1){
        cout<<-1;
    }
    return 0;
    }
