#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{

	list<int> *l; 
	int V;
public:
	Graph(int maxSize){
		V = maxSize;
		l = new list<int>[maxSize];
	}

	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}
	void print(){
		
		for(int i=0;i<V;i++){
			int node = i;

			cout<<"Node "<<node<<"->";
			
			auto neigbours = l[node];
			
			for(auto n:neigbours){
				cout<<n<<",";
			}
			cout<<endl;
		}
	}
	int dfsHelper(int s,bool *visited){
		visited[s] = true;

		int cnt = 1;
		auto neigbours = l[s];
		for(auto n:neigbours){
			if(!visited[n]){
				cnt += dfsHelper(n,visited);
			}
		}
		return cnt;

	}

	int dfs(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){
				int s = dfsHelper(i,visited);
				cout<<s<<endl;

				ans -= (s)*(s-1)/2;

			}
		}
		return ans;
	}
};


int main(){

	Graph g(5);
	/*5 3
0 1
2 3
0 4*/
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);
	//g.print();
	cout<<g.dfs()<<endl;


	return 0;
}