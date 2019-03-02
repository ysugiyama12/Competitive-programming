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
vector< pair<ll, double> > tree[1010];
double dist[10010] = {};
ll prever[10010] = {};
vector<ll> get_path(ll t){ //頂点tへの最短路
    vector<ll> path;
    for(; t != -1;t=prever[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D;
    ll X[1010], Y[1010];
    cin >> N >> D;
    rep(i,0,N) cin >> X[i] >> Y[i];
    rep(i,0,N){
        rep(j,0,N){
            if(i == j) continue;
            double dist = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
            if(dist <= D){
                tree[i].push_back(make_pair(j, dist));
                tree[j].push_back(make_pair(i, dist));
            }
        }
    }
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    rep(i,1,N){
        dist[i] = INF;
    }
    rep(i,0,N){
        pq.push(make_pair(dist[i], i));
    }
    rep(i,0,N) prever[i] = -1;
    while(!pq.empty()){
        pair<double, ll> l1 = pq.top();
        ll cur = l1.second;
        pq.pop();
        if(dist[cur] < l1.first) continue;
        for(auto &e: tree[l1.second]){
            if(dist[e.first] > dist[l1.second] + e.second){
                // if(!is_visit[e.first]){
                    dist[e.first] = dist[l1.second] + e.second;
                    prever[e.first] = cur;
                    pq.push(make_pair(dist[e.first], e.first));
                // }
            }
        }
    }
    vector<ll> ans = get_path(N-1);
    rep(i,0,ans.size()){
        print(ans[i]+1);
    }
    // print(dist[N-1]);
    // printa(dist, N);


}
