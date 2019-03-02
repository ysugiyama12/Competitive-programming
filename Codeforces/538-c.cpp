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
    ll N,B;
    cin >> N >> B;
    vector<ll> bb = factor(B);
    map<ll,ll> mp;
    rep(i,0,bb.size()){
        mp[bb[i]]++;
    }
    ll ans = INF;
    for(auto &e: mp){
        ll num = e.first;
        ll cnt = e.second;
        ll cc = 0;
        ll nn = num;
        while(nn <= N){
            // print(num);
            cc += N/nn;
            if(N / nn < num) break;
            nn *= num;
        }
        // print(num);
        ans = min(ans, cc / cnt);
        // print(num);
    }
    print(ans);
}
