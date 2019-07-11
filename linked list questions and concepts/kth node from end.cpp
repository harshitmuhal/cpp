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
    if(head==NULL){
        return 0;
    }
    long int l;
    l=length(head->next)+1;
    return l;
}
int main(){
    long int d;
    node* head=NULL;
    while(1){
        cin>>d;
        if(d==-1){
            break;
        }
        insertattail(head,d);
    }
    int k;
    cin>>k;
    node *temp=head;
    long int l=length(head);
    l=l-k+1;
    for(int i=0;i<l-1;i++){
        temp=temp->next;
    }
    cout<<temp->data;
    return 0;
}


