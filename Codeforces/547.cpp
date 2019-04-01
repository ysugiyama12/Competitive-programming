#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

inline vector<ll> factor(ll M){ //素因数分解
    vector<ll> dd;
    if(M == 1){
        dd.push_back(1);
        return dd;
    }
    for(ll i = 2; i*i <= M; i++){
        while(M % i == 0){
            dd.push_back(i);
            M /= i;
        }
    }
    if(M != 1) dd.push_back(M);
    sort(dd.begin(), dd.end());
    return dd;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll Q[200010];
    cin >> N;
    rep(i,0,N-1) cin >> Q[i];
    ll v[200010] = {};
    v[0] = 0;
    rep(i,0,N-1){
        v[i+1] = v[i] + Q[i];
    }
    ll tt = INF;
    rep(i,0,N) tt = min(tt, v[i]);
    rep(i,0,N){
        v[i] += abs(tt) + 1;
    }
    map<ll,ll> cnt;
    rep(i,0,N) cnt[v[i]]++;
    rep(i,0,N){
        if(cnt[i+1] != 1){
            print(-1);
            return 0;
        }
    }
    rep(i,0,N){
        cout << v[i] << " \n"[i == N-1];
    }



    
}