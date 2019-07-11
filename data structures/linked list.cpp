#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int d=0):data(d),next(NULL){}
    ~node(){
        cout<<"destructor starting: deleting "<<data<<endl;
        delete next;
    }
};

void insertathead(node* &head,int d){
    if(head==NULL){
        head =new node(d);
        return;
    }
    node *n=new node(d);
    n->next=head;
    head= n;
}

void insertattail(node *&head,int d){
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
void insertinmiddle(node* &head,int d,int p){
    if(p==0){
        insertathead(head,d);
        return;
    }
    node *temp=head;
    for(int i=1;i<=p-1;i++){
        temp=temp->next;
    }
    node* n=new node(d);
    n->next=temp->next;
    temp->next=n;

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

void deleteattail(node *&head){
    node* temp=head;
    node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
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

node* reverse_rec(node* head){
    if(head->next==NULL){
        return head;
    }
    node* temphead=NULL;
    temphead=reverse_rec(head->next);
    head->next->next=head;
    head->next=NULL;
    return temphead;
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

node* midpoint(node * head){
    node* slow=head;
    node*fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* merge(node *a,node*b){
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node* c;
    if(a->data<=b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
node* mergesort(node *head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node*  mid=midpoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;
    a=mergesort(a);
    b=mergesort(b);

    return merge(a,b);

}

int length(node* head){
    if(head==NULL){
        return 0;
    }
    int l;
    l=length(head->next)+1;
    return l;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

istream& operator>>(istream &is,node *&head){
    int d;
    while (scanf("%d",&d)!=EOF) {
        insertathead(head, d);
    }
    return is;
}

ostream& operator<<(ostream& os,node* &head){
    print(head);
    return os;
}

int main(){
    node *head=NULL;
    insertathead(head, 3);
    insertathead(head, 18);
    insertathead(head, 1);
    insertattail(head, 5);
    print(head);
    insertinmiddle(head, 4, 3);
    print(head);
    deleteathead(head);
    print(head);
    deleteattail(head);
    print(head);
    deleteinmiddle(head, 1);
    print(head);
    head=reverse_rec(head);
    cout<<"reversing recursively"<<endl<<head;
    reverse_iteratively(head);
    cout<<"reversing iteratively"<<endl<<head;
    head=mergesort(head);
    cout<<"sorted linked list is"<<endl<<head;
    return 0;
}