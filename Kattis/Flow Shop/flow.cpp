#include <iostream>

using namespace std;

int swathers[1005][1005];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
		
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> swathers[i][j];
	
	for (int i = 0; i < M - 1; ++i) swathers[0][i + 1] += swathers[0][i];
	
	for (int i = 0; i < N - 1; ++i) swathers[i + 1][0] += swathers[i][0];
	
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			if (swathers[i - 1][j] > swathers[i][j - 1]) swathers[i][j] += swathers[i - 1][j];
			else swathers[i][j] += swathers[i][j - 1];
		}	
	}
	

	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << swathers[i][M - 1];
	}

	cout << "\n";
	return 0;

}