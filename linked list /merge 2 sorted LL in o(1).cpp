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

node* merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    node* newhead=NULL;
    if(a->d>b->d){
        newhead=b;
        newhead->next=merge(a,b->next);
    }else{
        newhead=a;
        newhead->next=merge(b,a->next);
    }
    return newhead;
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



    return 0;
}
