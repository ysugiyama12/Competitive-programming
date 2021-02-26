#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
ll N,K;
ll A[2010], B[2010];
vector<ll> tree[2010];
ll ans = INF;
ll tt = 0;

void dfs1(ll cur, ll par, ll depth){
    if(depth > K/2) tt++;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs1(e, cur, depth+1);
    }
}

void dfs2(ll cur, ll par, ll depth){
    if(depth > (K-1)/2) tt++;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs1(e, cur, depth+1);
    }
}

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i,0,N-1){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree[B[i]].push_back(A[i]);
    }
    if(K % 2 == 0){
        rep(i,0,N){
            tt = 0;
            dfs1(i, -1, 0);
            ans = min(ans, tt);
        }
        print(ans);
    }else{
        rep(i,0,N-1){
            tt = 0;
            dfs2(A[i], B[i], 0);
            dfs2(B[i], A[i], 0); 
            ans = min(ans, tt);
        }
        print(ans);
    }
}
