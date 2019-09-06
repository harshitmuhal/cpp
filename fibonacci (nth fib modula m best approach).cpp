#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#define floop(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define pob pop_back
#define lli long long int
#define li long int
#define m 100

using namespace std;


void multiply(lli F[2][2], lli M[2][2]);

void power(lli F[2][2], lli n);
lli fib(li n)
{
    lli F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0]%m;
}
void power(lli F[2][2], lli n)
{
    if( n == 0 || n == 1)
        return;
    lli M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}

void multiply(lli F[2][2], lli M[2][2])
{
    lli x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%m;
    lli y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%m;
    lli z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%m;
    lli w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%m;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
int main(){
    
    cout<fib(n)%m;
    return 0;
}