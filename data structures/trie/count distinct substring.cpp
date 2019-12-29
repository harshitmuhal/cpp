#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
#define fl(i,a,n) for(int i=a;i<=n;i++)
#define pb push_back
#define pob pop_back
#define int long long int
#define ff first
#define ss second
#define pi 3.1415926535898
#define vi vector<int>
#define mi map<int,int>
#define w(x) int x; cin>>x; while(x--)
#define dbug(x) cout<<(#x)<<" "<<(x)<<"\n";
#define ios ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
//using namespace boost::multiprecision;
int mod=1000000007;
int gcd(int a,int b){
     return (b == 0) ? a :gcd(b, a % b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
class node{
public:
    char data;
    map<char,node*>mp;
    bool isterminal;
    node(char ch){
        data=ch;
        isterminal=false;
    }
};
class trie{
public:
    node *root;
    trie(){
        root=new node('\0');
    }
    void insert(string word){
        node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->mp.count(word[i])!=0){
                temp=temp->mp[word[i]];
            }
            else{
                node * nd=new node(word[i]);
                temp->mp[word[i]]=nd;
                temp=nd;
            }
        }
        temp->isterminal=true;
    }
    bool search(string s){
        node *temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->mp.count(s[i])==0){
                return 0;
            }
            temp=temp->mp[s[i]];
        }
        return temp->isterminal;
    }
    int cnt(node *temp){
        if(temp->mp.size()==0){
            return 1;
        }
        int ans=0;
        for(auto x:temp->mp){
            ans+=cnt(x.ss);
        }
        return 1+ans;
    }
    int cntnode(){
        return cnt(root); 
    }
};
int32_t main(){
    
    ios
    c_p_c();
    w(t)
    {
      string s;
      cin>>s;
      trie tt;
      for(int i=0;i<s.length();i++){
        tt.insert(s.substr(i,s.length()-i));
      }
      cout<<tt.cntnode()<<endl;
      //cout<<tt.cntnode()-1<<endl;  display this if you don't want to count the empty substr
    }

    return 0;
}

