#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    ll x[100001], y[100001];
    char c[100001];
    cin >> N >> K;
    rep(i,0,N){
        cin >> x[i] >> y[i] >> c[i];
    }
    rep(i,0,N){
        if(c[i] == 'W'){
            y[i] += K;
        }
    }
    rep(i,0,N){
        x[i] = x[i] % (2*K);
        y[i] = y[i] % (2*K);
    }
    int ans = 0;
    rep(i,0,K){
        rep(j,0,K){
            int sx = i;
            int sy = j;
            int ans_tmp = 0;
            rep(k,0,N){
                if(x[k] >= sx && x[k] < sx+K){
                    if(y[k] >= sy && y[k] < sy+K){
                        ans_tmp++;
                    }
                }else if(y[k] < sy || y[k] >= sy+K){
                    ans_tmp++;
                }
            }
            ans = max(ans, ans_tmp);

            ans_tmp = 0;
            rep(k,0,N){
                if(x[k] >= sx && x[k] < sx+K){
                    if(y[k] < sy || y[k] >= sy+K){
                        ans_tmp++;
                    }
                }else if(y[k] >= sy && y[k] < sy+K){
                    ans_tmp++;
                }
            }
            ans = max(ans, ans_tmp);

            // int sx = i;
            // int sy = j;
            // int ans_tmp = 0;
            // rep(k,0,N){
            //     if(sx <= K && sy <= K){
            //         if(x[k] >= sx && x[k] < sx + K){
            //             if(y[k] >= sy && y[k] < sy + K){
            //                 ans_tmp++;
            //             }
            //         }else if(y[k] < sy || y[k] >= sy + K){
            //             ans_tmp++;
            //         }
            //     }else if(sx > K && sy > K){
            //         sx -= K;
            //         sy -= K;
            //         if(x[k] >= sx && x[k] < sx + K){
            //             if(y[k] >= sy && y[k] < sy + K){
            //                 ans_tmp++;
            //             }
            //         }else if(y[k] < sy || y[k] >= sy + K){
            //             ans_tmp++;
            //         }

            //     }else{
            //         if(sx > K){
            //             sx -= K;
            //         }
            //         if(sy > K){
            //             sy -= K;
            //         }
            //         if(x[k] < sx || x[k] >= sx + K){
            //             if(y[k] >= sy && y[k] < sy + K){
            //                 ans_tmp++;
            //             }
            //         }else if(y[k] < sy || y[k] >= sy + K){
            //             ans_tmp++;
            //         }
            //     }
            // }
            // ans = max(ans_tmp, ans);

        }
    }
    print(ans);



}
