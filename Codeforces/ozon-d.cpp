/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vector<ll> tree[1010];
bool ok[1010] = {};
ll dist[1010] = {};
bool rem[1010] = {};

void dfs(ll cur, ll par, ll d){
    dist[cur] = d;
    for(auto &e: tree[cur]){
        if(e == par || ok[e] == false) continue;
        dfs(e, cur, d+1);
    }
}

bool dfs2(ll cur, ll par, ll dest){
    bool flg = false;
    for(auto &e: tree[cur]){
        if(e == par || ok[e] == false) continue;
        flg |= dfs2(e, cur, dest);
    }
    if(cur == dest){
        flg = true;
    }
    if(flg){
        rem[cur] = true;
    }
    return flg;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll u[1010], v[1010];

    rep(i,0,N-1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
        tree[v[i]].push_back(u[i]);
    }
    rep(i,0,N) ok[i] = true;
    ll M = N / 2;
    ll nxt = 0;
    rep(m,0,M+1){
        ll start = nxt;
        memset(dist, -1, sizeof(dist));
        dfs(start, -1, 0);
        ll max_pos = -1, max_pos2 = -1, max_val = -1;
        rep(i,0,N){
            if(ok[i]){
                if(max_val < dist[i]){
                    max_val = dist[i];
                    max_pos = i;
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        dfs(max_pos, -1, 0);
        max_val = -1;
        rep(i,0,N){
            if(ok[i]){
                if(max_val < dist[i]){
                    max_val = dist[i];
                    max_pos2 = i;
                }
            }
        }
        if(max_pos == max_pos2){
            cout << "! " << max_pos+1 << endl;
            return 0;
        }else{
            cout << "? " << max_pos+1 << " " << max_pos2+1 << endl;
            ll w = 0;
            cin >> w;
            w--;
            rep(i,0,N) rem[i] = false;
            bool res = dfs2(w, -1, max_pos);
            res = dfs2(w, -1, max_pos2);
            // printa(rem, N);
            rep(i,0,N){
                if(rem[i]) ok[i] = false;
            }
            ok[w] = true;
            nxt = w;
        }
    }
    

}