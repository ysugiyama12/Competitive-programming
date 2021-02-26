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
ll a[100010], b[100010];
ll v[100010], d[100010], c[100010];
vector<ll> tree[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }

    ll Q;
    cin >> Q;
    rep(i,0,Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    if(N > 2000 || M > 2000 || Q > 2000) return 0;
    ll color[100010] = {};
    rep(i,0,Q){
        ll dist[2010] = {};
        rep(i,0,N) dist[i] = -1;
        queue<lpair> que;
        que.push({v[i], 0});
        while(not que.empty()){
            lpair l1 = que.front();
            que.pop();
            if(dist[l1.first] != -1) continue;
            dist[l1.first] = l1.second;
            color[l1.first] = c[i];
            if(l1.second == d[i]) continue;
            for(auto &e: tree[l1.first]){
                if(dist[e] == -1){
                    que.push({e, l1.second+1});
                }
            }
        }
    }
    rep(i,0,N) print(color[i]);

    

}