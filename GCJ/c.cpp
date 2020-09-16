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
#define Case(t) cout << "Case #" << t << ": "

void solve(ll t){
    ll N;
    cin >> N;
    ll X[110], Y[110];
    rep(i,0,N) cin >> X[i] >> Y[i];
    if(N > 7) return;
    vector<ll> pairs;
    for(ll i = 0; i < N; i += 2){
        pairs.push_back(i/2);
        if(i+1 < N) pairs.push_back(i/2);
    }
    ll ans = 0;
    vector<lpair> dir;
    rep(i,0,N){
        rep(j,0,N){
            if(i == j) continue;
            dir.push_back({X[i]-X[j], Y[i]-Y[j]});
        }
    }

    do {
        map<ll,ll> nxt;
        rep(i,0,N) nxt[i] = -1;
        rep(i,0,N){
            rep(j,0,N){
                if(i == j) continue;
                if(pairs[i] == pairs[j]){
                    nxt[i] = j;
                    nxt[j] = i;
                }
            }
        }

        rep(s,0,N){
            for(auto &d: dir){
                ll cur = s;
                ll check[10] = {};
                while(true){
                    if(check[cur] > N) break;
                    check[cur]++;
                    if(nxt[cur] == -1){
                        break;
                    }
                    cur = nxt[cur];
                    check[cur]++;
                    bool ok = false;
                    ll min_dist = INF;
                    ll cur_nxt = -1;
                    
                    rep(i,0,N){
                        if(i == cur || i == nxt[cur]) continue;
                        ll dx = X[i] - X[cur];
                        ll dy = Y[i] - Y[cur];
                        if(dy * d.first == dx * d.second){
                            if(dx == 0){
                                if(d.second * dy > 0){
                                    if(dx < min_dist){
                                        ok = true;
                                        cur_nxt = i;
                                        min_dist = dx;
                                    }
                                }
                            }else{
                                if(d.first * dx > 0){
                                    if(dx < min_dist){
                                        ok = true;
                                        cur_nxt = i;
                                        min_dist = dx;
                                    }
                                }
                            }
                        }
                    }
                    if(not ok) break;
                    cur = cur_nxt;

                }
                ll cnt = 0;
                rep(i,0,N){
                    if(check[i] > 0) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }while(next_permutation(pairs.begin(), pairs.end()));
    if(ans == 0) ans++;
    Case(t);
    print(ans);

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    rep(i,1,t+1) solve(i);
}