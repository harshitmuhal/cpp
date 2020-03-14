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

bool cycledetectionandremoval(node*head){
    node*slow=head;
    node*fast=head;
    
    bool result=false;
    
    while(fast!=NULL and fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            result= true;
            break;
        }

    }
        //If loop exists
        if (slow==fast)
        {   slow=head;
            
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            //since fast->next is the looping point
            fast->next = NULL; //remove loop
        }
    return result;
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
    
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //making a loop in linked list for testing
    temp->next=head->next->next;
    
    cout<<cycledetectionandremoval(head);
    cout<<cycledetectionandremoval(head);
    return 0;
}