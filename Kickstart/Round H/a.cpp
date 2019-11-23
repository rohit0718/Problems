#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int arr[100005] = { 0 };
        int N; cin >> N;
        if (cs > 1) cout << "\n";
        cout << "Case #" << cs << ": ";
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            int x; cin >> x;
            arr[x]++;
            int tmp = min(arr[x], x);
            if (tmp > ans) ans = tmp;
            else if (x > ans) arr[ans]++, ans = min(ans, arr[ans]);
            cout << ans << " ";
        }
    }


    return 0;
}
