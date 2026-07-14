#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string S; cin >> S;

        int l = n - 1;
        for(int i = 0; i + 1 < n; i++) {
            if(S[i] > S[i+1]) {
                l = i;
                break;
            }
        }
        
        int r = n;
        for(int i = l + 1; i < n; i++){
            if(S[i] > S[l]){
                r = i;
                break;
            }
        }

        for(int i = 0; i < l; i++) cout << S[i];
        for(int i = l + 1; i < r; i++) cout << S[i];
        cout << S[l];
        for(int i = r; i < n; i++) cout << S[i];
        cout << endl;
    }
}
