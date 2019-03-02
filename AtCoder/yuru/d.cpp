#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
// typedef struct {
//     ll to;
//     ll cost;
// } ee;
vector<lpair> tree[10010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll s[10010], t[10010], c[10010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> s[i] >> t[i] >> c[i];
        s[i]--; t[i]--;
        tree[s[i]].push_back(make_pair(t[i], c[i]));
        tree[t[i]].push_back(make_pair(s[i], c[i]));
    }
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    ll dist[10010] = {};
    ll num[10010] = {};
    num[0] = 1;
    rep(i,1,N){
        dist[i] = INF;
    }
    rep(i,0,N){
        pq.push(make_pair(dist[i], i));
    }
    ll is_visit[10010] = {};
    while(!pq.empty()){
        lpair l1 = pq.top();
        ll cur = l1.second;
        pq.pop();
        if(dist[cur] < l1.first) continue;
        // is_visit[l1.second] = 1;
        for(auto &e: tree[l1.second]){
            if(dist[e.first] > dist[l1.second] + e.second){
                // if(!is_visit[e.first]){
                    dist[e.first] = dist[l1.second] + e.second;
                    pq.push(make_pair(dist[e.first], e.first));
                    num[e.first] = num[l1.second];
                // }
            }else if(dist[e.first] == dist[l1.second] + e.second){
                num[e.first] += num[l1.second];
                num[e.first] %= MOD;
            }
        }
    }
    print(num[N-1]);

}
