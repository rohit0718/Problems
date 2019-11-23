#include <bits/stdc++.h>

using namespace std;

int n, h, arr[13];
map<int, bool> memo;
vector<int> tmp, v1;

bool check2(int mask) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) sum += arr[i];
        if (sum >= h) return true;
    }
    return false;
}

bool check(int mask) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) sum += arr[i];
        if (sum >= h) return true;
    }
    return false;
}

void solve(int mask) {
    if (memo[mask]) return;

    if (check(mask)) tmp.push_back(mask);

    memo[mask] = true;

    for (int i = 0; i < n; ++i) solve(mask | (1 << i));

}

int main() {

    int T; cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        v1.clear(); tmp.clear(); memo.clear();
        cin >> n >> h;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        solve(0);

        // for each memo in tmp, flip and check
        long long ans = 0;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        if (check(3)) cout << "yes";
        else cout << "no";
        // for (auto x : tmp) {
        //   if (check2(x)) {
        //     cout << "hi";
        //     ans += (1LL << __builtin_popcount(x));
        //     if (!__builtin_popcount(x)) ans--;
        //   }
        // }

        cout << "Case #" << cs << ": " << ans << "\n";

    }

    return 0;
}
