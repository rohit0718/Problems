#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;
vector<iii> V;
int heights[10005] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		y++;
		V.push_back(make_tuple(x, y, z));

	}

	sort(V.begin(), V.end());

	int ans = 0;
	for (int i = 0; i < N; ++i) {

		ans += get<0>(V[i]) - heights[get<1>(V[i])];
		ans += get<0>(V[i]) - heights[get<2>(V[i])];

		for (int j = get<1>(V[i]); j <= get<2>(V[i]); ++j) {
			heights[j] = get<0>(V[i]);
		}
	}

	cout << ans;

	return 0;
}