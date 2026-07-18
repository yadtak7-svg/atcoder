#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; ll M;
    scanf("%d %lld", &N, &M);
    vector<ll> A(N+1), B(N); 
    for(int i=1;i<=N;i++) scanf("%lld", &A[i]);
    for(int i=1;i<=N-1;i++) scanf("%lld", &B[i]);

    vector<ll> c(N+1);
    vector<int> s(N+1);
    c[1]=0; s[1]=1;
    for(int i=2;i<=N;i++){
        c[i] = ((B[i-1] - c[i-1]) % M + M) % M;
        s[i] = -s[i-1];
    }

    vector<ll> e(N+1);
    ll F0 = 0;
    ll S = 0;
    for(int i=1;i<=N;i++){
        e[i] = ((c[i] - A[i]) % M + M) % M;
        F0 += e[i];
        S += s[i];
    }

    vector<pair<ll,ll>> events;
    events.reserve(N);
    for(int i=1;i<=N;i++){
        if(s[i]==1){
            if(e[i]!=0){
                ll pos = M - e[i];
                events.push_back({pos, -M});
            }
        } else {
            if(e[i]!=M-1){
                ll pos = e[i] + 1;
                events.push_back({pos, +M});
            }
        }
    }
    sort(events.begin(), events.end());

    ll curT = 0;
    ll curF = F0;
    ll minF = F0;

    size_t idx = 0;
    while(idx < events.size()){
        ll pos = events[idx].first;
        ll gap = pos - curT; 

       
        ll Fend = curF + S * (gap - 1);
        minF = min(minF, min(curF, Fend));

        ll pre = curF + S * gap; 

        ll deltaSum = 0;
        while(idx < events.size() && events[idx].first == pos){
            deltaSum += events[idx].second;
            idx++;
        }

        curF = pre + deltaSum;
        curT = pos;
        minF = min(minF, curF);
    }

    if(curT <= M-1){
        ll gap = (M-1) - curT;
        ll Fend = curF + S * gap;
        minF = min(minF, min(curF, Fend));
    }

    cout << minF << endl;
    return 0;
}