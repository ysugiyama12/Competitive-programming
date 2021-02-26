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
    if(N == 1){
        print(-1);
        return 0;
    }
    if(N == 2){
        print(-1);
        return 0;
    }

    if(N % 3 == 0){
        char ans[1010][1010];
        rep(i,0,N){
            rep(j,0,N){
                ans[i][j] = '.';
            }
        }
        rep(i,0,N/3){
            ll h = i;
            ll w = 2*i;
            if(i % 2 == 0){
                ans[h][w] = 'a';
                ans[h][w+1] = 'a';
            }else{
                ans[h][w] = 'b';
                ans[h][w+1] = 'b';     
            }
        }
        rep(i,0,N/3){
            ll h = N/3 + 2 * i;
            ll w = 2 * (N/3) + i;
            if(i % 2 == 0){
                ans[h][w] = 'a';
                ans[h+1][w] = 'a';
            }else{
                ans[h][w] = 'b';
                ans[h+1][w] = 'b';          
            }
        }
        rep(i,0,N){
            rep(j,0,N){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }else if(N % 3 == 1){
        exit(1);

        // string S[3];
        // S[0] = "aa.";
        // S[1] = "..b";
        // S[2] = "..b";
        // char ans[1010][1010];
        // rep(i,0,N){
        //     rep(j,0,N){
        //         ans[i][j] = '.';
        //     }
        // }
        // for(ll i = 0; i < N; i += 4){
        //     for(ll j = 0; j < N; j += 4){
        //         if(i != j) continue;
        //         rep(k,0,3){
        //             rep(l,0,3){
        //                 ans[i+k][j+l] = S[k][l];
        //             }
        //         }
        //     }
        // }
        // rep(i,0,N){
        //     if(i != 0 && i % 3 == 0){
        //         ans[i][i] = 'a';
        //     }
        // }
        // rep(i,0,N){
        //     rep(j,0,N){
        //         cout << ans[i][j];
        //     }
        //     cout << endl;
        // }

    }else{
        string S[3];
        S[0] = "aa.";
        S[1] = "..b";
        S[2] = "..b";
        string T[3];
        T[0] = "aab";
        T[1] = "d.b";
        T[2] = "dcc";
        char ans[1010][1010];
        rep(i,0,N){
            rep(j,0,N){
                ans[i][j] = '.';
            }
        }
        ll soto = N * 2 + (N-2) * 2;
        string ss = "";
        rep(i,0,soto){
            if(i % 4 <= 1){
                ss += 'x';
            }else{
                ss += 'y';
            }
        }
        ss[soto-2] = 'z';
        ss[soto-1] = 'z';
        ll h = 0, w = 0, idx = 0;
        while(1){
            ans[h][w] = ss[idx];
            idx++;
            if(h == 0 && w <= N-2){
                w++;
            }else if(w == N-1 && h != N-1){
                h++;
            }else if(h == N-1 && w != 0){
                w--;
            }else{
                h--;
            }
            if(h == 0 && w == 0) break;
        }
        for(ll i = 1; i < N; i += 3){
            for(ll j = 1; j < N; j += 3){
                if(i == N-1 || j == N-1) continue;
                if(i == j){
                    rep(k,0,3){
                        rep(l,0,3){
                            ans[i+k][j+l] = T[k][l];
                        }
                    }    
                }else{
                    rep(k,0,3){
                        rep(l,0,3){
                            ans[i+k][j+l] = S[k][l];
                        }
                    }    
                }
            }
        }
        rep(i,0,N){
            rep(j,0,N){
                cout << ans[i][j];
            }
            cout << endl;
        }     
    }

    

}
