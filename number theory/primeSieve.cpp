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
            // this inner loop is for marking multiples of i as not prime
            // so multiples of i are present at i,i+i,i+i+i...that is why
            // in the inner loop increment is by 2*i ..its not only i because
            // we want to mark only for odd positions.
            for(int j=i*i;j<=n;j+=2*i){
            // if we start loop from i*i then at any i,numbers before i*i
            //already check ho chuke honge for prime by numbers less than i
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
