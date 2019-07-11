#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string a,string b){
return a<b;
}

int permute(char input[],int i,string s[],int k){
    //base case
    if(input[i]=='\0'){
        s[k]=input;
        k++;
        //cout<<input<<endl;
        return k;
    }

    //rec case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
       k= permute(input,i+1,s,k);
        swap(input[i],input[j]);
    }
return k;
}

int main(){

    string s[10000];
    char input[10000];
    cin.getline(input,10000);
    int k=permute(input,0,s,0);
    sort(s,s+k,compare);
    for(int z=0;z<k;z++){
        if(s[z]<input){
            cout<<s[z]<<endl;
        }
    }
    return 0;
}