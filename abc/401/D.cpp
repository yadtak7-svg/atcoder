#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int co = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            co++;
        }
    }

    if (co == k) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = '.';
            }
        }
        cout << s << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i+1 < n && s[i] == '?' && s[i+1] == 'o') {
            s[i] = '.';
        }
        if (0 <= i-1 && s[i-1] == 'o' && s[i] == '?') {
            s[i] = '.';
        }
    }

    vector<tuple<int, int>> memo;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && s[j] == '?') {
            j++;
        }
        if (s[i] == '?') {
            memo.push_back({i, j-1});
            i = j-1;
        } else {
            j++;
        }
    }

    int cmax = 0;
    for (int i = 0; i < (int)memo.size(); i++) {
        int l = get<0>(memo[i]);
        int r = get<1>(memo[i]);

        cmax += (r-l+1+2-1)/2;
    }

    if (cmax == k-co) {
        for (auto item: memo) {
            int l = get<0>(item);
            int r = get<1>(item);

            if ((r-l+1)&1) {
                for (int i = l; i <= r; i++) {
                    if ((i-l+1)&1) {
                        s[i] = 'o';
                    } else {
                        s[i] = '.';
                    }
                }
            }
        }
        cout << s << endl;
    } else {
        cout << s << endl;
    }
    
    return 0;
}