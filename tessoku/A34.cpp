#include <bits/stdc++.h>
using namespace std;

int mex(int a,int b){ 
    int used[3]={0, 0, 0};
    
    if(a >= 0 && a < 3) used[a] = 1;
    if(b >= 0 && b < 3) used[b] = 1;
   
    for(int i = 0;i < 3; i++){
        if(!used[i]) return i;
    }
    
    return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    if(x < y) swap(x, y);
    vector<int> A(n);
    int Amax = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        Amax = max(Amax, A[i]);
    }

    vector<int> grundy(Amax + 1);
    grundy[0] = 0;
    for(int i = 1; i <= Amax; i++){ 
        int g1 = (i >= x ? grundy[i - x] : -1);
        int g2 = (i >= y ? grundy[i - y] : -1);
        grundy[i] = mex(g1,g2);
    }

    int G = 0;
    for(int i = 0; i < n; i++) G ^= grundy[A[i]];

    if(!G) cout << "Second\n";
    else cout << "First\n";
}