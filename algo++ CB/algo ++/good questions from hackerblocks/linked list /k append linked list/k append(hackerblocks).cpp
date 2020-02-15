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
        delete prev;
    }
    
}

long int length(node* head){
    if(head==NULL){
        return 0;
    }
    long int l;
    l=length(head->next)+1;
    return l;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    long int d;
    node* head=NULL;
    long int n;
    cin>>n;
    long int i=0;
    while(i<n){
        cin>>d;
        insertattail(head,d);
        i++;
    }
    
    long int k;
    cin>>k;
    if(k>=n){
        k=k-n;
    }
        if(k!=n){
        node *temp=head;
        long int l=length(head);
        l=l-k+1;
        for(int i=0;i<l-2;i++){
            temp=temp->next;
        }
        node* x=temp->next;
        temp->next=NULL;
        temp=x;
        while(x->next!=NULL){
            x=x->next;
        }
        x->next=head;
        print(temp);
        //temp is our new head now
        }
        else{
            print(head);
        }
    return 0;
}
