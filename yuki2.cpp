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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
ll a[100010], b[100010], c[100010];
vector<lpair> tree[2010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,P,Q,T;
    cin >> N >> M >> P >> Q >> T;
    P--; Q--;
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(make_pair(b[i], c[i]));
        tree[b[i]].push_back(make_pair(a[i], c[i]));
    }
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    ll dist[2010] = {};
    rep(i,1,N) dist[i] = INF;
    rep(i,0,N) pq.push(make_pair(dist[i], i));
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

    ll distP[2010] = {};
    rep(i,0,N) distP[i] = INF;
    distP[P] = 0;
    rep(i,0,N) pq.push(make_pair(dist[i], i));
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        for(auto &e: tree[l1.second]){
            if(distP[e.first] > distP[l1.second] + e.second){
                distP[e.first] = distP[l1.second] + e.second;
                pq.push(make_pair(distP[e.first], e.first));
            }
        }
    }

    ll distQ[2010] = {};
    rep(i,0,N) distQ[i] = INF;
    distQ[Q] = 0;
    rep(i,0,N) pq.push(make_pair(dist[i], i));
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        for(auto &e: tree[l1.second]){
            if(distQ[e.first] > distQ[l1.second] + e.second){
                distQ[e.first] = distQ[l1.second] + e.second;
                pq.push(make_pair(distQ[e.first], e.first));
            }
        }
    }
    ll ans = -INF;
    rep(i,0,N){
        rep(j,0,N){
            ll dd = dist[i] + max(distP[i] + distP[j], distQ[i] + distQ[j]) + dist[j];
            if(dd <= T){
                ans = max(ans, T - max(distP[i] + distP[j], distQ[i] + distQ[j]));
            }
        }
    }
    if(dist[P] + distP[Q] + dist[Q] <= T){
        print(T);
        return 0;
    }
    if(ans == -INF){
        print(-1);
    }else{
        print(ans);
    }
    
}