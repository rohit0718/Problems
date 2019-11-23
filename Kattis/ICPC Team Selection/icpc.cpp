#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int N;
		cin >> N;
		vector<int> arr(3*N);
		for (auto &x : arr) {
			cin >> x;
		}
		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 3 * N - 2; i >= N; i = i - 2) {
			ans += arr[i];
		}

		cout << ans << "\n";
	}
}