#include <iostream>
#include <set>

using namespace std;

const int MX = 1e6;

int a[MX];

int main() {

	
	multiset<int> mset;

	int n;
	cin >> n;

	int tmp;

	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> tmp, mset.insert(tmp);
	

	for (int i = 0; i < n; ++i) {

		int num = (n - a[i]) % n;
		auto it = mset.lower_bound(num);
		if (it == mset.end()) it = mset.begin();
		cout << (a[i] + *it) % n << " ";
		mset.erase(it);

	}


	return 0;
	
}