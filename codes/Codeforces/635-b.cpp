/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 8e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll nr,ng,nb;
        cin >> nr >> ng >> nb;
        vector<ll> r(nr), g(ng), b(nb);
        rep(i,0,nr) cin >> r[i];
        rep(i,0,ng) cin >> g[i];
        rep(i,0,nb) cin >> b[i];
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ll ans = INF;
        vector<lpair> lp;
        rep(i,0,nr){
            lp.push_back({r[i], 0});
        }
        rep(i,0,ng){
            lp.push_back({g[i], 1});
        }
        rep(i,0,nb){
            lp.push_back({b[i], 2});
        }
        sort(lp.begin(), lp.end());
        vector<ll> pr,pg,pb;
        rep(i,0,nr+ng+nb){
            if(lp[i].second == 0){
                pr.push_back(i);
            }else if(lp[i].second == 1){
                pg.push_back(i);
            }else{
                pb.push_back(i);
            }
        }

        rep(i,1,nr+ng+nb-1){
            if(lp[i].second == 0){
                ll val_g = -1, val_b = -1;
                ll pos = lower_bound(pg.begin(), pg.end(), i) - pg.begin();
                if(pos != 0){
                    val_g = g[pos-1];
                }
                pos = lower_bound(pb.begin(), pb.end(), i) - pb.begin();
                if(pos != nb){
                    val_b = b[pos];
                }
                if(val_g != -1 && val_b != -1){
                    ll val_r = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);

                    ans = min(ans, res);
                }

                val_b = -1, val_g = -1;
                pos = lower_bound(pb.begin(), pb.end(), i) - pb.begin();
                if(pos != 0){
                    val_b = b[pos-1];
                }
                pos = lower_bound(pg.begin(), pg.end(), i) - pg.begin();
                if(pos != ng){
                    val_g = g[pos];
                }
                if(val_g != -1 && val_b != -1){
                    ll val_r = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);

                    ans = min(ans, res);
                }
            }else if(lp[i].second == 1){
                ll val_r = -1, val_b = -1;
                ll pos = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
                if(pos != 0){
                    val_r = r[pos-1];
                }
                pos = lower_bound(pb.begin(), pb.end(), i) - pb.begin();
                if(pos != nb){
                    val_b = b[pos];
                }
                // print(val_r, val_b);
                if(val_r != -1 && val_b != -1){
                    ll val_g = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);
                    ans = min(ans, res);
                }
                val_r = -1, val_b = -1;
                pos = lower_bound(pb.begin(), pb.end(), i) - pb.begin();
                if(pos != 0){
                    val_b = b[pos-1];
                }
                pos = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
                if(pos != nr){
                    val_r = r[pos];
                }
                // print(val_r, val_b);
                if(val_r != -1 && val_b != -1){
                    ll val_g = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);
                    ans = min(ans, res);
                }
            }else{
                ll val_r = -1, val_g = -1;
                ll pos = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
                if(pos != 0){
                    val_r = r[pos-1];
                }
                pos = lower_bound(pg.begin(), pg.end(), i) - pg.begin();
                if(pos != ng){
                    val_g = g[pos];
                }
                if(val_r != -1 && val_g != -1){
                    ll val_b = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);

                    ans = min(ans, res);
                }

                val_g = -1, val_r = -1;
                pos = lower_bound(pg.begin(), pg.end(), i) - pg.begin();
                if(pos != 0){
                    val_g = g[pos-1];
                }
                pos = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
                if(pos != nr){
                    val_r = r[pos];
                }
                if(val_r != -1 && val_g != -1){
                    ll val_b = lp[i].first;
                    ll res = (val_r - val_g) * (val_r - val_g) + (val_r - val_b) * (val_r - val_b) + (val_b - val_g) * (val_b - val_g);
                    ans = min(ans, res);
                }
            }
        }
        print(ans);

    }
    

}