/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll calc(string T){
    ll n = T.size();
    ll idx = 1;
    ll res = 0;
    reverse(T.begin(), T.end());
    rep(i,0,n){
        if(T[i] == '1'){
            res += idx;
        }
        idx *= 2;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    vector<ll> alt[200010];
    rep(n,3,200001){
        ll keta = 0;
        ll nn = n;
        while(nn > 0){
            keta++;
            nn /= 2;
        }
        ll zero = n - keta;
        alt[zero].push_back(keta);
    }
    while(T--){
        string S;
        cin >> S;
        ll ans = 0;
        ll N = S.size();
        vector<ll> pos;
        rep(i,0,N){
            if(S[i] == '1') pos.push_back(i);
        }
        rep(i,0,N){
            if(S[i] == '1'){
                ans++;
                if(i <= N-2 && S[i+1] == '0') ans++;
            }else{
                ll p = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
                if(p == pos.size()) continue;
                ll npos = pos[p];
                ll diff = npos - i;
                for(auto &e: alt[diff]){
                    ll keta_total = e + diff;
                    ll val = calc(S.substr(npos, e));
                    if(val == keta_total){
                        ans++;
                    }
                }
            }
        }
        print(ans);

    }
}