class DSU {
public:
	int rank, parent;
	DSU() {}
	DSU(int p) {
		rank = 0, parent = p;
	}
};
int Find(vector<DSU> &dsu, int x) {
	if (dsu[x].parent == x) {
		return x;
	}
	dsu[x].parent = Find(dsu, dsu[x].parent);
	return dsu[x].parent;
}
void Union(vector<DSU> &dsu, int x, int y) {
	int u = Find(dsu, x), v = Find(dsu, y);
	if (u != v) {
		if (dsu[u].rank > dsu[v].rank) {
			dsu[v].parent = u;
		}
		else if (dsu[u].rank < dsu[v].rank) {
			dsu[u].parent = v;
		}
		else {
			dsu[v].parent = u;
			dsu[u].rank++;
		}
	}
}
class edge {
public:
	int u, v;
	int wt;
	edge() {}
	edge(int a, int b, int c) {
		u = a, v = b, wt = c;
	}
};
bool cmp(edge a, edge b) {
	return a.wt <= b.wt;
}
int kruskals(int m, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
	int n = g_from.size();
	vector<edge>e(n);
	for (int i = 0; i < n; i++) {
		e[i] = edge(g_from[i], g_to[i], g_weight[i]);
	}

	sort(e.begin(), e.end(), cmp);

	vector<DSU>dsu(m + 1);
	for (int i = 0; i <= m; i++) {
		dsu[i] = DSU(i);
	}

	int cnt = 0;
	int min_weight = 0;
	for (int i = 0; i < n; i++) {

		if (cnt == m - 1) {
			break;
		}
		int u = Find(dsu, e[i].u), v = Find(dsu, e[i].v);
		if (u != v) {
			Union(dsu, u, v);
			min_weight += e[i].wt;
			cnt++;
		}
	}
	return min_weight;
}