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
ll rev(ll x){
    string s = to_string(x);
    ll val = 0;
    rep(i,0,s.size()){
        val += pow(10,i) * (s[i] - '0');
    }
    return val;
    
}
ll dp[1010][1010];
ll is_visit[1010][1010] = {};
ll rec(ll x, ll y){
    ll &res = dp[x][y];
    if(~res) return res;
    if(is_visit[x][y]) return res = 0;
    is_visit[x][y] = 1;
    if(x == 0 || y == 0) return res = 1;
    if(x < y){
        x = rev(x);
    }else{
        y = rev(y);
    }
    if(x < y){
        y -= x;
    }else{
        x -= y;
    }
    return res = rec(x,y);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    rep(i,0,1000){
        rep(j,0,1000){
            rec(i,j);
        }
    }
    ll ans = 0;
    rep(i,1,N+1){
        rep(j,1,M+1){
            if(dp[i][j] == 0) ans++;
        }
    }
    print(ans);
    // int x,y;
    // int x_inv, y_inv;
    // int total = 0;
    // rep(i,1,N+1){
    //     rep(j,1,M+1){
    //         // if(i != 13 || j != 13) continue;
    //         // print(i);
    //         // print(j);
    //         // print("");
    //         x = i;
    //         y = j;
    //         int count = 0;
    //         while(1){
    //             if(x == 0 || y == 0) break;
    //             // print(x);
    //             // print(y);
    //             string x_s = to_string(x);
    //             string y_s = to_string(y);
    //             reverse(x_s.begin(), x_s.end());
    //             reverse(y_s.begin(), y_s.end());
    //             int x_inv = atoi(x_s.c_str());
    //             int y_inv = atoi(y_s.c_str());
    //             // print(x_inv);
    //             // print(y_inv);
    //             // print("");
    //             // break;

    //             if(x < y){
    //                 x = x_inv;
    //             }else{
    //                 y = y_inv;
    //             }
    //             if(x < y){
    //                 y = y - x;
    //             }else{
    //                 x = x - y;
    //             }
    //             count++;
    //             if(count >= 500){
    //                 total++;
    //                 print(i);
    //                 print(j);
    //                 print("");
    //                 break;
                    
    //             }
    //         }
            
    //     }
    // }
    // print(total);
}
