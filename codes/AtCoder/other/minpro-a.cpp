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
    // sort(dd.begin(), dd.end());
    return dd;
}

inline vector<ll> divisor(ll M){ //約数の全列挙
    vector<ll> dd;
    for(ll i = 1; i*i <= M; i++){
        if(M % i == 0){
            dd.push_back(i);
            if(i * i != M){
                dd.push_back(M/i);
            }
        }
    }
    // sort(dd.begin(), dd.end());
    return dd;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll mp[100010] = {};
    rep(i,0,N){
        vector<ll> dd = divisor(A[i]);
        for(auto &e: dd){
            mp[e]++;
        }
    }
    rep(n,1,M+1){
        vector<ll> dd = factor(n);
        dd.erase(unique(dd.begin(), dd.end()), dd.end());
        ll sz = dd.size();
        ll ans = 0;
        rep(bit,1,(1LL<<sz)){
            ll cnt = __builtin_popcount(bit);
            ll mul = 1;
            rep(i,0,sz){
                if((bit>>i) & 1) mul *= dd[i];
            }
            if(cnt % 2 == 1){
                ans += mp[mul];
            }else{
                ans -= mp[mul];
            }
        }
        ans = N - ans;
        if(n == 1){
            print(N);
        }else{
            print(ans);

        }

    }
    
}