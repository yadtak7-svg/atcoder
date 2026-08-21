#include <bits/stdc++.h>
using namespace std;

int A[6];
map<pair<int, vector<int>>, long double> memo;

long double f(int rest_turn, vector<int> keep_idxs) {
    if ((int)keep_idxs.size() == 5) {
        map<int,int> cnt;
        for (int idx : keep_idxs) cnt[A[idx]]++;
        int best = 0;
        for (auto &pr : cnt) best = max(best, pr.first * pr.second);
        return (long double)best;
    }

    auto key = make_pair(rest_turn, keep_idxs);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    int rest_dice = 5 - (int)keep_idxs.size();

    long double prob = 1.0L;
    for (int i = 0; i < rest_dice; i++) prob /= 6.0L;

    int total = 1;
    for (int i = 0; i < rest_dice; i++) total *= 6;

    long double ans = 0.0L;

    for (int comb = 0; comb < total; comb++) {
        vector<int> deme_idxs(rest_dice);
        int c = comb;
        for (int i = 0; i < rest_dice; i++) {
            deme_idxs[i] = c % 6;
            c /= 6;
        }

        long double M = 0.0L;
        int maskCount = 1 << rest_dice;

        if (rest_turn == 1) {
            int mask = maskCount - 1;
            vector<int> new_keep = keep_idxs;
            for (int i = 0; i < rest_dice; i++)
                if ((mask >> i) & 1) new_keep.push_back(deme_idxs[i]);
            sort(new_keep.begin(), new_keep.end());
            M = f(rest_turn - 1, new_keep);
        } else {
            for (int mask = 0; mask < maskCount; mask++) {
                vector<int> new_keep = keep_idxs;
                for (int i = 0; i < rest_dice; i++)
                    if ((mask >> i) & 1) new_keep.push_back(deme_idxs[i]);
                sort(new_keep.begin(), new_keep.end());
                long double v = f(rest_turn - 1, new_keep);
                if (v > M) M = v;
            }
        }

        ans += M * prob;
    }

    memo[key] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 6; i++) cin >> A[i];

    vector<int> empty_keep;
    long double res = f(3, empty_keep);

    cout << fixed << setprecision(10) << (double)res << "\n";

    return 0;
}