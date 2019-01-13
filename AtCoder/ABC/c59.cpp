#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    ll a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll sum[100010] = {};
    ll ans = 0;
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
        if(i % 2 == 0){
            if(sum[i+1] <= 0){
                ans += -sum[i+1] + 1;
                sum[i+1] += -sum[i+1] + 1;
            }
        }else{
            if(sum[i+1] >= 0){
                ans += sum[i+1] + 1;
                sum[i+1] -= sum[i+1] + 1;
            }
        }
    }
    rep(i,0,N+1){
        sum[i] = 0;
    }
    ll ans2 = 0;
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
        if(i % 2 == 0){
            if(sum[i+1] >= 0){
                ans2 += sum[i+1] + 1;
                sum[i+1] -= sum[i+1] + 1;
            }
        }else{
            if(sum[i+1] <= 0){
                ans2 += -sum[i+1] + 1;
                sum[i+1] += -sum[i+1] + 1;
            }
        }
    }
    print(min(ans, ans2));








}
