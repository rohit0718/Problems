#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> AB;
vector<int> BC;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		AB.push_back(tmp);
	}
	
	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		BC.push_back(tmp);
	}

	if (k >= n || k >= m) {
		cout << "-1";
		return 0;
	}

	int sol = -1;
	
	for (int i = 0; i < n; ++i) {

		int val = AB[i] + ta;
		int pos = (int)(lower_bound(BC.begin(), BC.end(), val) - BC.begin());
		if (k > i) pos += k - i;
		if (pos >= m) {
			cout << "-1";
			return 0;
		}
		sol = (BC[pos] + tb > sol) ? BC[pos] + tb : sol;
		if (k == i) break;
	}

	cout << sol;

	return 0;

}