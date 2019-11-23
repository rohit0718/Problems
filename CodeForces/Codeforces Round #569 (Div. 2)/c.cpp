#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
vector<ii> ans;
vector<int> v;
int max_element = -1;
int max_pos = -1;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x > max_element) max_element = x, max_pos = i;
		v.push_back(x);
	}

	for (int i = 0; i < max_pos + n - 1; ++i) {
		ans.push_back(make_pair(v[0], v[1]));
		if (v[0] > v[1]) {
			v.push_back(v[1]);
			v.erase(v.begin() + 1);
		}
		else {
			v.push_back(v[0]);
			v.erase(v.begin());
		}
		
	}

	for (int i = 0; i < q; ++i) {
		unsigned long long int y;
		cin >> y;
		y--;
		if (y <= max_pos) {
			cout << ans[y].first << " " << ans[y].second << endl;
		}
		else {
			unsigned long long int tmp = (y - max_pos) % (n - 1);
			tmp += max_pos;
			cout << ans[tmp].first << " " << ans[tmp].second << endl;
		}


	}

	return 0;
}