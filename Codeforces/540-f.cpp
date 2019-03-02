#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll cnt_b = 0, cnt_r = 0;
ll N;
ll A[300010];
vector<lpair> lp(300010);
vector<ll> tree[300010];
void dfs(ll cur, ll par){
    ll red = 0, blue = 0;
    if(A[cur] == 1){
        red++;
    }else if(A[cur] == 2){
        blue++;
    }
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur);
        red += lp[e].first;
        blue += lp[e].second;
    }
    lp[cur] = make_pair(red, blue);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N) cin >> A[i];
    rep(i,0,N-1){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    rep(i,0,N){
        if(A[i] == 1){
            cnt_r++;
        }else if(A[i] == 2){
            cnt_b++;
        }
    }
    dfs(0,-1);
    ll ans = 0;
    rep(i,1,N){
        if(lp[i].first * lp[i].second == 0){
            if((cnt_r - lp[i].first) * (cnt_b - lp[i].second) == 0){
                ans++;
            }
        }

    }
    print(ans);
    // print("--");
    // rep(i,0,N){
    //     print2(lp[i].first, lp[i].second);
    // }




}
