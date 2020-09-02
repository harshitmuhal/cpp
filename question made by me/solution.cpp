#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int>prime_no;
void psieve() {
    int n = 1000001;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            prime_no[p]++;
        }
    }
}
bool ans = 1;
void DFS(int src, unordered_map<int, int>&vis, int sum, int label[], vector<int>v[]) {
    vis[src] = 1;
    sum += label[src];
    if (v[src].size() == 0) {
        ans = ans && prime_no.count(abs(sum));
        sum -= label[src];
        return;
    }
    for (auto x : v[src]) {
        if (!vis[x])
            DFS(x, vis, sum, label, v);
    }
    sum -= label[src];
}
int main() {
    int t;
    cin >> t;
    psieve();
    while (t--) {
        ans = 1;
        int n;
        cin >> n;
        vector<int>v[n + 1];
        int m = n - 1;
        while (m--) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        int label[n];
        for (int i = 0; i < n; i++) {
            cin >> label[i];
        }
        unordered_map<int, int>vis;
        DFS(0, vis, 0, label, v);
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}