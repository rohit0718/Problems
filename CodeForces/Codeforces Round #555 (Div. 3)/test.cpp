#include <iostream>

using namespace std;
int n, m;
int a[204][204];
int r[204], c[204];

bool che(int y) {
	int b[204] = { 0 };
	for (int i = 1; i <= m; ++i) {
		if (i <= y)continue;
		else b[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		c[i] = a[1][i] ^ b[i];
	}
	if (b[m] == 1) {
		for (int i = 2; i <= n; ++i) {
			r[i] = 1 ^ a[i][1] ^ c[1];
		}
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!(a[i][j] ^ r[i] ^ c[j]))return 0;
			}
		}
		return 1;
	}
	else {
		bool ok = 0;
		r[1] = 0;
		for (int i = 2; i <= n; ++i) {
			r[i] = a[i][1] ^ c[1];
			if (ok)r[i] ^= 1;
			for (int j = 1; j <= m; ++j) {
				if (!(a[i][j] ^ r[i] ^ c[j]) && ok)return 0;
				else if ((a[i][j] ^ r[i] ^ c[j]))ok = 1;
			}
		}
	}
	return 1;
}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int j = 0; j <= m; ++j) {
		if (che(j)) {
			puts("YES");
			for (int k = 1; k <= n; ++k) {
				printf("%d", r[k]);
			}
			puts("");
			for (int k = 1; k <= m; ++k) {
				printf("%d", c[k]);
			}
			puts("");
			return 0;
		}
	}

	puts("NO");

}