#include <iostream>
#include <vector>


using namespace std;

typedef pair<int, int> ii;
const int MX = 1e6;
int arr[MX];
int pos[MX];
vector<ii> sol;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i], arr[i]--;

	// sorting the left and the right halves

	int l = 0;
	int r = n - 1;
	while (l < n / 2) {

		while (arr[l] < n / 2) l++;
		while (arr[r] >= n / 2) r--;

		if (l > r) break;

		if (r - l < n / 2) {
			// execute 'tedious' operation
			sol.push_back({ l, n - 1 });
			sol.push_back({ 0, n - 1 });
			sol.push_back({ 0, r });
			sol.push_back({ 0, n - 1 });
			sol.push_back({ l, n - 1 });
			swap(arr[l], arr[r]);
		}
		else {
			sol.push_back({ l, r });
			swap(arr[l], arr[r]);
		}

		l++;
		r--;

	}

	for (int i = 0; i < n; ++i) pos[arr[i]] = i;

	// make swaps wihtin the left and right halves

	for (int i = 0; i < n; ++i) {

		if (arr[i] == i) continue;
		else if (i < n / 2) {
			int ptr = pos[i];
			sol.push_back({ i, n - 1 });
			sol.push_back({ ptr, n - 1 });
			sol.push_back({ i, n - 1 });
			swap(arr[i], arr[ptr]);
			pos[arr[i]] = i;
			pos[arr[ptr]] = ptr;
		}
		else {
			int ptr = pos[i];
			sol.push_back({ 0, i });
			sol.push_back({ 0, ptr });
			sol.push_back({ 0, i });
			swap(arr[i], arr[ptr]);
			pos[arr[i]] = i;
			pos[arr[ptr]] = ptr;
		}

	}
	
	cout << sol.size() << "\n";
	for (auto &s : sol) cout << s.first + 1 << " " << s.second + 1 << "\n";

	return 0;

}