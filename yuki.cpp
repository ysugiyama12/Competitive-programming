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
    ll N,K,M;
    ll num = 30;
    cin >> N >> K >> M;
    if(N == 1){
        print(1);
        return 0;
    }
    vector<ll> fac = factor(N);
    // printa(fac, fac.size());
    map<ll,ll> mp;
    bool flg = false;
    for(auto &e: fac){
        mp[e]++;
        if(e == 2) flg = true;
    }
    for(auto &e: mp){
        ll v = e.second * K;
        if(v > num){
            mp[e.first] = num;
        }else{
            mp[e.first] *= K;
        }
    }
    vector<lpair> lp;
    for(auto &e: mp){
        lp.push_back(make_pair(e.first, e.second));
    }
    sort(lp.begin(), lp.end());
    ll sz = mp.size() / 2;
    vector<ll> ans;
    rep(bit,0,pow(num, sz)){
        ll v[20] = {};
        ll b = bit;
        ll idx = 0;
        while(b){
            v[idx] = b % num;
            b /= num;
            idx++;
        }
        bool ok = true;
        rep(i,0,sz){
            if(v[i] > lp[i].second) ok = false;
        }
        if(not ok) continue;
        ll tt = 1;
        rep(i,0,sz){
            tt *= pow(lp[i].first, v[i]);
            if(tt > 1e9 || tt > M){
                ok = false;
                break;
            }
        }
        if(not ok) continue;
        ans.push_back(tt);
    }
    sort(ans.begin(), ans.end());

    vector<ll> ans2;
    num = 20;
    ll sz2 = mp.size() - sz;
    // print(sz2);
    rep(bit,0,pow(num, sz2)){
        ll v[20] = {};
        ll b = bit;
        ll idx = 0;
        while(b){
            v[idx] = b % num;
            b /= num;
            idx++;
        }
        bool ok = true;
        rep(i,0,sz2){
            if(v[i] > lp[sz+i].second) ok = false;
        }
        if(not ok) continue;
        ll tt = 1;
        rep(i,0,sz2){
            if(pow(lp[sz+i].first, v[i]) > 1e9){
                ok = false;
                break;
            }
            tt *= pow(lp[sz+i].first, v[i]);
            if(tt > 1e9 || tt > M){
                ok = false;
                break;
            }
        }
        if(not ok) continue;
        ans2.push_back(tt);
    }
    sort(ans2.begin(), ans2.end());
    // printa(ans, ans.size());
    // printa(ans2, ans2.size());
    ll val = 0;
    rep(i,0,ans.size()){
        ll k = M / ans[i];
        ll pos = upper_bound(ans2.begin(), ans2.end(), k) - ans2.begin();
        val += pos;
    }
    print(val);





}