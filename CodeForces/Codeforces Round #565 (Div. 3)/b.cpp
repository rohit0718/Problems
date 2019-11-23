#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;

		cin >> n;
		int ans0 = 0;
		int ans1 = 0;
		int ans2 = 0;
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp % 3 == 0) ans0++;
			else if (tmp % 3 == 1) ans1++;
			else if (tmp % 3 == 2) ans2++;
				
		}

		ans0 += min(ans1, ans2);

		if (ans1 > ans2) ans0 += (ans1 - ans2) / 3;
		else if (ans2 > ans1) ans0 += (ans2 - ans1) / 3;

		cout << ans0 << endl;

	}



	return 0;
}




if ((s.empty() || s.top() == 42) && tmp == 4) s.push(tmp);
else if (s.top() == 4 && tmp == 8) s.push(tmp);
else if (s.top() == 8 && tmp == 15) s.push(tmp);
else if (s.top() == 15 && tmp == 16) s.push(tmp);
else if (s.top() == 16 && tmp == 23) s.push(tmp);
else if (s.top() == 23 && tmp == 42) {
	s.push(tmp);
	ans++;
}