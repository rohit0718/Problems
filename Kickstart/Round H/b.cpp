#include <iostream>

using namespace std;

int N, l[10005], r[10005];

void dp(int arr[], int sum , int MX, int ans) {
    if (!sum) {
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < MX; ++i) {
        if (!l[i]) continue;
        int tmp = i;
        while (1) {
            if (arr[tmp]) arr[tmp] = 0, sum--;
            else arr[tmp] = 1, sum++;
            if (r[tmp]) break;
            tmp -= N - 1;
        }
        dp(arr, sum, MX, ans + 1);
        while (1) {
            if (arr[tmp]) arr[tmp] = 0, sum--;
            else arr[tmp] = 1, sum++;
            if (l[tmp]) break;
            tmp += N - 1;
        }
    }
    for (int i = 0; i < MX; ++i) {
        if (!r[i]) continue;
        int tmp = i;
        while (1) {
            if (arr[tmp]) arr[tmp] = 0, sum--;
            else arr[tmp] = 1, sum++;
            if (l[tmp]) break;
            tmp += N - 1;
        }
        dp(arr, sum, MX, ans + 1);
        while (1) {
            if (arr[tmp]) arr[tmp] = 0, sum--;
            else arr[tmp] = 1, sum++;
            if (r[tmp]) break;
            tmp -= N - 1;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cout << "Case #" << cs << ": ";  
        cin >> N;
        int MX = N * N;
        int arr[10005] = { 0 };
        for (int i = 0; i < 10005; ++i) r[i] = 0, l[i] = 0;
        int sum = 0;
        for (int i = 0; i < MX; ++i) {
            char c; cin >> c;
            if (c == '.') continue;
            else arr[i] = 1, sum++;
        }
        dp(arr, sum, MX, 0);
        cout << "\n";
    }


    return 0;
}
