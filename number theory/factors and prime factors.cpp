vector<int> primes;
vector<pair<int,int>>primeFactors;
void p_factorize (int N){
    for (int i=0; i<primes.size(); i++)
    {
        int Count=0;
        while (N%primes[i]==0)
        {
            N/=primes[i];
            Count++;
        }
        if (Count)
            primeFactors.pb({primes[i], Count});
    }
    if (N!=1)
        primeFactors.pb({N, 1});
}


void factor(vector<int> &v,int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i*i==n){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
}
