#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A[] = {1, 2, 3, 4, 5, 6};

    int X, Y;
    cin >> X >> Y;
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(A[i] + A[j] >= X || abs(A[i] - A[j]) >= Y) cnt++;
        }
    }
    double ans = (double)cnt / 36;

    cout << fixed << setprecision(15) << ans << endl;
}
