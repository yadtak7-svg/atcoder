#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long q;
    cin >> n >> q;

   
    int L = 1;
    while ((1LL << L) <= (q + 2)) L++;
    L += 1; 

   
    vector<vector<char>> cntParity(L);
    for (int p = 0; p < L; p++) cntParity[p].assign((size_t)1 << (p + 1), 0);

    vector<char> active(n + 1, 0);
    vector<long long> Bval(n + 1, 0);
    unordered_map<long long, unordered_set<int>> bucket; 

    auto toggleB = [&](long long B){
        for (int p = 0; p < L; p++){
            long long mod = 1LL << (p + 1);
            cntParity[p][B % mod] ^= 1;
        }
    };

    long long total = 0;
    long long time_ = 0;

    string result;
    result.reserve((size_t)q * 7);

    for (long long i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 1){
            int x; cin >> x;
            if (!active[x]){
                long long B = time_ + 1;
                active[x] = 1;
                Bval[x] = B;
                bucket[B].insert(x);
                toggleB(B);
                total ^= (B - time_);
            } else {
                long long oldB = Bval[x];
                bucket[oldB].erase(x);
                if (bucket[oldB].empty()) bucket.erase(oldB);
                toggleB(oldB);
                total ^= (oldB - time_);

                long long newB = oldB + 1;
                Bval[x] = newB;
                bucket[newB].insert(x);
                toggleB(newB);
                total ^= (newB - time_);
            }
        } else {
            long long C = 0;
            for (int p = 0; p < L; p++){
                long long mod = 1LL << (p + 1);
                long long r = (time_ + (1LL << p)) % mod;
                if (cntParity[p][r]) C ^= (mod - 1);
            }
            total ^= C;

            time_++;
            auto it = bucket.find(time_);
            if (it != bucket.end()){
                for (int x : it->second){
                    active[x] = 0;
                    toggleB(time_); 
                }
                bucket.erase(it);
            }
        }
        result += to_string(total);
        result += '\n';
    }

    cout << result;
    return 0;
}