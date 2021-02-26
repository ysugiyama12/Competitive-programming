#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
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
    ll A[200010];
    cin >> N >> K;
    rep(i,0,N) cin >> A[i];
    ll g[200010];
    rep(i,0,N) g[i] = gcd(A[i], K);
    vector<ll> dd = divisor(K);
    map<ll, ll> mp;
    rep(i,0,N){
        mp[g[i]]++;
    }
    ll ans = 0;
    ll n = dd.size();
    rep(i,0,n){
        rep(j,0,n){
            // if(i == j) continue;
            if(dd[i] * dd[j] % K == 0){
                if(i == j){
                    ans += mp[dd[i]] * (mp[dd[i]]-1);

                }else{
                    ans += mp[dd[i]] * mp[dd[j]];
                }
            }
        }
    }
    print(ans/2);

}
