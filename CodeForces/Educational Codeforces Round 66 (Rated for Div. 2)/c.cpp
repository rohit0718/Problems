#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {

		vector<ll> v;
		int n, k;
		cin >> n >> k;

		for (int j = 0; j < n; ++j) {
			ll x;
			cin >> x;
			v.push_back(x);
		}

		ll ans = 0;
		ll min_diff = 3e9;
		for (int j = 0; j + k < n; ++j) {
			int l = v[j];
			int r = v[j + k];
			int mid = (v[j] + v[j + k]) / 2;
			if ((max((mid - l), (r - mid))) < min_diff) {
				ans = mid;
				min_diff = max((mid - l), (r - mid));
			}
		}

		cout << ans << endl;
		// iterate over trhe vector and cout the min value

	}


	return 0;
}