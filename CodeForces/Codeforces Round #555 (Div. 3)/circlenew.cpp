#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MX = 1e6;
int arr[MX];
vector<int> solution;
map<int, int> m;

int main() {

	int n, count;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i], m[arr[i]]++;

	// finding the largest substring
	for (int i = 0; i < MX; ++i) {

		if (m[i] == 0) continue;
		int ptr = i;
		int origin = i;
		vector<int> tmp;
		while (m[ptr] != 0) {
			tmp.push_back(ptr), m[ptr]--;
			ptr++;
			if (m[ptr] == 0 || m[ptr] == 1) {
				if (m[ptr] == 1) tmp.push_back(ptr);
				ptr--;
				while (ptr >= origin) {
					while (m[ptr] > 0) tmp.push_back(ptr), m[ptr]--;
					ptr--;
				}
				break;
			}
		}
	
		if (tmp.size() > solution.size()) solution = tmp;

	}

	cout << solution.size() << "\n";
	for (auto &s : solution) cout << s << " ";

	return 0;
}