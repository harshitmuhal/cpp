#include<bits/stdc++.h>
#define maxsize 100
using namespace std;

int bst[maxsize];

void insert(int d,int i=0){
    if(bst[i]==-1){
        bst[i]=d;
        return;
    }
    int left=2*i+1;
    int right=2*i+2;
    if(bst[i]>d){
        insert(d,left);
    }
    else{
        insert(d,right);
    }
}
bool search(int key,int i=0){
    if(i>=maxsize){
        cout<<"key is Not Present"<<endl;
        return 0;
    }
    if(bst[i]==key){
        cout<<"key is Present"<<endl;
        return 1;
    }
    int left=2*i+1;
    int right=2*i+2;
    if(bst[i]>key){
        bool temp=search(key,left);
        return temp;
    }
    else{
        bool temp=search(key,right);
        return temp;
    }
}
void reorder(int i){
    int x=ceil((double)i/2)-1;
    bst[x]=bst[i];
    bst[i]=-1;
    if(bst[2*i+1]!=-1)
        reorder(2*i+1);
    if(bst[2*i+2]!=-1)
        reorder(2*i+2);
}
void deletenode(int key,int i=0){
    if(i>=maxsize){
        return;
    }
    int left=2*i+1;
    int right=2*i+2;
    if(bst[i]==key){
        if(bst[left]==-1 && bst[right]==-1){
            bst[i]=-1;
            return;
        }
        else if(bst[left]!=-1 && bst[right]==-1){
            bst[i]=-1;
            reorder(left);
        }
        else if(bst[right]!=-1 && bst[left]==-1){
            bst[i]=-1;
            reorder(right);
        }
        else if(bst[left]!=-1 && bst[right]!=-1){
            int idx=right;
            while(bst[2*idx+1]!=-1){
                idx=2*idx+1;
            }
            int temp=bst[idx];
            deletenode(bst[idx]);
            bst[i]=temp;
        }
    }
    else{
        if(key<bst[i]){
            deletenode(key,left);
        }
        else{
           deletenode(key,right);
        }
    }
}
void levelorder(){
    queue<int>q;
    q.push(0);
    q.push(-1);
    while(!q.empty()){
        int i=q.front();
        if(i==-1){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(-1);
        }
        else{
            cout<<bst[i]<<" ";
            q.pop();
            if(bst[2*i+1]!=-1){
                q.push(2*i+1);
            }
            if(bst[2*i+2]!=-1){
                q.push(2*i+2);
            }
        }
    }
}
int main(){
    memset(bst,-1,sizeof(bst));
    insert(3);
    insert(1);
    insert(4);
    insert(2);
    insert(5);
    insert(8);
    levelorder();
    search(4);
    search(7);
    deletenode(4);
    levelorder();
    return 0;
}


