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
vector<ll> tree[100010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll u[100010], v[100010];
    rep(i,0,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        tree[u[i]].push_back(v[i]);
    }
    ll S,T;
    cin >> S >> T;
    S--; T--;
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    ll dist[100010][3] = {};
    rep(i,0,N){
        rep(j,0,3){
            dist[i][j] = INF;
        }
    }
    dist[S][0] = 0;
    rep(i,0,N){
        rep(j,0,3){
            pq.push(make_pair(dist[i][j], i + 1000000 * j));
        }
    }
    while(!pq.empty()){
        lpair l1 = pq.top();
        ll dd = l1.first;
        ll idx = l1.second % 1000000;
        ll mode = l1.second / 1000000;
        pq.pop();
        for(auto &e: tree[idx]){
            ll nxt = (mode + 1) % 3;
            if(dist[e][nxt] > dist[idx][mode] + 1){
                dist[e][nxt] = dist[idx][mode] + 1;
                pq.push(make_pair(dist[e][nxt], e + 1000000 * nxt));
            }
        }
    }
    if(dist[T][0] == INF){
        print(-1);
    }else{
        print(dist[T][0]/3);
    }

    
}