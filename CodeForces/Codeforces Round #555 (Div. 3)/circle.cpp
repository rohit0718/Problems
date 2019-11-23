#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main() {
		
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<int, int> map;
	unordered_map<int, int> map_quantity;

	int n;
	cin >> n;
	int tmp;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		map[tmp]++;
		map_quantity[tmp]++;
		if (map[tmp] == 1) {
			if (map[tmp + 1] > 0) map[tmp + 1]++, map[tmp]++;
			if (map[tmp - 1] > 0) map[tmp - 1]++, map[tmp]++;
		}
		else {
			if (map[tmp + 1] > 0) map[tmp + 1]++;
			if (map[tmp - 1] > 0) map[tmp - 1]++;
		}
	}
	
	auto it = max_element
	(map.begin(), map.end(),
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second < p2.second;
	});

	int max = it->first;

	
	

	// if max - 1, max, max + 1 all greater than 0 will be tricky
	if (map_quantity[max - 1] > 0 && map_quantity[max + 1] > 0) {

		// accoiutn for the case whr max and max + 1 are 1
		if (map_quantity[max] == 1 && map_quantity[max + 1] == 1 ||
			map_quantity[max - 1] == 1 && map_quantity[max] == 1 && map_quantity[max + 1] == 1) {
			cout << map_quantity[max - 1] + map_quantity[max] << endl;
			while (map_quantity[max] > 0) cout << max << " ", map_quantity[max]--;
			while (map_quantity[max - 1] > 0) cout << max - 1 << " ", map_quantity[max - 1]--;
		}

		else if (map_quantity[max - 1] == 1 && map_quantity[max] == 1) {
			cout << map_quantity[max] + map_quantity[max + 1] << endl;
			while (map_quantity[max] > 0) cout << max << " ", map_quantity[max]--;
			while (map_quantity[max + 1] > 0) cout << max + 1 << " ", map_quantity[max + 1]--;
		}
		else {

			cout << map_quantity[max - 1] + map_quantity[max] + map_quantity[max + 1] << "\n";
			cout << max + 1 << " ", map_quantity[max + 1]--;
			cout << max << " ", map_quantity[max]--;
			while (map_quantity[max - 1] > 0) cout << max - 1 << " ", map_quantity[max - 1]--;
			while (map_quantity[max] > 0) cout << max << " ", map_quantity[max]--;
			while (map_quantity[max + 1] > 0) cout << max + 1 << " ", map_quantity[max + 1]--;
		}

	}
	// else print the other 2
	else if (map_quantity[max - 1] == 0) {
		cout << map_quantity[max - 1] + map_quantity[max] + map_quantity[max + 1] << "\n";
		while (map_quantity[max] > 0) cout << max << " ", map_quantity[max]--;
		while (map_quantity[max + 1] > 0) cout << max + 1 << " ", map_quantity[max + 1]--;
	}
	else if (map_quantity[max + 1] == 0) {
		cout << map_quantity[max - 1] + map_quantity[max] + map_quantity[max + 1] << "\n";
		while (map_quantity[max] > 0) cout << max << " ", map_quantity[max]--;
		while (map_quantity[max - 1] > 0) cout << max - 1 << " ", map_quantity[max - 1]--;
	}




	return 0;



}