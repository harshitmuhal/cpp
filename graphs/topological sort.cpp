#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#include<cstring>
#include<list>
#define floop(i,n) for(int i=0;i<n;i++)
#define initialise(x,y,a,b) for(int i=x;i<y;i++){a[i]=b;}
#define pb push_back
#define pob pop_back
#define lli long long int
#define li long int
#define pi 3.1415926535898

using namespace std;

class graph{
public:
    map<int,list<pair<int,int>>> mp;

    void insert(int i,int j,int l){
        mp[i].push_back(make_pair(j,l));
    }
    void topologicalsort(int n){
        int indegree[20];
        for(int i=1;i<=n;i++){
            indegree[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(auto y:mp[i]){
                indegree[y.first]++;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<indegree[i]<<" ";
        }cout<<endl;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            cout<<f<<" ";
            for(auto nbr:mp[f]){
                indegree[nbr.first]--;
                if(indegree[nbr.first]==0){
                    q.push(nbr.first);
                }
            }
        }
            

        
    }
    void bfs(int n){
        int src=1;
        bool visited[n+1];
        for(int i=0;i<=n+1;i++){
            visited[i]=0;
        }
        visited[src]=true;
        queue<int>q;
        q.push(src);
        q.push(-1);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(f!=-1){
            cout<<f<<" ";
            for(auto x:mp[f]){
                if(!visited[x.first]){
                    q.push(x.first);
                    visited[x.first]=true;
                }
            }
             q.push(-1);
            }
            else{
                cout<<endl;
            }
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        graph g;
        int x=n;
        while(x--){
            int a,b,l;
            cin>>a>>b>>l;
            g.insert(a,b,l);
        }
        //g.bfs(n);
        g.topologicalsort(n);
    }
    return 0;
}
