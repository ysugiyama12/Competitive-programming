#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
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
    ll vp[200010] = {};
    rep(i,0,N-1){
        ll v = A[i+1];
        while(v < A[i]){
            v *= 4;
            vp[i]++;
        }
    }
    ll vp_sum[200010];
    rep(i,0,N){
        vp_sum[i+1] = vp_sum[i] + vp[i];
    }
    printa(vp,N);
    printa(vp_sum,N+1);
    // for(int i = N-1; i >= 0; i--){
    //     if(i == N-1) continue;
    //     if(A[i] <= A[i+1]){
    //         continue;
    //     }else{
    //         ll v = A[i+1];
    //         ll tt = 0;
    //         while(A[i] > v){
    //             tt++;
    //             v *= 4;
    //         }
    //         vp[i] = 2 * tt * (N - 1 - i);
    //     }
    // }
    ll ans = INF;
    rep(t,0,N+1){
        ll cur = A[t];
        ll ans_tmp = 0;
        rep(i,t+1,N){
            ll v = A[i];
            while(v < cur){
                // print(v);
                ans_tmp += 2;
                v *= 4;
            }
            cur = v;
        }
        cur = A[t-1];
        ans_tmp += t;
        for(int i = t-2; i >= 0; i--){
            ll v = A[i];
            while(v < cur){
                ans_tmp += 2;
                v *= 4;
            }
            cur = v; 
        }
        ans = min(ans, ans_tmp);
        // print2(ans_tmp,t);
    }
    print(ans);

}
