#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, E;
	cin >> N >> E;

	vector<vector<int>> villagers(N + 1);

	int song_num = 1;

	for (int case_num = 0; case_num < E; ++case_num) {
		int K;
		cin >> K;
		vector<int> row(K);

		bool has_one = 0;

		for (int &r : row) {
			cin >> r;
			if (r == 1) has_one = 1;
		}

		if (has_one) {
			for (int &r : row)
				villagers[r].push_back(song_num);
			song_num++;
		}

		else {
			for (int &x : row)
				for (int &y : row)
					if (villagers[y] != villagers[x]) {
						villagers[y].insert(villagers[y].end(), villagers[x].begin(), villagers[x].end());
						sort(villagers[y].begin(), villagers[y].end());
						villagers[y].erase(unique(villagers[y].begin(), villagers[y].end()), villagers[y].end());
					}		

		}	

	}
	   	 
	for (int i = 1; i < N + 1; ++i)
		if (villagers[i] == villagers[1]) cout << i << endl;


	return 0;
}