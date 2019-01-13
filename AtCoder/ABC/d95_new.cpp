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

    ll N,C;
    ll x[100010], v[100010];
    cin >> N >> C;
    rep(i,0,N){
        cin >> x[i] >> v[i];
    }
    ll sum[100010] = {}, sum_rev[100010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + v[i];
    }
    rep(i,0,N){
        sum_rev[i+1] = sum_rev[i] + v[N-1-i];
    }
    ll g1[100010] = {}, g2[100010] = {};
    rep(i,0,N){
        g1[i+1] = max(g1[i], sum[i+1] - x[i]);
        g2[i+1] = max(g2[i], sum[i+1] - 2 * x[i]);
    }
    ll ans = 0;
    rep(i,0,N){
        ans = max(ans, sum_rev[N-i] - 2 * (C - x[i]) + g1[i]);
        ans = max(ans, sum_rev[N-i] - (C - x[i]) + g2[i]);
    }
    ans = max(ans, g1[N]);
    print(ans);



    //ll f_a[100010];
    //f_a[0] = v[0] - x[0];
    //rep(i,1,N){
    //    f_a[i] = f_a[i-1] + v[i] + x[i-1] - x[i];
    //}
    //ll g_a[100010];
    //ll idx_a[100010];
    //g_a[0] = f_a[0];
    //idx_a[0] = 0;
    //rep(i,1,N){
    //    if(f_a[i] > g_a[i-1]){
    //        idx_a[i] = i;
    //    }else{
    //        idx_a[i] = idx_a[i-1];
    //    }
    //    g_a[i] = max(g_a[i-1], f_a[i]);
    //}

    //ll f_b[100010];
    //f_b[0] = v[N-1] - (C - x[N-1]);
    //rep(i,1,N){
    //    f_b[i] = f_b[i-1] + v[N-1-i] - x[N-i] + x[N-1-i];
    //}
    //ll g_b[100010];
    //ll idx_b[100010];
    //g_b[0] = f_b[0];
    //idx_b[0] = 0;
    //rep(i,1,N){
    //    if(f_b[i] > g_b[i-1]){
    //        idx_b[i] = i;
    //    }else{
    //        idx_b[i] = idx_b[i-1];
    //    }
    //    g_b[i] = max(g_b[i-1], f_b[i]);
    //}
    //ll ans = 0;
    //ans = max(ans, g_a[N-1]);
    //rep(i,0,N){
    //    if(i == 0){
    //        ans = max(ans, f_b[N-1]);
    //    }else{
    //        ll ans_tmp = 0;
    //        ans_tmp += g_a[i-1];
    //        ans_tmp += f_b[N-1-i];
    //        ll dist = min(C - x[i], x[idx_a[i-1]]);
    //        ans_tmp -= dist;
    //        ans = max(ans, ans_tmp);
    //    }
    //}
    //ans = max(ans, g_b[N-1]);
    //rep(i,0,N){
    //    if(i == N-1){
    //        ans = max(ans, f_a[N-1]);
    //    }else{
    //        ll ans_tmp = 0;
    //        ans_tmp += g_b[i+1];
    //        ans_tmp += f_a[i];
    //        ll dist = min(x[i], C - x[idx_b[i+1]]);
    //        ans_tmp -= dist;
    //        ans = max(ans, ans_tmp);
    //    }
    //}
    //print(ans);


    //vector<ll> x(N);
    //vector<ll> v(N);

    //rep(i, 0, N){
    //    cin >> x[i] >> v[i];
    //}

    //vector<ll> a_score(N);
    //vector<ll> b_score(N);
    //a_score[0] = v[0] - x[0];
    //b_score[N-1] = v[N-1] - (C - x[N-1]);
    //rep(i,1,N){
    //    a_score[i] = a_score[i-1] + v[i] - (x[i] - x[i-1]);
    //    b_score[N-i-1] = b_score[N-i] + v[N-i-1] - (x[N-i] - x[N-i-1]);
    //}
    //vector<int> max_idx(N);
    //max_idx[0] = 0;
    //rep(i,1,N){
    //    if(a_score[i] > a_score[max_idx[i-1]]){
    //        max_idx[i] = i;
    //    }else{
    //        max_idx[i] = max_idx[i-1];
    //    }
    //}
    //ll ans = 0;
    //rep(i,1,N){
    //    int a_idx = max_idx[i-1];
    //    ll score = a_score[a_idx] + b_score[i];
    //    score -= min(x[a_idx], C-x[i]);
    //    ans = max(ans, score);

    //}
    //ans = max(a_score[max_idx[N-1]],ans);
    //rep(i,0,N){
    //    ans = max(ans, b_score[i]);
    //}
    //print(ans);

}
