#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int T, cs = 1; cin >> T;
    while (T--) {
        int arr[100005] = { 0 };
        int n, m, q; cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i) arr[i] = 1;
        for (int i = 0; i < m; ++i) {
            int x; cin >> x;
            arr[x] = 0;
        }
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = i * 2; j <= n; j = j + i) {
                if (arr[j]) arr[i]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < q; ++i) {
            int x; cin >> x;
            ans += arr[x];
        }
        cout << "Case #" << cs++ << ": " << ans << "\n" ;
    }



    return 0;
}
