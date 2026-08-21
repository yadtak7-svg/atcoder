#include <bits/stdc++.h>
using namespace std;

vector<long long> A;
int n; 

void gen(long long k, int i) {
    if(i == n) A.push_back(k);
    else {
        long long a = k / 2;
        long long b = k - a;

        gen(a, i + 1);
        gen(b, i + 1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long k; cin >> n >> k;
    gen(k, 0);

    long long MIN = 1e18, MAX = 0; 
    for(long long x : A) {
        MAX = max(MAX, x);
        MIN = min(MIN, x);
    }

    cout << MAX - MIN << '\n';
    for(long long x : A) {
        cout << x << ' ';
    }
    cout << '\n';
}