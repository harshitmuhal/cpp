#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class edge {
public:
    int u;
    int v;
    int cost;
};
class set_ {
public:
    int rank;
    int parent;
};
bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}
int find(set_* Set, int i) {
    if(Set[i].parent != i) {
        Set[i].parent = find(Set, Set[i].parent);
    }
    return Set[i].parent;
}
void Union(set_* Set, int x, int y) {
    int u=find(Set,x);
    int v=find(Set,y);
    if(Set[u].rank>Set[v].rank){
        Set[v].parent=u;
    }
    else if(Set[u].rank<Set[v].rank){
        Set[u].parent=v;
    }
    else{ 
        Set[u].parent=v;
        Set[v].rank++;
    }
}
void kruskal(edge* input, int n, int m) {
    edge *output = new edge[n - 1];
    //n-1 because MST will have n-1 edges if given graph has n vertices
    set_* Set = new set_[n];
    for (int i = 0; i < n; i++) {
        Set[i].rank = 0;
        Set[i].parent = i;
    }
    sort(input, input + m, cmp);
    int counter = 0;
    for (int i = 0; i < m; i++) {
        if (counter == n - 1) {
            break;
        }
        int v1_parent = find(Set, input[i].u);
        int v2_parent = find(Set, input[i].v);
        if (v1_parent != v2_parent) {
            Union(Set, v1_parent, v2_parent);
            output[counter] = input[i];
            counter++;
        }
    }
    int totalweight = 0;
    for (int i = 0; i < n - 1; i++) {
        totalweight += output[i].cost;
    }
    cout<< totalweight << endl;
}
int32_t main() {

    int n, m;
    cin >> n >> m;
    edge *Edge = new edge[m];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Edge[i].u = x;
        Edge[i].v = y;
        Edge[i].cost = z;
    }
    kruskal(Edge, n, m);
    return 0;
}

