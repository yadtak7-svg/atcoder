#include <bits/stdc++.h>
using namespace std;

struct Data {
    string s;
    int len;
    int lz;
    int efflen;
    int id;
};

bool concat_cmp(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Data> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].s;

        A[i].len = A[i].s.size();
        A[i].id = i;

        A[i].lz = 0;
        while (A[i].lz < A[i].len &&
               A[i].s[A[i].lz] == '0') {
            A[i].lz++;
        }

        A[i].efflen = A[i].len - A[i].lz;
    }

    vector<int> order(N);

    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(),
        [&](int i, int j) {
            if (A[i].len != A[j].len) {
                return A[i].len > A[j].len;
            }
            return A[i].s > A[j].s;
        }
    );

    vector<long long> prefix(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] =
            prefix[i] + A[order[i]].len;
    }

    long long sumTopK = prefix[K];

    int boundary_length =
        A[order[K - 1]].len;

    const long long NEG_INF = -(1LL << 60);

    long long g1_min_lz = (1LL << 60);

    for (int i = 0; i < N; i++) {
        if (A[i].len > boundary_length) {
            g1_min_lz =
                min(g1_min_lz,
                    (long long)A[i].lz);
        }
    }

    long long g1 = NEG_INF;

    if (g1_min_lz != (1LL << 60)) {
        g1 = sumTopK - g1_min_lz;
    }

    int best_efflen = -1;
    int best_i_star = -1;

    for (int i = 0; i < N; i++) {

        if (A[i].len > boundary_length)
            continue;

        if (A[i].efflen > best_efflen) {

            best_efflen = A[i].efflen;
            best_i_star = i;

        } else if (A[i].efflen == best_efflen &&
                   best_i_star != -1) {

            string s1 = A[i].s;
            string s2 = A[best_i_star].s;

            int p1 = 0;
            while (p1 < (int)s1.size() &&
                   s1[p1] == '0') {
                p1++;
            }

            int p2 = 0;
            while (p2 < (int)s2.size() &&
                   s2[p2] == '0') {
                p2++;
            }

            string t1 = s1.substr(p1);
            string t2 = s2.substr(p2);

            if (t1 > t2) {
                best_i_star = i;
            }
        }
    }

    long long g2 =
        sumTopK - boundary_length + best_efflen;

    vector<int> topK_indices;

    for (int i = 0; i < K; i++) {
        topK_indices.push_back(order[i]);
    }

    vector<bool> topK_set(N, false);

    for (int x : topK_indices) {
        topK_set[x] = true;
    }

    auto build_value = [&](const vector<int>& T) {

        vector<string> strs;

        for (int i : T) {
            strs.push_back(A[i].s);
        }

        sort(strs.begin(), strs.end(),
            concat_cmp);

        string res;

        for (const string& s : strs) {
            res += s;
        }

        int p = 0;

        while (p + 1 < (int)res.size() &&
               res[p] == '0') {
            p++;
        }

        res = res.substr(p);

        if (res.empty()) {
            return string("0");
        }

        return res;
    };

    
    vector<vector<int>> candidates;

    candidates.push_back(topK_indices);

    if (best_i_star != -1 &&
        !topK_set[best_i_star]) {

        vector<int> v;

        for (int i = 0; i < K - 1; i++) {
            v.push_back(topK_indices[i]);
        }

        v.push_back(best_i_star);

        candidates.push_back(v);
    }

    string best_result = "";

    for (const auto& T : candidates) {

        string val = build_value(T);

        if (best_result.empty()) {
            best_result = val;
        }
        else if (val.size() != best_result.size()) {

            if (val.size() > best_result.size()) {
                best_result = val;
            }

        }
        else {

            if (val > best_result) {
                best_result = val;
            }
        }
    }

    cout << best_result << '\n';

    return 0;
}