#include<iostream>
using namespace std;


// gcd and hcf are two names of same thing!!

//euclid's algorithm

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    
    int gcd_=gcd(b,a%b);
    return gcd_;
}

//product of lcm and gcd is equal to the product of the number itself
int lcm(int gcd_,int a,int b){
    return (a*b)/gcd_;
}


int main() {
    int a,b;
    cin>>a>>b;
    int gcd_=gcd(a,b);
    cout<<"gcd : "<<gcd_<<endl;
    cout<<"lcm : "<<lcm(gcd_,a,b)<<endl;
    return 0;
}
