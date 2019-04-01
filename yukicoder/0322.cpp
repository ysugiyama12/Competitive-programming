#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
typedef pair<ll, lpair> lpair2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[100010], B[100010], C[100010];
    vector<lpair> tree[100010];
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(make_pair(B[i], C[i]));
        tree[B[i]].push_back(make_pair(A[i], C[i]));
    }
    ll dist1[100010] = {};
    rep(i,1,N) dist1[i] = INF;
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq;
    rep(i,0,N) pq.push(make_pair(dist1[i], i));
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        ll cur = l1.second;
        for(auto &e: tree[cur]){
            if(dist1[e.first] > dist1[cur] + e.second){
                dist1[e.first] = dist1[cur] + e.second;
                pq.push(make_pair(dist1[e.first], e.first));
            }
        }
    }
    ll dist2[100010] = {};
    rep(i,1,N) dist2[i] = INF;
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq2;
    rep(i,0,N) pq.push(make_pair(dist2[i], i));
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        ll cur = l1.second;
        for(auto &e: tree[cur]){
            ll v = min(dist2[cur] + e.second, dist1[cur]);
            if(dist2[e.first] > v){
                dist2[e.first] = v;
                pq.push(make_pair(dist2[e.first], e.first));
            }
        }
    }
    rep(i,0,N){
        print(dist1[i] + dist2[i]);
    }    
}