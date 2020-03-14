#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename t>
class graph{
public:
    
    map<t,list<t> > adjlist;
    
    graph(){
    }
    
    void addedge(t i,t j,bool isbidirectional=true){
        adjlist[i].push_back(j);
        if(isbidirectional){
            adjlist[j].push_back(i);
        }
    }
    
    bool iscyclicbfs(int s){
        map<t,t> visited;
        map<t,t> parent;
        queue<t> q;
        q.push(s);
        parent[s]=s;
        visited[s]=true;
        
        while(!q.empty()){
            t node=q.front();
            q.pop();
            for(t nbr:adjlist[node]){
                if(visited[nbr]==true && parent[node]!=nbr){
                    return true;
                }
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr]=node;
                    visited[nbr]=true;
                }
            }
        }
         return false;
    }
};

int main(){

    graph<int> g;
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(2, 4);
    g.addedge(4, 1);
    g.addedge(2, 5);
    
    if(g.iscyclicbfs(1)){
        cout<<"cycle is present";
    }
    else{
        cout<<"cycle ain't present";
    }

    return 0;
}


