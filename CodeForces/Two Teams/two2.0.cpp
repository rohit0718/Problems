#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	priority_queue<ii> pq;
	vector<int> res(n, -1);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push({arr[i], i});
	}

	vector<int> prev(n);
	for (int i = 0; i < n; i++) {
		prev[i] = i - 1;
	}
	vector<int> next(n);
	for (int i = 0; i < n; i++) {
		next[i] = i + 1;
	}
	int taken = 0;
	int team = 0;

	while (taken < n) {

		ii x = pq.top();

		while (res[x.second] != -1) {
			pq.pop();
			x = pq.top();
		}

		res[x.second] = team;
		taken++;

		int i = prev[x.second];
		int j = next[x.second];


		// check left side
		int mv = 0;
		while (mv < k && i > -1 && res[i] == -1) {
			res[i] = team;
			mv++;
			taken++;
			i = prev[i];
		}



		// check right side
		mv = 0;
		while (mv < k && j < n && res[j] == -1) {
			res[j] = team;
			mv++;
			taken++;
			j = next[j];
		}

		if (i >= 0) next[i] = j;
		if (j <= n) prev[j] = i;
		
		team ^= 1;
	}

	for (int x : res) cout << (x + 1);
	cout << "\n";

}