/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
const int M = 61;
// https://atcoder.jp/contests/abc141/submissions/19236387
void GaussJordan(vector<bitset<M> > &bit, ll N){
    vector<bool> use(N+1, false);
    rrep(k,M-1,0){
        ll pivot = -1;
        rep(i,0,N){
            if(use[i]) continue;
            if(bit[i][k] == 1){
                pivot = i;
                break;
            }
        }
        if(pivot == -1) continue;
        rep(i,0,N){
            if(i == pivot) continue;
            if(bit[i][k] == 1){
                bit[i] ^= bit[pivot];
            }
        }
        use[pivot] = true;
    }
}

void solve(){
    ll N;
    cin >> N;
    vll a(N);
    rep(i,0,N) cin >> a[i];
    ll ans = 0;
    vector<bitset<M> > bit(N, bitset<M>(0));

    rep(k,0,M){
        ll cnt = 0;
        rep(i,0,N){
            if(a[i] & (1LL<<k)) cnt++;
        }
        if(cnt % 2 == 1){
            ans += (1LL<<k);
        }else{
            rep(i,0,N){
                if(a[i] & (1LL<<k)) bit[i][k] = 1;
            }
        }
    }

    GaussJordan(bit, N);
    ll res = 0;
    rep(k,0,M){
        ll cnt = 0;
        rep(i,0,N){
            if(bit[i][k]) cnt++;
        }
        if(cnt % 2 == 1) res += (1LL<<k);
    }
    ans += res * 2;
    print(ans);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}