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
    ll H,W,N;
    cin >> H >> W >> N;
    ll r[210000], c[210000];
    rep(i,0,N) cin >> r[i] >> c[i];
    if(N <= 10){
        vector<ll> v1(N+4, 0);
        rep(i,0,4) v1[i] = 1;
        sort(v1.begin(), v1.end());
        do{

        }while(next_permutation)

        return 0;
    }
    if(H > 350 || W > 350) return 0;
    ll s[355][355] = {};
    rep(i,0,N){
        s[r[i]-1][c[i]-1]++;
    }
    ll ans = 0;
    ll sum[355][355] = {};
    rep(i,0,H){
        rep(j,0,W){
            sum[i+1][j+1] = s[i][j];
        }
    }
    rep(i,0,H+1){
        rep(j,0,W+1){
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(j,0,W+1){
        rep(i,0,H+1){
            sum[i+1][j] += sum[i][j];
        }
    }
    // rep(i,0,H+1){
    //     rep(j,0,W+1){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rep(w1,0,W){
        rep(w2,w1,W){
            rep(h1,0,H){
                ll lv = h1-1, rv = H;
                while(rv - lv > 1){
                    ll mid = (rv + lv) / 2;
                    ll val = sum[mid+1][w2+1] - sum[mid+1][w1] - sum[h1][w2+1] + sum[h1][w1];
                    if(val > 0){
                        rv = mid;
                    }else{
                        lv = mid;
                    }
                }

                ll h2 = rv-1;
                if(h2 < h1) continue;
                // print(w1,w2, h1, h2);
                // rep(h2,h1,H){
                    bool ok = true;
                    if(sum[h2+1][w2+1] - sum[h2+1][w1] - sum[h1][w2+1] + sum[h1][w1] > 0) ok = false;
                    // if(not ok) break;
                    bool tmp = false;
                    if(h1 == 0 || sum[h1][w2+1] - sum[h1][w1] - sum[h1-1][w2+1] + sum[h1-1][w1] > 0) tmp = true;
                    // rep(k,w1,w2+1){
                    //     if(h1 == 0 || s[h1-1][k] == 1){
                    //         tmp = true;
                    //         break;
                    //     }
                    // }
                    if(not tmp) ok = false;

                    tmp = false;
                    // if(h2 == H-1 || sum[h2+2][w2+1] - sum[h2+2][w1] > 0) tmp = true;
                    if(h2 == H-1 || sum[h2+2][w2+1] - sum[h2+2][w1] - sum[h2+1][w2+1] + sum[h2+1][w1] > 0) tmp = true;


                    // rep(k,w1,w2+1){
                    //     if(h2 == H-1 || s[h2+1][k] == 1){
                    //         tmp = true;
                    //         break;
                    //     }
                    // }
                    if(not tmp) ok = false;
                    tmp = false;
                    // if(w1 == 0 || sum[h2+1][w1] - sum[h1][w1] > 0) tmp = true;
                    if(w1 == 0 || sum[h2+1][w1] - sum[h1][w1] - sum[h2+1][w1-1] + sum[h1][w1-1] > 0) tmp = true;

                    // rep(k,h1,h2+1){
                    //     if(w1 == 0 || s[k][w1-1] == 1){
                    //         tmp = true;
                    //         break;
                    //     }
                    // }
                    if(not tmp) ok = false;
                    tmp = false;
                    // if(w2 == W-1 || sum[h2+1][w2+2] - sum[h1][w2+2] > 0) tmp = true;
                    if(w2 == W-1 || sum[h2+1][w2+2] - sum[h1][w2+2] - sum[h2+1][w2+1] + sum[h1][w2+1] > 0) tmp = true;

                    // rep(k,h1,h2+1){
                    //     if(w2 == W-1 || s[k][w2+1] == 1){
                    //         tmp = true;
                    //         break;
                    //     }
                    // }
                    if(not tmp) ok = false;
                    if(ok){
                        ans++;
                        // print("Yes");
                        // break;
                        // print(h1,h2, w1,w2);
                    }
                // }
            }

        }
    }
    print(ans);

    

}