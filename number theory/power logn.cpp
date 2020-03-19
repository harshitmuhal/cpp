#include<iostream>
using namespace std;

template<class type>
type power(type x, int n) {
    type temp; int y=n;
    if(y == 0) return 1;
    temp = power(x,y/2);
    return ((y % 2)?((y>0)?x * temp * temp:(temp * temp) / x):temp * temp);
}
int main(){
    int a;int x;
    cin>>a>>x;
    cout<<power<double>(a,x);
    return 0;
}
