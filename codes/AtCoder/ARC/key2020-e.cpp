/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll U[200010], V[200010];
ll D[100010];
vector<ll> tree[100010];
map<lpair, ll> mp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,N) cin >> D[i];
    rep(i,0,M){
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
        tree[U[i]].push_back(V[i]);
        tree[V[i]].push_back(U[i]);
        mp[{U[i], V[i]}] = i;
        mp[{V[i], U[i]}] = i;
    }
    ll weight[200010] = {};
    rep(i,0,M){
        weight[i] = max(D[U[i]], D[V[i]]);
    }
    vector<lpair> lp;
    rep(i,0,M){
        lp.push_back({weight[i], i});
    }
    ll color[100010] = {};
    sort(lp.begin(), lp.end(), greater<lpair>());
    bool ok = true;
    // printa(weight, M);
    rep(i,0,N){
        ll min_val = INF;
        for(auto &e: tree[i]){
            ll idx = mp[{i, e}];
            min_val = min(min_val, weight[idx]);
        }
        // print(min_val);
        if(min_val != D[i]) ok = false;
    }
    if(not ok){
        print(-1);
        return 0;
    }
    rep(i,0,M){
        ll idx = lp[i].second;
        if(color[U[idx]] == 0 && color[V[idx]] == 0){
            color[U[idx]] = 1;
            color[V[idx]] = 2;
        }else if(color[U[idx]] == 0){
            if(color[V[idx]] == 1){
                color[U[idx]] = 2;
            }else{
                color[U[idx]] = 1;
            }
        }else if(color[V[idx]] == 0){
            if(color[U[idx]] == 1){
                color[V[idx]] = 2;
            }else{
                color[U[idx]] = 1;
            }
        }
    }
    rep(i,0,N){
        if(color[i] == 1){
            cout << 'B';
        }else{
            cout << 'W';
        }
    }
    cout << endl;
    rep(i,0,M) print(weight[i]);





    

}