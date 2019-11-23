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
		pq.push({ arr[i], i });
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


		// check left side
		int mv = 1;
		while (mv <= k && x.second - mv >= 0) {
			while (res[x.second - mv] != -1 && x.second - mv >= 0) {
				mv++;
			}
			if (x.second - mv == -1) break;
			res[x.second - mv] = team;
			mv++;
			taken++;
		}

		// check right side
		mv = 1;
		while (mv <= k && x.second + mv < n) {

			while (res[x.second + mv] != -1 && x.second + mv < n) {
				mv++;
			}
			if (x.second + mv == n) break;
			res[x.second + mv] = team;
			mv++;
			taken++;
		}

		team ^= 1;
	}

	for (int x : res) cout << (x + 1);
	cout << "\n";

}