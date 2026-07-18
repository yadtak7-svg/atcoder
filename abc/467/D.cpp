#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

i128 cross(ll ax, ll ay, ll bx, ll by) {
    return (i128)ax * by - (i128)ay * bx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        ll vx1 = qx - px;
        ll vy1 = qy - py;
        ll vx2 = sx - rx;
        ll vy2 = sy - ry;

        bool ok = false;

        if (cross(vx1, vy1, vx2, vy2) != 0) {
            ok = true;
        } else {
            ll dx = (rx + sx) - (px + qx);
            ll dy = (ry + sy) - (py + qy);

            ll wx = -vy1;
            ll wy = vx1;

            if (cross(wx, wy, dx, dy) == 0)
                ok = true;
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}