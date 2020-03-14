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


//if length is same

long int add(node* &head,node *&head2,node*&head3){
    if(head==NULL || head2==NULL){
        return 0;
    }
    long int carry=0;
    carry=add(head->next,head2->next,head3);
    long int temp=(head->data+head2->data)+carry;
    carry=temp/10;
    cout<<temp<<endl;
    cout<<"carry"<<carry<<endl;
    insertathead(head3, temp%10);
    cout<<"data"<<head3->data<<endl;
    return carry;
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

    node* head2=NULL;
    i=0;
    cin>>n;
    while(i<n){
        cin>>d;
        insertattail(head2,d);
        i++;
    }

    node*head3=NULL;
    long int last_carry=add(head,head2,head3);
    if(last_carry){
        insertathead(head3, last_carry);
    }
    print(head3);
    return 0;
}
