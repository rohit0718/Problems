#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> V(n);
	for (int &v : V)
		cin >> v;
	sort(V.begin(), V.end(), greater<int>());

	long long ans = 0;
	for (int i = 2; i < n; i = i + 3) {
		ans += V[i];
	}

	cout << ans << "\n";

	return 0;
}