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
    ll a[110];
    rep(i,0,N) cin >> a[i];
    ll num[110];
    rep(i,0,N) num[i] = __builtin_popcount(a[i]);
    ll keta = 32;
    vector<ll> val[110];
    rep(bit,0,30){
        rep(i,0,N){
            if((a[i]>>bit) & 1){
                val[i].push_back(-1);
            }else{
                val[i].push_back(1);
            }
        }
    }
    vector< vector<ll> > v;
    map< vector<ll>, ll> mp;
    rep(bit,0,(1LL<<15)){
        vector<ll> v1(N,0);
        rep(i,0,15){
            if((bit>>i) & 1){
                rep(j,0,N){
                    v1[j] += val[j][i];
                }

            }
        }
        v.push_back(v1);
    }

    rep(bit,0,(1LL<<15)){
        vector<ll> v1(N,0);
        rep(i,0,15){
            if((bit>>i) & 1){
                rep(j,0,N){
                    v1[j] += val[j][i+15];
                }

            }
        }
        mp[v1]++;
    }
    for(auto &e: v){
        vector<ll> v3;
        rep(i,0,N) v3.push_back(e[i]-100);
        rep(i,0,200){
            if(mp[v3] > 0){
                // print("Yay");
            }
            rep(j,0,N) v3[j]++;
        }

    }
    print(-1);
    // rep(bit,0,(1LL<<30)){
    //     ll cnt[110] = {};
    //     rep(i,0,N) cnt[i] = num[i];
    //     rep(i,0,30){
    //         if((bit>>i) & 1){
    //             // rep(j,0,N){
    //             //     cnt[j] += val[j][i];
    //             // }
    //         }
    //     }
    //     bool ok = true;
    //     rep(i,0,N-1){
    //         if(cnt[i] != cnt[i+1]) ok = false;
    //     }
    //     if(ok){
    //         ll ans = 0;
    //         rep(i,0,30){
    //             if((bit>>i) & 1) ans += (1LL<<i);
    //         }
    //         print(ans);
    //         return 0;

    //     }
    // }
    // print(-1);
}