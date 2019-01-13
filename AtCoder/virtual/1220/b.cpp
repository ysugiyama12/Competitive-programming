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
    ll N,x;
    ll a[2010];
    cin >> N >> x;
    rep(i,0,N){
        cin >> a[i];
    }
    ll ans = INF;
    rep(i,1,N){

    }
    ll vv[2010] = {};
    rep(i,0,N){
        ll tt = 0;
        tt += i * x;
        rep(j,0,N){
            ll min_val = INF;
            if(i == 0){
                vv[j] = a[j];
            }else{
                ll pos = (j-i + N) % N;
                vv[j] = min(vv[j], a[pos]);
            }


            // rep(k,j-i,j+1){
            //     ll pos = (k + N) % N;
            //     min_val = min(min_val, a[pos]);
            // }
            tt += vv[j];
        }
        ans = min(ans, tt);
    }
    // vector<lpair> lp;
    // rep(i,0,N){
    //     lp.push_back(make_pair(a[i],i));
    // }
    // sort(lp.begin(), lp.end());
    // ll ans = 0;
    // rep(i,0,N+1){
    //     ll tt = 0;
    //     rep(j,0,i){
    //         tt += lp[j].first;
    //     }


    // }
    // sort(a,a+N);

    // ll min_val[2010] = {};
    // ll min_pos[2010] = {};
    // rep(i,0,N){
    //     min_val[i] = INF;
    //     min_pos[i] = -1;
    // }
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(i == j){
    //             if(min_val[i] > a[i]){
    //                 min_val[i] = a[i];
    //                 min_pos[i] = j;
    //             }
    //             // min_val[i] = min(min_val[i], a[i]);
    //         }else if(j < i){
    //             if(min_val[i] > a[j] + x * (i - j)){
    //                 min_val[i] = a[j] + x * (i - j);
    //                 min_pos[i] = j;
    //             }
    //             // min_val[i] = min(min_val[i], a[j] + x * (i - j));
    //         }else{
    //             if(min_val[i] > a[j] + x * (i + N - j)){
    //                 min_val[i] = a[j] + x * (i + N - j);
    //                 min_pos[i] = j;
    //             }
    //             // min_val[i] = min(min_val[i], a[j] + x * (i + N - j));
    //         }
    //     }
    // }
    // printa(min_val, N);
    // ll diff_max = 0;
    // ll diff_arr[100010] = {};
    // rep(i,0,N){
    //     if(i >= min_pos[i]){
    //         diff_max = max(diff_max, i - min_pos[i]);
    //     }else{
    //         diff_max = max(diff_max, i + N -min_pos[i]);
    //     }
    // }
    // ll ans = 0;
    // rep(i,0,N){
    //     ans += a[min_pos[i]];
    // }
    // ans += diff_max * x;
    print(ans);

    // print(diff_max);
    // printa(min_pos,N);
    // print(diff_max * x + )
}
