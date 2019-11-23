#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int biggest_pos = 0;
int biggest_pos_val = 0;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x >= 0) x = -x - 1;
		if (x < biggest_pos_val) biggest_pos = i, biggest_pos_val = x;
		v.push_back(x);
	}

	if ((N % 2 != 0) || N == 1) {
		v[biggest_pos] = - v[biggest_pos] - 1;
	}

	

	for (int i = 0; i < N; ++i) {
		cout << v[i] << " ";
	}

	return 0;
}