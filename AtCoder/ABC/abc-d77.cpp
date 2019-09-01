/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll dist[100010] = {};
vector<lpair> edge[100010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    rep(i,0,K){
        ll after = (i+1) % K;
        edge[i].push_back(make_pair(after, 1));
        after = i * 10 % K;
        edge[i].push_back(make_pair(after, 0));
    }
    fill(dist, dist+K, INF);
    dist[1] = 0;
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq;
    rep(i,0,K) pq.push(make_pair(dist[i], i));
    while(not pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        for(auto &e: edge[l1.second]) {
            if(dist[e.first] > dist[l1.second] + e.second){
                dist[e.first] = dist[l1.second] + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    print(dist[0] + 1);
    
}