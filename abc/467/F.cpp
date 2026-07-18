#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG = LLONG_MIN / 2;

int treeSize;      // 2のべき乗にパディングした葉の数
int numVals;        // 実際のdistinct B値の数
vector<ll> sumTree, bestTree, vals;

void updateLeaf(int pos) {
    int i = treeSize + pos;
    ll s = sumTree[i];
    bestTree[i] = (s > 0) ? s + vals[pos] : NEG;
}

void pointAdd(int pos, ll delta) {
    int i = treeSize + pos;
    sumTree[i] += delta;
    updateLeaf(pos);
    i /= 2;
    while (i >= 1) {
        ll rs = sumTree[2*i+1];
        ll lb = bestTree[2*i], rb = bestTree[2*i+1];
        sumTree[i] = sumTree[2*i] + rs;
        ll cand = (lb == NEG) ? NEG : lb + rs;
        bestTree[i] = max(cand, rb);
        i /= 2;
    }
}

int main(){
    int n, q; cin >> n >> q;
    vector<ll> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];

    vector<int> qt(q), qi(q);
    vector<ll> qx(q);
    vector<ll> allVals;
    for (int i = 1; i <= n; i++) allVals.push_back(B[i]);
    for (int k = 0; k < q; k++){
        int t, i; ll x;
        cin >> t >> i >> x;
        qt[k] = t; qi[k] = i; qx[k] = x;
        if (t == 2) allVals.push_back(x);
    }

    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());
    vals = allVals;
    numVals = (int)vals.size();

    // ★ 2のべき乗にパディング(ここが修正点)
    treeSize = 1;
    while (treeSize < numVals) treeSize <<= 1;

    sumTree.assign(2 * treeSize, 0);
    bestTree.assign(2 * treeSize, NEG);
    // パディング分の葉は sum=0 のままなので明示的な初期化は不要
    // (未タッチのノードは (sum=0, best=NEG) がそのまま正しい単位元になる)

    auto idxOf = [&](ll v)->int{
        return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin());
    };

    vector<int> curBidx(n + 1);
    for (int i = 1; i <= n; i++){
        curBidx[i] = idxOf(B[i]);
        pointAdd(curBidx[i], A[i]);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int k = 0; k < q; k++){
        int t = qt[k], i = qi[k]; ll x = qx[k];
        if (t == 1){
            ll delta = x - A[i];
            pointAdd(curBidx[i], delta);
            A[i] = x;
        } else {
            pointAdd(curBidx[i], -A[i]);
            int nb = idxOf(x);
            curBidx[i] = nb;
            pointAdd(nb, A[i]);
            B[i] = x;
        }
        cout << to_string(bestTree[1]) << endl;
    }
    return 0;
}