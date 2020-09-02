#include<bits/stdc++.h>
using namespace std;

#define T_CASE 10
#define T_NODES 10000

void generate(int &n, set<pair<int, int>> &edges, int node) {
    int x = rand() % 3;
    vector<int>v;
    while (x--) {
        v.push_back(n + 1);
        n++;
        edges.insert({node, n});
        if (n == T_NODES) {
            return;
        }
    }
    for (auto x : v) {
        generate(n, edges, x);
        if (n == T_NODES) {
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ofstream myfile;
    myfile.open ("in.txt");

    set<pair<int, int>> edges;
    srand(time(NULL));
    int NUM;
    int T_CASE_ = 1 + rand() % T_CASE;
    myfile << T_CASE_ << endl;
    for (int i = 1; i <= T_CASE_; i++) {
        NUM = 0;
        generate(NUM, edges, 0);
        myfile << ++NUM << endl;
        for (auto it = edges.begin(); it != edges.end(); ++it)
            myfile << it->first << " " << it->second << endl;
        edges.clear();
        for (int i = 0; i < NUM; i++) {
            int negate = rand() % 2;
            int sign = (negate ? -1 : 1);
            myfile << sign*(1 + rand() % 100) << " ";
        }
        myfile << endl;
    }
    return (0);
}