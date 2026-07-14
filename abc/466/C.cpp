#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int r = 2;
    long long ans = 0;

    for (int l = 1; l < N; l++) {
        if (r <= l) r = l + 1;

        while (r <= N) {
            cout << "? " << l << " " << r << endl;

            string res;
            cin >> res;

            if (res == "Yes") {
                r++;
            } else {
                break;
            }
        }

        ans += r - l - 1;
    }

    cout << "! " << ans << endl;

    return 0;
}