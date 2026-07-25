#include <bits/stdc++.h>
using namespace std;

namespace range {

    template<class R, class T>
    size_t count(const R& r, const T& value) {
        return std::count(r.begin(), r.end(), value);
    }

    template<class R, class Comp, class Proj>
    void sort(R& r, Comp comp, Proj proj) {
        std::sort(r.begin(), r.end(),
            [&](const auto& a, const auto& b) {
                return comp(proj(a), proj(b));
            }
        );
    }

    template<class R>
    void sort(R& r) {
        std::sort(r.begin(), r.end());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned T;
    cin >> T;

    while (T--) {
        unsigned N;
        cin >> N;
        vector<long> A(N);
        for (auto& a : A) cin >> a;

        if (range::count(A, A[0]) == N) {
            cout << "Yes\n";
            continue;
        }

        const auto p_cnt = range::count(A, A[0]);
        const auto n_cnt = range::count(A, -A[0]);
        if (p_cnt + n_cnt == N && min(p_cnt, n_cnt) == N / 2) {
            cout << "Yes\n";
            continue;
        }

        range::sort(A, greater<long>{}, [](long a){ return abs(a); });

        bool ok = true;
        for (unsigned i = 0; i + 2 < N; ++i) {
            if (A[i] * A[i + 2] != A[i + 1] * A[i + 1]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}
