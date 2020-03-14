#include<iostream>
using namespace std;

class node{
public:
    long long int data;
    node *next;
    node(long long int d=0):data(d),next(NULL){}

};

void insertathead(node* &head,long long int d){
    if(head==NULL){
        head =new node(d);
        return;
    }
    node *n=new node(d);
    n->next=head;
    head= n;
}

void insertattail(node *&head,long long int d){
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

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
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

int main(){
    long long int n,k,no;
    cin>>n>>k;
    
    node* head=NULL;
    for(long long int i=0;i<n;i++){
        cin>>no;
        insertattail(head,no);
    }
    if(k!=1){
        
        node *temp=head;
        node *next_=temp->next;
        for(long long int j=1;j<=k-1;j++){
            temp=temp->next;
            next_=temp->next;
        }
        temp->next=NULL;
        reverse_iteratively(head);
        print(head);

        for(long long int i=1;i<=n/k-1;i++){
            temp=next_;
            node* temphead=temp;
            for(long long int j=1;j<=k-1;j++){
                temp=temp->next;
                next_=temp->next;
            }
            temp->next=NULL;
            reverse_iteratively(temphead);
            print(temphead);
        }

        if(n%k!=0){
            reverse_iteratively(next_);
            print(next_);
        }
    
    }
    else
        print(head);
    
    return 0;
}