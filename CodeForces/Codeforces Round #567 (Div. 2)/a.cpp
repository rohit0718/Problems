#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long x, y, z;
	cin >> x >> y >> z;

	if (((x + y) / z) <= (x / z) + (y / z)) {
		cout << (x + y) / z << " 0";
	}
	else cout << (x + y) / z << " " << min(z - x % z, z - y % z);

	return 0;
}