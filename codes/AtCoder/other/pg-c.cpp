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
#define print(x) cout << (x) << endl;
#define print2(x, y) cout << (x) << " " << (y) << endl;
vector<ll> tree[200010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[200010], B[200010];
    rep(i,0,M){
        cin >> A[i] >> B[i];
        tree[B[i]].push_back(A[i]);
    }
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    ll dist[200010] = {};
    rep(i,1,N+1) dist[i] = INF;
    rep(i,0,N+1) pq.push(make_pair(dist[i], i));
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        for(auto &e: tree[l1.second]){
            if(dist[e] > dist[l1.second] + 1){
                dist[e] = dist[l1.second] + 1;
                pq.push(make_pair(dist[e], e));
            }
        }
    }
    rep(i,1,N+1){
        if(dist[i] <= 3){
            print("Yes");
        }else{
            print("No");
        }
    }
}