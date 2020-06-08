#include<bits/stdc++.h>
using namespace std;

void c_p_c() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class FenwickTree {
public:
	int n;
	vector<int>v;
	FenwickTree(int n) {
		this->n = n + 1;
		v.resize(n + 1, 0);
	}
	int query(int i, int j) {
		j++;
		int a = 0, b = 0;
		while (i > 0) {
			a += v[i];
			i = i - (i & -i);
		}
		while (j > 0) {
			b += v[j];
			j = j - (j & -j);
		}
		return b - a;
	}
	void update(int idx, int val) {
		idx++;
		while (idx < n) {
			v[idx] += val;
			idx += (idx & -idx);
		}
	}
};

int main() {
	c_p_c();

	int n;
	cin >> n;
	vector<int>v(n);

	FenwickTree ft(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ft.update(i, v[i]);
	}

	int q, type, l, r, idx, value;
	cin >> q;

	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> l >> r;
			cout << ft.query_range(l, r) << endl;
		}
		else {
			cin >> idx >> value;
			ft.update(idx, value);
		}
	}

	return 0;
}






