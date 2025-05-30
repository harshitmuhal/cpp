/*
Main logic behind the question is that you need to find the nth prime number starting from 2. Any one can implement this logic "Not a big Deal" for anyone, but wait a min there's more to it.

Many of you are getting time limit exceed right ? Even if you are using SOE (Sieve of Eratosthenes) for finding the prime numbers.

Have u see the constraint on number of test cases, It's quite large because for every test case you are going to find the prime numbers upto that number and at last return the last prime number found, this will cause the TLE for big test cases.

So, to overcome this problem, let's just store your test cases in an array.
Then find the maximum number from all of the testcases.
then, Use SOE(Sieve of Eratosthenes) to find the prime number upto that number and store that an the array.
After storing, simply loop over every test case that was stored previously in an array.
Print the value of n from the array storing primes.
That's how we need not to find the prime number for every test case. :)
*/


#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000000
vector<bool>isPrime (MAX,true);
unsigned primearray[5761459];


void gen_primes(){
    isPrime[0]=isPrime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(unsigned j=i;j*i<=MAX;j++) isPrime[i*j]=false;
        }
    }
    unsigned idx = 1;
    primearray[0]=2;

    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            primearray[idx++]=i;
        }     
    }
}

int main(int argc, char const *argv[])
{

    gen_primes();

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<primearray[n-1]<<endl;
    }
    return 0;
}
