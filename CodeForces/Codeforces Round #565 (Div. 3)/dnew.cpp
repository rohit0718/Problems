#include <iostream>
#include <vector>
#include <map>

using namespace std;

int arr[2750135] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> p{ 0 };
	map<int, int, greater<int>> a;
	vector<int> ans;

	int n;
	cin >> n;

	
	// prime sieve 
	for (int i = 2; i < 2750135; ++i) {

		int ptr = 2;
		while (i * ptr <= 2750135) {
			arr[i * ptr] = 1;
			ptr++;
		}
		if (arr[i] != 0) {
			ptr = 2;
			while (i % ptr != 0) ptr++;
			arr[i] = i / ptr;
		}
		else if (arr[i] == 0) p.push_back(i);

	}

	for (int i = 0; i < 2 * n; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}


	for (int i = 2750131; i >= 2; --i) {
		if (a[i] == 0) continue;
		else {
			while (a[i] > 0) {
				if (arr[i] != 0 && a[arr[i]] > 0) 
					ans.push_back(i), a[i]--, a[arr[i]]--;
				else if (arr[i] == 0 && i <= 199999 && a[p[i]] > 0) 
					ans.push_back(i), a[i]--, a[p[i]]--;
				else break;
			}
		}
	}


	for (auto &x : ans) {
		cout << x << " ";
	}

	return 0;
}