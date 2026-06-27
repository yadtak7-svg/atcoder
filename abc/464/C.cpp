#include <bits/stdc++.h>
using namespace std;

struct X{
    int a, d, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<X> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].a >> A[i].d >> A[i].b;
        A[i].a--; A[i].b--; A[i].d--;
    }

    sort(A.begin(), A.end(), [](const X& x, const X& y){
    return x.d < y.d;   
    });

    vector<int> ans(m);
    vector<int> cnt(n, 0);


    for(int i = 0; i < n; i++) {
        int c = (A[i].d == 0 ? A[i].b : A[i].a);
        if(cnt[c] == 0) ans[0]++;
        cnt[c]++;
    }
    int day = 1;
    int top = 0;
    while (top < n && A[top].d == 0) top++;
    while(day < m) {
        int diff = 0;
        while( top < n && day == A[top].d) {
            if(A[top].a != A[top].b) {
                if(cnt[A[top].a] == 1) diff--;
                if(cnt[A[top].b] == 0) diff++;
                
                cnt[A[top].a]--;
                cnt[A[top].b]++;
            }
            top++;
        }
        ans[day] = ans[day - 1] + diff;
        day++;
    }

    for(int x : ans) cout << x << endl;
}