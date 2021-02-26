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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[410];
    rep(i,0,N*N) cin >> A[i];
    sort(A, A+N*N);
    if(N % 2 == 0){
        map<ll, ll> mp;
        rep(i,0,N*N){
            mp[A[i]]++;
        }
        bool ok = true;
        for(auto &e: mp){
            if(e.second % 4 != 0){
                ok = false;
            }
        }
        if(!ok){
            print("NO");
            return 0;
        }
        ll ans[25][25] = {};
        vector<ll> alt;
        for(auto &e: mp){
            rep(j,0,e.second/4){
                alt.push_back(e.first);
            }
        }
        ll idx = 0;
        rep(i,0,N/2){
            rep(j,0,N/2){
                ll v = alt[idx];
                ans[i][j] = v;
                ans[N-1-i][j] = v;
                ans[i][N-1-j] = v;
                ans[N-1-i][N-1-j] = v;
                idx++;
            }
        }
        print("Yes");
        rep(i,0,N){
            rep(j,0,N){
                cout << ans[i][j] << " \n"[j == N-1];
            }
        }
    }else{
        map<ll,ll> mp;
        rep(i,0,N*N){
            mp[A[i]]++;
        }
        bool ok = true;
        ll cnt1 = 0, cnt2 = 0;
        for(auto &e: mp){
            if(e.second % 4 != 0){
                if(e.second % 2 == 1){
                    cnt1++;
                }else{
                    cnt2++;
                }
            }
        }
        if(!ok || cnt1 != 1 || cnt2 > N-1){
            print("NO");
            return 0;
        }
        ll ans[25][25] = {};
        vector<ll> alt;
        vector<ll> alt2;
        ll num1 = -1;
        for(auto &e: mp){
            if(e.second % 4 == 0){
                rep(i,0,e.second/4){
                    alt.push_back(e.first);
                }
            }else{
                ll v = e.second;
                if(v % 2 == 1){
                    num1 = e.first;
                    v--;
                }
                if(v % 4 == 2){
                    alt2.push_back(e.first);
                    v -= 2;
                }
                rep(i,0,v/4){
                    alt.push_back(e.first);
                }
            }
        }
        if(alt2.size() < N-1){
            ll n = N-1-alt2.size();
            rep(i,0,n){
                ll v = i/2;
                alt2.push_back(alt[alt.size()-1-v]);
            }
        }
        // printa(alt,alt.size());
        // printa(alt2,alt2.size());
        // print(num1);
        ll idx = 0, idx2 = 0;
        ll k = (N+1)/2;
        rep(i,0,k){
            rep(j,0,k){
                if(i != k-1 && j != k-1){
                    ans[i][j] = alt[idx];
                    ans[i][N-1-j] = alt[idx];
                    ans[N-1-i][j] = alt[idx];
                    ans[N-1-i][N-1-j] = alt[idx];
                    idx++;
                }else if(i == k-1 && j == k-1){
                    ans[i][j] = num1;
                }else if(i == k-1){
                    ans[i][j] = alt2[idx2];
                    ans[i][N-1-j] = alt2[idx2];
                    idx2++;
                }else{
                    ans[i][j] = alt2[idx2];
                    ans[N-1-i][j] = alt2[idx2];
                    idx2++;

                }

            }
        }
        print("Yes");
        rep(i,0,N){
            rep(j,0,N){
                cout << ans[i][j] << " \n"[j == N-1];
            }
        }

    }
}
