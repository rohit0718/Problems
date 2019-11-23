#include <iostream>

using namespace std;

const int mod = 1000000007;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    long long len[100005] = { 0 };
    len[1] = 2; len[2] = 4;
    for (int i = 3; i <= 100000; ++i)
        len[i] = len[i - 1] + len[i - 2] % mod;
    cout << 1LL * (len[n] + len[m] - 2) % mod;
    
    return 0;
}
