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
typedef struct {
    ll s;
    ll t;
    ll idx;
} pp;
ll N,M;
ll s[100010], t[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> s[i] >> t[i];
        s[i]--; t[i]--;
    }
    ll cnt[300010] = {};
    rep(i,0,M){
        cnt[s[i]]++;
        cnt[t[i]+1]--;
    }
    rep(i,0,N+1){
        cnt[i+1] += cnt[i];
    }
    ll sum[300010] = {};
    rep(i,0,N){
        if(cnt[i] == 1){
            sum[i+1] = sum[i] + 1;
        }else{
            sum[i+1] = sum[i];
        }
    }
    ll ans_cnt = 0;
    vector<ll> pos;
    rep(i,0,M){
        if(sum[t[i]+1] - sum[s[i]] == 0){
            ans_cnt++;
            pos.push_back(i);
        }
    }
    print(ans_cnt);
    rep(i,0,ans_cnt){
        print(pos[i]+1);
    }
}
