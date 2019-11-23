#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int ,int> iii;
vector<iii> increasing;
vector<iii> decreasing;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) decreasing.push_back(make_tuple( a, b, i ));
		else increasing.push_back(make_tuple(a, b, i));
	}

	sort(decreasing.begin(), decreasing.end());
	sort(increasing.begin(), increasing.end(), greater<iii>());

	if (increasing.size() > decreasing.size()) {
		cout << increasing.size() << "\n";
		for (int i = 0; i < increasing.size(); ++i) {
			cout << get<2>(increasing[i]) << " ";
		}
	}
	else {
		cout << decreasing.size() << "\n";
		for (int i = 0; i < decreasing.size(); ++i) {
			cout << get<2>(decreasing[i]) << " ";
		}
	}

	return 0;

}