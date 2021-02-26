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
    ll N;
    ll A[200010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    ll sum[200010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + A[i];
    }
    ll ans = 0;
    sort(sum, sum+N+1);
    ll cnt = 1;
    ll val = sum[0];
    rep(i,1,N+1){
        if(sum[i] == val){
            cnt++;
        }else{
            if(val == 0){
                // ans += cnt;
            }
            ans += cnt * (cnt-1) / 2;
            cnt = 1;
            val = sum[i];
        }
    }
    if(val == 0){
        // ans += cnt;
    }
    ans += cnt * (cnt - 1) / 2;
    print(ans);


}

