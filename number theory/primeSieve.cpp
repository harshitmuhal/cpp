#include <iostream>
using namespace std;
void psieve(int *p,int n){
    p[0] = p[1] = 0;
    p[2] = 1;
    for(int i=3;i<=n;i+=2){
        p[i] = 1;
    }
    for(int i=3;i<=n;i+=2){
        if(p[i]){
            for(int j=i*i;j<=n;j+=2*i){
                // if we start loop from i*i then at any i numbers before i*i already check ho chuke honge for prime
                p[j] = 0;
            }
        }
    }
    return;
}
int main() {
    int p[1000001] = {0};
    int t;
    cin>>t;
    primeSieve(p,t);
    return 0;       
}
