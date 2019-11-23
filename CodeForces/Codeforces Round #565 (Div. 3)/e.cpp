#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, m;
vector<int> d;
vector<vector<int>> g;

void bfs(int s) {
	d = vector<int>(n, INF);
	d[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (auto x : g[v]) {
				if (d[x] == INF) {
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int case_num = 0; case_num < t; ++case_num) {

		cin >> n >> m;

		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);

		}

		// begin bfs at 0
		bfs(0);

		vector<int> even, odd;

		for (int i = 0; i < n; ++i) {
			if (d[i] % 2 == 0) even.push_back(i);
			else odd.push_back(i);
		}

		if (even.size() < odd.size()) {
			cout << even.size() << "\n";
			for (auto x : even) cout << x + 1 << " ";
		}
		else {
			cout << odd.size() << "\n";
			for (auto x : odd) cout << x + 1 << " ";
		}
		cout << "\n";

	}


	return 0;
}
