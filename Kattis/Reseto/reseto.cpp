#include <iostream>
#include <set>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	set<int> s;

	for (int i = 2; i <= N; ++i) s.insert(i);

	while (true) {
		auto it = s.begin();
		int x = *it;
		for (int i = 1; i <= N / x; ++i) {
			if (s.find(x * i) != s.end()) {
				s.erase(s.find(x * i));
				K--;
			}
			if (K == 0) {
				cout << x * i << "\n"; 
				return 0;
			}
		}
	}

	return 0;
}