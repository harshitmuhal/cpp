#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename t>
class graph{
public:
    int v;
    map<t,list<t> > adjlist;
    
    graph(){
    }
    
    void addedge(t i,t j,bool isbidirectional=true){
        adjlist[i].push_back(j);
        if(isbidirectional){
            adjlist[j].push_back(i);
        }
    }
};