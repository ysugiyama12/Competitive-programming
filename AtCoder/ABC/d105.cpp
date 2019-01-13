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
    int N,M;
    ll A[100010];
    cin >> N >> M;
    rep(i,0,N){
        cin >> A[i];
    }
    ll sum[100010] = {};
    rep(i,1,N+1){
        sum[i] = sum[i-1] + A[i-1];
    }
    rep(i,0,N+1){
        sum[i] %= M;
    }
    sort(sum, sum+N+1);
    ll ans = 0;
    ll now_val = 0;
    ll cnt = 0;
    rep(i,1,N+1){
        if(now_val == sum[i]){
            cnt++;
        }else{
            if(now_val == 0){
                ans += cnt;
            }
            ans += (cnt * (cnt-1))/2;
            now_val = sum[i];
            cnt = 1;
        }
    }
    if(now_val == 0){
        ans += cnt;
    }
    ans += (cnt * (cnt-1))/2;

    print(ans);



}
