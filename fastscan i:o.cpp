#include<iostream>
#include<vector>
#include<unordered_map>
#include<time.h>
using namespace std;

void fastscan(int &number){
    register int ch;
    number=0;
    ch=getchar();
    bool negative=false;
    if(ch=='-'){
        negative=true;
    }
    ch=getchar();
    for(;ch>47 and ch<58 ;){
        number=number*10+ch-'0';
        ch=getchar();
    }
    if(negative){
        number*=-1;
    }
}


int main() {
    
    int n;
    
    clock_t t1,t2;
    t1=clock();
    fastscan(n);
    t2=clock();
    float diff = ((float)t2-(float)t1)/CLOCKS_PER_SEC;
    cout << "Running time: " << diff << endl;
    
    
    t1=clock();
    scanf("%d",&n);
    t2=clock();
    diff = ((float)t2-(float)t1)/CLOCKS_PER_SEC;
    cout << "Running time: " << diff << endl;
    printf("%d",n);
    
    return 0;
}
//if you compare time than fastscan is 5-7 times faster on average