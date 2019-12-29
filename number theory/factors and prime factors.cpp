Vector<int> solve(int n,int k){
    vector<int> P;
    while (n%2 == 0){            //this loop will terminate when no more 2 are present as a prime factor
         P.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
            n = n/i;
            P.push_back(i);
        }
    }
    if (n > 2){                 //this is the case when n itself will be a prime no
        P.push_back(n);
    }
return P;
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
