#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        long long x1, y1, r1, x2, y2, r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long dx = x1 - x2, dy = y1 - y2;
        long long dist = dx * dx + dy * dy;

        if((r1 - r2) * (r1 - r2) <= dist && dist <= (r1 + r2) * (r1 + r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}