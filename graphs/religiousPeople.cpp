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
#define umi unordered_map<int,int>
#define endl "\n"
#define w(x) int x; cin>>x; while(x--)
#define db(x) cout<<(#x)<<" "<<(x)<<"\n";
#define db2(x,y) cout<<(#x)<<" "<<(x)<<" ,"<<(#y)<<" "<<(y)<<"\n";
#define db3(x,y,z) cout<<(#x)<<" "<<(x)<<" ,"<<(#y)<<" "<<(y)<<" ,"<<(#z)<<" "<<(z)<<"\n";
#define print(a) for(auto x:a){cout<<x<<" ";}
#define ios ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
//using namespace boost::multiprecision;

int mod = 1000000007;
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
template<class type>
type power(type x, int n) {
    type temp; int y = n;
    if (y == 0) return 1;
    temp = power(x, y / 2);
    return ((y % 2) ? ((y > 0) ? x * temp * temp : (temp * temp) / x) : temp * temp);
}
void c_p_c() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

list<int>*l;
int n;
int m;

int dfs(int src,map<int,bool>&visited){
    visited[src]=true;
    int size=1;
    for(auto nbr:l[src]){
        if(!visited[nbr]){
            int temp=dfs(nbr,visited);
            size+=temp;
        }
    }
    return size;
}

int mincost(){
    map<int,bool>visited;
    int size;
    int cost=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            size=dfs(i,visited);
            cost+=min((size-1)*b+a,size*a);
        }
    }
    return cost;
}

int32_t main() {

    ios
    c_p_c();
   // w(t)
    {   
        cin>>n>>m;
        l=new list<int>[n+1];
        fl(i,0,m-1){
            int x,y;
            cin>>x>>y;
            l[x].pb(y);
            l[y].pb(x);
        }
        cout<<mincost()<<endl;
    }

    return 0;
}