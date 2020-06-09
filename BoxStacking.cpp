#include<bits/stdc++.h>
#define fl(i,a,n)      for(int i=a;i<=n;i++)
#define w(x)           int x; cin>>x; while(x--)
using namespace std;
void IO_FILE() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class mypair {
public:
    int l, w, h;
};
bool cmp(mypair a, mypair b) {
    return a.w * a.l > b.w * b.l;
}
void print0(mypair p) {
    cout << p.h << " " << p.w << " " << p.l << endl;
}
int maxHeight(int height[], int width[], int length[], int n)
{
    vector<mypair>v(3 * n);
    for (int i = 0; i < n; i++) {
        mypair p;
        p.h = height[i];
        p.l = max(width[i], length[i]);
        p.w = min(width[i], length[i]);
        v[i] = p;

        p.h = width[i];
        p.l = max(height[i], length[i]);
        p.w = min(height[i], length[i]);
        v[i + n] = p;

        p.h = length[i];
        p.l = max(height[i], width[i]);
        p.w = min(height[i], width [i]);
        v[i + 2 * n] = p;
    }
    sort(v.begin(), v.end(), cmp);
    n = 3 * n;
    int dp[n + 2];
    dp[0] = v[0].h;
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        int ht = v[i].h ;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i].w < v[j].w and v[i].l < v[j].l) {
                ht = max(ht, v[i].h + dp[j]);
            }
        }
        dp[i] = ht;
        ans = max(ans, ht);
    }
    return ans;
    //return 0;
}
inline void solve() {
    int n; cin >> n;
    int height[n], width[n], length[n];
    fl(i, 0, n - 1) {
        cin >> height[i];
        cin >> width[i];
        cin >> length[i];
    }
    cout << maxHeight(height, width, length, n) << endl;
}
int32_t main() {
    IO_FILE();
    w(t)
    {
        solve();
    }

    return 0;
}

