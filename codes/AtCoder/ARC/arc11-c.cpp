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
    string S,T;
    cin >> S >> T;
    ll N;
    cin >> N;
    string a[1010];
    a[0] = S;
    a[1] = T;
    rep(i,0,N) cin >> a[i+2];
    ll len = S.size();
    vector<lpair> tree[1010];
    rep(i,0,N+2){
        rep(j,0,N+2){
            if(a[i] == a[j]){
                tree[i].push_back({j,0});
                tree[j].push_back({i,0});   
            }
            ll diff = 0;
            rep(k,0,len){
                if(a[i][k] != a[j][k]) diff++;
            }
            if(diff == 1){
                tree[i].push_back({j,1});
                tree[j].push_back({i,1});
            }
        }
    }
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq;
    ll dist[1010] = {};
    rep(i,1,N+2) dist[i] = INF;
    rep(i,0,N+2) pq.push({dist[i], i});
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        for(auto &e: tree[l1.second]){
            if(dist[e.first] > dist[l1.second] + e.second){
                dist[e.first] = dist[l1.second] + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    if(dist[1] == INF){
        print(-1);
        return 0;
    }
    if(dist[1] == 0){
        print(0);
        print(S);
        print(T);
        return 0;
    }
    vector<ll> v;
    ll pos = 1;
    while(1){
        v.push_back(pos);
        if(pos == 0) break;
        for(auto &e: tree[pos]){
            if(dist[pos] == dist[e.first] + 1){
                pos = e.first;
            }
        }
    }
    reverse(v.begin(), v.end());
    ll sz = v.size();
    print(sz-2);
    print(S);
    rep(i,0,sz-2){
        print(a[v[i+1]]);
    }
    print(T);


}