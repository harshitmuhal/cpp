#include<bits/stdc++.h>
using namespace std;


list<pair<int, int>>*l;

int findminVertex(map<int,bool>visited,int *weight,int n){
    int minVertex = -1;
    for(int i=1;i<=n;i++) {
        if(!visited[i] and (minVertex==-1 or weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int src,int n) {
    int *weight=new int[n+1];
    int *parent=new int[n+1];
    map<int,bool>visited;
    for(int i=1;i<=n;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[src]=0;
    parent[src]=-1;
    for(int i=0;i<n;i++){
        int minvertex=findminVertex(visited,weight,n);
        visited[minvertex]=true;
        for(auto nbr:l[minvertex]){
            if(!visited[nbr.first]){
                if(weight[nbr.first]>nbr.second){
                    weight[nbr.first]=nbr.second;
                    parent[nbr.first]=minvertex;
                }
            }
        }
    }
    int totalWeight = 0;
    for(int i=1;i<=n;i++) {
        totalWeight+=weight[i];
    }
    cout<<totalWeight<<endl;
}


int main() {
    int n, m;
    cin >> n >> m;
    l = new list<pair<int, int>>[n + 1];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        l[x].push_back({y, z});
        l[y].push_back({x, z});
    }
    int src;
    cin>>src;
    prims(src,n);
    return 0;
}

