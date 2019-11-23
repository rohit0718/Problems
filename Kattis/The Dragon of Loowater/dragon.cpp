#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	

	while (true) {

		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		vector<int> heads(n);
		for (int &h : heads) cin >> h;
		vector<int> knights(m);
		for (int &k : knights) cin >> k;

		sort(heads.begin(), heads.end(), greater<int>());
		sort(knights.begin(), knights.end());

		int H = n;
		int K = m;
		int ans = 0;

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				if (knights[j] >= heads[i]) {
					H--;
					K--;
					ans += knights[j];
					knights[j] = -1;
					break;
				}
			}

		}

		if (H == 0) cout << ans << "\n";
		else cout << "Loowater is doomed!\n";

	}

	return 0;
}