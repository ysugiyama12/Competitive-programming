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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll X[1010], Y[1010];
    rep(i,0,N) cin >> X[i] >> Y[i];
    ll cnt[2] = {};
    rep(i,0,N){
        cnt[abs(X[i]+Y[i]) % 2]++;
    }
    if(not(cnt[0] == 0 || cnt[0] == N)){
        print(-1);
        return 0;
    }
    if(cnt[0] == 0){
        ll m = 40;
        ll d[42] = {};
        rep(i,0,m) d[i] = (1LL<<i);
        print(m);
        printa(d, m);
        rep(i,0,N){
            ll u = X[i] + Y[i];
            ll v = X[i] - Y[i];
            ll ua = abs(X[i]+Y[i]);
            ll num[45] = {};
            rep(j,0,m-1) num[j] = -1;
            num[m-1] = 1;
            ua--;
            rrep(j,m-2,0){
                if(ua >= 2*d[j]){
                    ua -= 2*d[j];
                    num[j] = 1;
                }
            }
            if(u < 0){
                rep(j,0,40) num[j] *= -1;
            }
            ll va = abs(X[i] - Y[i]);
            ll num2[45] = {};
            rep(j,0,m-1) num2[j] = -1;
            num2[m-1] = 1;
            va--;
            rrep(j,m-2,0){
                if(va >= 2*d[j]){
                    va -= 2*d[j];
                    num2[j] = 1;
                }
            }
            if(v < 0){
                rep(j,0,m) num2[j] *= -1;
            }
            rep(j,0,m){
                if(num[j] == 1){
                    if(num2[j] == 1){
                        cout << 'R';
                    }else{
                        cout << 'U';
                    }
                }else{
                    if(num2[j] == 1){
                        cout << 'D';
                    }else{
                        cout << 'L';
                    }
                }
            }
            cout << endl;
        }

    }else{
        ll m = 40;
        ll d[42] = {};
        d[0] = 1;
        rep(i,0,m-1) d[i+1] = (1LL<<i);
        print(m);
        printa(d, m);
        rep(i,0,N){
            ll u = X[i] + Y[i];
            ll v = X[i] - Y[i];
            ll ua = abs(X[i]+Y[i]);
            ll num[45] = {};
            rep(j,0,m-1) num[j] = -1;
            num[m-1] = 1;
            // ua--;
            rrep(j,m-2,0){
                if(ua >= 2*d[j]){
                    ua -= 2*d[j];
                    num[j] = 1;
                }
            }
            if(u < 0){
                rep(j,0,40) num[j] *= -1;
            }
            ll va = abs(X[i] - Y[i]);
            ll num2[45] = {};
            rep(j,0,m-1) num2[j] = -1;
            num2[m-1] = 1;
            // va--;
            rrep(j,m-2,0){
                if(va >= 2*d[j]){
                    va -= 2*d[j];
                    num2[j] = 1;
                }
            }
            if(v < 0){
                rep(j,0,m) num2[j] *= -1;
            }
            rep(j,0,m){
                if(num[j] == 1){
                    if(num2[j] == 1){
                        cout << 'R';
                    }else{
                        cout << 'U';
                    }
                }else{
                    if(num2[j] == 1){
                        cout << 'D';
                    }else{
                        cout << 'L';
                    }
                }
            }
            cout << endl;
        }

    }

    
}