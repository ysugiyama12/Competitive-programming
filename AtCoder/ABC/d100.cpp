#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    ll x[1001], y[1001], z[1001];
    rep(i,0,N){
        ll t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        x[i] = t1;
        y[i] = t2;
        z[i] = t3;
    }
    ll ans = 0;
    rep(i,0,2){
        rep(j,0,2){
            rep(k,0,2){
                ll sum[1001] = {0};
                rep(m,0,N){
                    ll xt = (i == 1) ? x[m] : x[m] * -1;
                    ll yt = (j == 1) ? y[m] : y[m] * -1;
                    ll zt = (k == 1) ? z[m] : z[m] * -1;
                    sum[m] = xt+yt+zt;
                }
                sort(sum, sum+N);

                ll ans_tmp = 0;
                rep(m,0,M){
                    ans_tmp += sum[N - m - 1];
                }
                ans = max(ans, ans_tmp);
            }
        }
    }
    print(ans);
}
