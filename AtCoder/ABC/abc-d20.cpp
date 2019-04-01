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

inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;} //最小公倍数
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
    sort(dd.begin(), dd.end());
    return dd;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> dd = divisor(K);
    ll n = dd.size();
    rep(i,0,n){
        ll k = dd[i];

    }
    // ll N,K;
    // cin >> N >> K;
    // if(K > 100) return 0;
    // vector<ll> dv = divisor(K);
    // ll gcds[110] = {};
    // rep(i,0,K){
    //     gcds[i] = gcd(i,K);
    // }
    // ll ans = 0;
    // rep(i,0,K){
    //     ll tt = 0, max_val, cnt;
    //     if(N % K == i){
    //         max_val = N;
    //     }else if(N % K > i){
    //         max_val = N - (N%K - i);
    //     }else{
    //         max_val = N - N%K - (K - i);
    //     }
    //     if(i == 0){
    //         cnt = (max_val - K)/K + 1;
    //         tt = (K + max_val) * cnt * K / 2;
    //         tt /= gcds[i];
    //     }else{
    //         cnt = (max_val - i)/K + 1;
    //         tt = (i + max_val) * cnt * K / 2;
    //         tt /= gcds[i];
    //     }
    //     // print(cnt);
    //     ans += tt % MOD;
    //     ans %= MOD;
    // }
    // print(ans);
}
