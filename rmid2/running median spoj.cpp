#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    long long int d,median;

    long long int t;
    cin>>t;
    while(t--){
        priority_queue<long long int,vector<long long int>,greater<long long int>> minheap;
        priority_queue<long long int> maxheap;
    
        while(1){
            scanf("%ld",&d);
            if(d==0){
                break;
            }
            if(d!=-1){
                if( minheap.size()==0 and maxheap.size()==0){
                    maxheap.push(d);
                }
                else if(d>maxheap.top()){
                    minheap.push(d);
                }else{
                    maxheap.push(d);
                }
                if(max(maxheap.size(),minheap.size())-min(maxheap.size(),minheap.size())==2){
                    if(maxheap.size()>minheap.size()){
                        long long int p=maxheap.top();
                        maxheap.pop();
                        minheap.push(p);
                    }else{
                        long long int p=minheap.top();
                        minheap.pop();
                        maxheap.push(p);
                    }
                }
                
            }
            else{
                if(maxheap.size()==minheap.size()){
                    if(maxheap.top()>=minheap.top()){
                        median=minheap.top();
                        minheap.pop();
                    }else{
                        median=maxheap.top();
                        maxheap.pop();
                    }
                    printf("%ld\n",median);
       
                }else if(maxheap.size()>minheap.size()){
                    median=maxheap.top();
                    maxheap.pop();
                    printf("%ld\n",median);
                }else{
                    median=minheap.top();
                    minheap.pop();
                    printf("%ld\n",median);
                }
            }
    }


    }
    return 0;
}