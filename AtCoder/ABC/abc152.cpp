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
vector<ll> tree[55];
map<ll,ll> vertex;
vector<ll> edge_use[25];

ll power(ll x, ll n){
    if(n == 0) return 1LL;
    ll res = power(x * x, n/2);
    if(n % 2 == 1) res = res * x;
    return res;
}

bool dfs(ll cur, ll par, ll target){
    bool flg = false;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        flg |= dfs(e, cur, target);
    }
    if(cur == target){
        flg = true;
    }
    if(flg) vertex[cur]++;
    return flg;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[55], b[55];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }

    ll M;
    cin >> M;
    ll u[25], v[25];
    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    rep(i,0,M){
        vertex.clear();
        bool res = dfs(u[i], -1, v[i]);
        rep(j,0,N-1){
            if(vertex[a[j]] > 0 && vertex[b[j]] > 0) edge_use[i].push_back(j);
        }
    }


    ll ans = 0;
    rep(bit,1,(1LL<<M)){
        ll cnt = __builtin_popcount(bit);
        ll check[55] = {};
        rep(i,0,M){
            if((bit>>i) & 1){
                for(auto &e: edge_use[i]){
                    check[e] = 1;
                }
            }
        }
        ll check_cnt = 0;
        rep(i,0,N-1){
            if(check[i] > 0) check_cnt++;
        }
        check_cnt = N-1 - check_cnt;
        ll res = power(2, check_cnt);
        if(cnt % 2 == 1){
            ans += res;
        }else{
            ans -= res;
        }
    }
    ans = power(2,N-1) - ans;
    print(ans);

    

}