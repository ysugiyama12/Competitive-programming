#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
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
    int N;
    cin >> N;
    int bit_count[35] = {};
    ll plus_sum[20] = {0};
    ll minus_sum[20] = {0};
    rep(i,1,20){
        plus_sum[i] = plus_sum[i-1] + pow(2, 2*i - 2);
        minus_sum[i] = minus_sum[i-1] + pow(-2, 2*i - 1);
    }
    ll n = N;
    while(1){
        // print(n);
        if(n == 0) break;
        int pos = -1;
        if(n > 0){
            rep(i,0,20){
                if(plus_sum[i] >= n){
                    pos = i;
                    break;
                }
            }
            int tt = (pos-1)*2;
            bit_count[tt] = 1;
            n -= pow(2, tt);
        }else{
            rep(i,0,20){
                if(minus_sum[i] <= n){
                    pos = i;
                    break;

                }
            }
            int tt = (pos - 1)*2 + 1;
            bit_count[tt] = 1;
            n -= pow(-2, tt);
        }
    }
    bool flg = false;
    if(N == 0){
        print("0");
        return 0;
    }
    rep(i,0,35){
        if(flg){
           cout << bit_count[34-i]; 
        }else if(bit_count[34-i] == 1){
            cout << bit_count[34-i];
            flg = true;
        }
    }
    cout << endl;



    // ll n = N;
    // while(1){
    //     if(n == 0) break;
    //     int min_pos = -1;
    //     ll min_val = 1e12;
    //     rep(i,0,35){
    //         ll val = pow(-2, i);
    //         if(abs(n - val) < min_val){
    //             min_val = abs(n-val);
    //             min_pos = i;
    //         }
    //     }
    //     print(pow(-2, min_pos));
    //     bit_count[min_pos] = 1;
    //     n -= pow(-2, min_pos);
    // }
    // rep(i,0,35){
    //     cout << bit_count[34-i];
    // }
    // print("");

}
