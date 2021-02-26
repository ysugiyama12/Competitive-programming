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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[100010];
    rep(i,0,N) cin >> a[i];
    vector<ll> v(N);
    iota(v.begin(), v.end(), 1);
    if(N == 2){
        print(-1);
        return 0;
    }
    ll cnt = 0;
    do{
        bool ok = true;
        rep(i,0,N-1){
            ll n = v[i];
            if(a[n-1] == v[i+1]) ok = false;
        }
        if(ok){
            printa(v, N);
            return 0;
        }
        cnt++;
        if(cnt > 1000) break;

    }while(next_permutation(v.begin(), v.end()));
    cnt = 0;
    iota(v.begin(), v.end(), 1);
    v[1] = 3;
    v[2] = 2;
    do{
        bool ok = true;
        rep(i,0,N-1){
            ll n = v[i];
            if(a[n-1] == v[i+1]) ok = false;
        }
        if(ok){
            printa(v, N);
            return 0;
        }

    }while(next_permutation(v.begin(), v.end()));

    

}