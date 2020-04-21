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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    rep(t,1,T+1){
        ll R,S;
        cin >> R >> S;
        ll ans = 0;
        vector<ll> cur;
        rep(i,0,S){
            rep(j,0,R){
                cur.push_back(j+1);
            }
        }
        vector<ll> last_pos;
        rep(i,0,R){
            rep(j,0,S){
                last_pos.push_back(i+1);
            }
        }
        vector<lpair> ope;
        while(1){
            vector<ll> nxt;
            bool ok = true;
            rep(i,0,R*S-1){
                if(cur[i] > cur[i+1]) ok = false;
            }
            if(ok){
                break;
            }
            rrep(i,R*S-1,0){
                if(cur[i] != last_pos[i]){
                    ll pos = -1;
                    rrep(j,i,0){
                        if(cur[j] == last_pos[i]){
                            pos = j;
                            break;
                        }
                    }
                    ope.push_back({pos+1, i-pos});
                    rep(j,pos+1, i+1){
                        nxt.push_back(cur[j]);
                    }
                    rep(j,0,pos+1){
                        nxt.push_back(cur[j]);
                    }
                    rep(j,i+1,R*S){
                        nxt.push_back(cur[j]);
                    }
                    break;
                }
            }
            
            cur = nxt;
        }
        ans = ope.size();

        Case(t);
        print(ans);
        for(auto &e: ope){
            print(e.first, e.second);
        }
    }
    

}