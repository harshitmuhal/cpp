#include<iostream>
#include<list>
#include<set>
#include<unordered_map>
#include<climits>

using namespace std;

template<typename t>
class graph{
public:
    
    unordered_map<t,list<pair<t,int>> > adjlist;
    
    graph(){
    }
    
    void addedge(t i,t j,t w,bool isbidirectional=true){
        adjlist[i].push_back(make_pair(j,w));
        if(isbidirectional){
            adjlist[j].push_back(make_pair(i,w));
        }
    }
    
    void dijtra(t src){
        unordered_map<t,int> dist;
        for(auto node: adjlist){
            dist[node.first]=INT_MAX;
        }
        
        dist[src]=0;
        set< pair<int,t> > s;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            auto p=*(s.begin());
            int d=p.first;
            t node=p.second;
            s.erase(s.begin());
            for(auto childpair:adjlist[node]){
                if(d+childpair.second<dist[childpair.first]){
                    t dest=childpair.first;
                    auto f= s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=d+childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        
        for(auto d:dist){
            cout<<d.first<<" is at a distance of "<<d.second<<endl;
        }
    }
};



int main(){
    graph<int> g;
    
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(1,4,7);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.dijtra(1);
    return 0;
}
