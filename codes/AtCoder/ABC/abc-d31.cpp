#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
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
    ll K,N;
    string v[55], w[55];
    cin >> K >> N;
    rep(i,0,N){
        cin >> v[i] >> w[i];
    }
    string ans[10];
    rep(i,0,pow(3,K)){
        ll cnt[10];
        rep(i,0,K){
            cnt[i] = 1;
        }
        ll idx = 0;
        ll k = i;
        while(k > 0){
            cnt[idx] = k % 3 + 1;
            k /= 3;
            idx++;
        }
        // printa(cnt,K);
        ll s_len[10] = {};
        rep(j,0,K){
            s_len[j+1] = cnt[j];
        }
        bool is_ok = true;
        rep(j,0,N){
            ll w_len = w[j].size();
            ll v_len = 0;
            rep(k,0,v[j].size()){
                v_len += s_len[v[j][k] - '0'];
            }
            if(w_len != v_len){
                is_ok = false;
            }
        }
        rep(j,0,K+1){
            ans[j] = "";
        }
        if(is_ok){
            bool is_ans = true;
            rep(j,0,N){
                ll now_pos = 0;
                rep(k,0,v[j].size()){
                    ll num = v[j][k] - '0';
                    if(ans[num] == ""){
                        ans[num] = w[j].substr(now_pos, s_len[num]);
                    }else{
                        if(ans[num] != w[j].substr(now_pos, s_len[num])){
                            is_ans = false;
                        }
                    }
                    now_pos += s_len[num];
                }
            }
            if(is_ans){
                rep(i,0,K){
                    print(ans[i+1]);
                }
                return 0;

            }
        }
    }

}
