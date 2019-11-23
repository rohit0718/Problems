#include <iostream>

using namespace std;

const int MX = 1e6;
int arr[MX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, k;
	cin >> n >> k;
	long long initial_num = n;

	long long first_num = ((2 * n) - (k * k) - k) / (2 * k);
	
	

	if (first_num < 0) {
		cout << "NO";
		return 0;
	}
	

	first_num++;

	for (int i = 0; i < k; ++i) arr[i] = first_num, n -= first_num, first_num++;
	

	int ptr = k - 1;
	while (n > 0) {
		
		if (ptr != 0 && arr[ptr] + 1 > 2 * arr[ptr - 1]) ptr--;
		else if (ptr == 0 && arr[ptr] + 1 == arr[ptr + 1]) ptr = k - 1;
		arr[ptr]++;
		n--;
	}


	for (int i = 0; i < k; ++i) {
		initial_num -= arr[i];
		if (arr[i + 1] == arr[i] || arr[i + 1] > arr[i] * 2 || initial_num < 0) {
			cout << "NO";
			return 0;
		}
	
	}
	

	cout << "YES" << "\n";
	for (int i = 0; i < k; ++i) cout << arr[i] << " ";


	return 0;
}