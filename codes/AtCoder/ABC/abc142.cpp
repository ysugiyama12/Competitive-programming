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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[2010], B[2010];
    vector<ll> tree[1010], tree_inv[1010];
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree_inv[B[i]].push_back(A[i]);
    }
    ll ans = INF, idx = -1, last_pos = -1;

    rep(i,0,N){
        queue<lpair> que;
        que.push({i, 0});
        bool visit[1010] = {};
        bool ok = false;
        while(not que.empty()){
            lpair l1 = que.front();
            que.pop();
            if(visit[l1.first]) continue;
            visit[l1.first] = true;
            for(auto &e: tree[l1.first]){
                if(not visit[e]){
                    que.push({e, l1.second+1});
                }else{
                    if(e == i){
                        if(ans > l1.second+1){
                            ans = l1.second+1;
                            idx = i;
                            last_pos = l1.first;
                        }
                        ok = true;
                        break;
                    }
                }
            }
            if(ok) break;
        }
    }

    if(idx == -1){
        print(-1);
        return 0;
    }

    ll dist[1010] = {};
    rep(i,0,N) dist[i] = INF;
    bool visit[1010] = {};
    queue<lpair> que;
    bool ok = false;
    que.push({idx, 0});
    while(not que.empty()){
        lpair l1 = que.front();
        que.pop();
        if(visit[l1.first]) continue;
        visit[l1.first] = true;
        dist[l1.first] = l1.second;
        for(auto &e: tree[l1.first]){
            if(not visit[e]){
                que.push({e, l1.second+1});
            }else{
                if(e == idx){
                    ok = true;
                    break;
                }
            }
        }
        if(ok) break;
    }

    ll pos = last_pos;
    vector<ll> res;
    while(1){
        res.push_back(pos);
        if(pos == idx) break;
        for(auto &e: tree_inv[pos]){
            if(dist[pos] == dist[e]+1){
                pos = e;
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    print(res.size());
    for(auto &e: res) print(e+1);
}