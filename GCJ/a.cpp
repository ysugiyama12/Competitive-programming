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
        ll X,Y;
        cin >> X >> Y;
        ll x2 = abs(X), y2 = abs(Y);
        ll N = x2 + y2;
        ll sum = 0;
        ll max_bit = -1;
        bool ok = false;
        vector<ll> plus, minus;
        rep(i,0,32){
            minus.clear();
            sum += (1LL<<i);
            ll v = sum - N;
            if(v < 0) continue;
            if(v % 2 == 1) continue;
            v /= 2;
            rrep(j,i-1,0){
                ll bb = (1LL<<j);
                if(v&bb){
                    v -= bb;
                    minus.push_back(1LL<<j);
                }
            }
            if(v == 0){
                ok = true;
                max_bit = i;
                break;
            }

        }
        if(not ok){
            Case(t);
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        map<ll,ll> mp;
        for(auto &e: minus){
            mp[e]++;
        }
        vector<ll> num;
        rep(i,0,max_bit+1){
            ll v = (1LL<<i);
            if(mp[v] > 0){
                num.push_back(-v);
            }else{
                num.push_back(v);
            }
        }
        // printa(num, num.size());
        ll sz = num.size();
        ll m1 = sz/2, m2 = sz - m1;
        vector<ll> p1, p2;
        rep(bit,0,(1LL<<m1)){
            ll res = 0;
            rep(i,0,m1){
                if((bit>>i)&1) res += num[i];
            }
            p1.push_back(res);
        }
        rep(bit,0,(1LL<<m2)){
            ll res = 0;
            rep(i,0,m2){
                if((bit>>i)&1) res += num[i+m1];
            }
            p2.push_back(res);
        }
        map<ll,ll> mp2;
        for(auto &e: p2) mp2[e]++;
        vector<ll> ans_X, ans_Y;
        ll v1 = 0, v2 = 0;
        for(auto &e: p1){
            if(mp2[x2-e] > 0){
                // print(e, x2-e);
                v1 = e; v2 = x2-e;
                break;
            }
        }
        rep(bit,0,(1LL<<m1)){
            ll res = 0;
            rep(i,0,m1){
                if((bit>>i)&1) res += num[i];
            }
            if(res == v1){
                rep(i,0,m1){
                    if((bit>>i)&1){
                        ans_X.push_back(num[i]);
                    }else{
                        ans_Y.push_back(num[i]);
                    }
                }
            }
        }
        rep(bit,0,(1LL<<m2)){
            ll res = 0;
            rep(i,0,m2){
                if((bit>>i)&1) res += num[m1+i];
            }
            if(res == v2){
                rep(i,0,m2){
                    if((bit>>i)&1){
                        ans_X.push_back(num[m1+i]);
                    }else{
                        ans_Y.push_back(num[m1+i]);
                    }
                }
            }
        }
        // printa(ans_X, ans_X.size());
        vector<lpair> lp;
        for(auto &e: ans_X) lp.push_back({e, 0}); 
        for(auto &e: ans_Y) lp.push_back({e, 1}); 
        sort(lp.begin(), lp.end(), [](lpair l1, lpair l2){
            return abs(l1.first) < abs(l2.first);
        });

        // printa(ans_Y, ans_Y.size());
        string ans = "";
        for(auto &e: lp){
            if(e.second == 1){
                if(e.first > 0){
                    if(Y == y2){
                        ans += 'N';
                    }else{
                        ans += 'S';
                    }
                }else{
                    if(Y == y2){
                        ans += 'S';
                    }else{
                        ans += 'N';
                    }
                }
            }else{
                if(e.first > 0){
                    if(X == x2){
                        ans += 'E';
                    }else{
                        ans += 'W';
                    }
                }else{
                    if(X == x2){
                        ans += 'W';
                    }else{
                        ans += 'E';
                    }
                }
            }
        }
        Case(t);
        print(ans);






    }
    

}