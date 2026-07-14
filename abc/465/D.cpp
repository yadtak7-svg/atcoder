#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int depth(int64 x, int64 K){
    int d = 0;
    while(x){
        x /= K;
        d++;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int64 X, Y, K;
        cin >> X >> Y >> K;

        long long ans = 0;

        while(X != Y){
            int dx = depth(X, K);
            int dy = depth(Y, K);

            if(dx > dy){
                X /= K;
                ans++;
            }
            else if(dx < dy){
                Y /= K;
                ans++;
            }
            else{
                X /= K;
                Y /= K;
                ans += 2;
            }
        }

        cout << ans << '\n';
    }
}