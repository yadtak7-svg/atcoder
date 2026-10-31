#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

int half(const Point& p) {
    return (p.y > 0 || (p.y == 0 && p.x > 0)) ? 0 : 1;
}

bool cmp(const Point& a, const Point& b) {
    if (half(a) != half(b)) {
        return half(a) < half(b);
    }
    return cross(a, b) > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Point> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i].x >> A[i].y;
        }

        sort(A.begin(), A.end(), cmp);

        vector<Point> B = A;
        for (int i = 0; i < n; i++) {
            B.push_back(A[i]);
        }

        int ans = 0;
        int r = 1;

        for (int l = 0; l < n; l++) {
            r = max(r, l + 1);

            while (r < l + n &&
                   cross(B[l], B[r]) > 0) {
                r++;
            }

            ans = max(ans, r - l);
        }

        cout << ans << '\n';
    }
}