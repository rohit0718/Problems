#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int min = n;
	map<int, int> V;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		V.insert(pair<int, int>(x, i));
		auto search = V.find(x);
		if (search->second != i) {
			if (min > i - (search->second)) min = i - search->second;
		}
	}
	
	cout << min << "\n";
	return 0;


}