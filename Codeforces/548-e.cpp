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
typedef struct {
    ll val;
    ll n;
    ll m;
} P;

bool comp(P p1, P p2){
    if(p1.val == p2.val){
        return p1.n > p2.n;
    }
    return p1.val > p2.val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        ll N,M;
        cin >> N >> M;
        ll a[5][110];
        rep(i,0,N){
            rep(j,0,M){
                cin >> a[i][j];
            }
        }
        if(N <= 3){
            vector<ll> v;
            rep(i,0,N){
                rep(j,0,M){
                    v.push_back(a[i][j]);
                }
            }
            sort(v.begin(), v.end(), greater<ll>());
            ll ans = 0;
            rep(i,0,N) ans += v[i];
            print(ans);
        }else{
            vector<P> v;
            rep(i,0,N){
                rep(j,0,M){
                    v.push_back((P){a[i][j], i, j});
                }
            }
            sort(v.begin(), v.end(), comp);
            map<ll,ll> mp;
            rep(i,0,N){
                mp[v[i].m]++;
            }
            ll ans = 0;
            rep(i,0,N) ans += v[i].val;
            if(mp.size() != 2){
                print(ans);
            }else{
                ll cnt2 = 0;
                for(auto &e: mp){
                    if(e.second == 2) cnt2++;
                }
                if(cnt2 != 2){
                    print(ans);
                }else{
                    map<ll,ll> mp2;
                    rep(i,0,N){
                        if(mp2[v[i].m] == 0){
                            mp2[v[i].m] = v[i].n;
                        }else{
                            mp2[v[i].m] = min(abs(mp2[v[i].m] - v[i].n), N - abs(mp2[v[i].m] - v[i].n));
                        }
                    }
                    ll cnt_1 = 0, cnt_2 = 0;
                    for(auto &e: mp2){
                        if(e.second == 1){
                            cnt_1++;
                        }else if(e.second == 2){
                            cnt_2++;
                        }
                    }
                    if(cnt_1 == 1 && cnt_2 == 1){
                        ans -= v[N-1].val;
                        ans += v[N].val;
                        print(ans);
                    }else{
                        print(ans);
                    }
                }
            }

        }

    }
    
}