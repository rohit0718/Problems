#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp == 4) m[0]++;
		else if (tmp == 8 && m[0] > 0) m[1]++, m[0]--;
		else if (tmp == 8 && m[0] == 0) ans++;
		else if (tmp == 15 && m[1] > 0) m[2]++, m[1]--;
		else if (tmp == 15 && m[1] == 0) ans++;
		else if (tmp == 16 && m[2] > 0) m[3]++, m[2]--;
		else if (tmp == 16 && m[2] == 0) ans++;
		else if (tmp == 23 && m[3] > 0) m[4]++, m[3]--;
		else if (tmp == 23 && m[3] == 0) ans++;
		else if (tmp == 42 && m[4] > 0) m[5]++, m[4]--;
		else if (tmp == 42 && m[4] == 0) ans++;

	}


	cout << ans + m[0] + m[1] * 2 + m[2] * 3 + m[3] * 4 + m[4] * 5 << endl;



	return 0;
}