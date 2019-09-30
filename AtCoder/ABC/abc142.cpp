/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class H, class... T>
void print(H&& head, T&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<T>(tail)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[1010], B[1010];
    vector<ll> tree[1010];
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
    }

    ll ans = N+1;
    vector<ll> res;
    rep(i,0,N){
        ll dist[1010] = {};
        ll prev[1010] = {};
        fill(dist, dist+N, -1);
        queue<ll> que;
        que.push(i);
        dist[i] = 0;
        while(not que.empty()){
            ll p = que.front();
            que.pop();
            for(auto &e: tree[p]){
                if(dist[e] != -1) continue;
                dist[e] = dist[p] + 1;
                prev[e] = p;
                que.push(e);

            }
        }
        printa(dist, N);
        ll max_val = 0;
        rep(j,0,N) max_val = max(max_val, dist[j]);
        vector<ll> tmp;
        if(max_val < ans){
            ans = max_val;
            rep(j,0,N){
                if(dist[j] == max_val){
                    for(auto &e: tree[j]){
                        if(e == i){
                            ll cur = j;
                            while(1){
                                tmp.push_back(cur);
                                if(cur == i) break;
                                cur = prev[cur];
                            }
                            res = tmp;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(ans == N+1){
        print(-1);
        return 0;
    }
    print(ans+1);
    for(auto &e: res) print(e+1);

    
}