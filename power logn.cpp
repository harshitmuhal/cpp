#include<iostream>

using namespace std;

int fn(int a,int x){
    int ans=1;
    while(x>0){
        if(x&1){
            ans*=a;
        }
        a=a*a;
        x=x>>1;
    }
    return ans;
}

int main(){
    int a;int x;
    cin>>a>>x;
    cout<<fn(a,x);
    return 0;
}