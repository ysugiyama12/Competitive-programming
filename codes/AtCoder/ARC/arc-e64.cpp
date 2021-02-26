#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, double> lpair;
typedef pair<double, ll> lpair2;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    double xs, ys, xt, yt;
    ll N;
    double x[1010], y[1010], r[1010];
    cin >> xs >> ys >> xt >> yt;
    cin >> N;
    rep(i,1,N+1) cin >> x[i] >> y[i] >> r[i];
    x[0] = xs; y[0] = ys, r[0] = 0;
    x[N+1] = xt; y[N+1] = yt; r[N+1] = 0;
    vector<lpair> tree[1010];
    rep(i,0,N+2){
        rep(j,0,N+2){
            if(i == j) continue;
            double dist = sqrt(pow(x[i] - x[j],2) + pow(y[i] - y[j], 2));
            double hankei = r[i] + r[j];
            dist = max(0.0, dist - hankei);
            tree[i].push_back(make_pair(j, dist));
        }
    }

    priority_queue<lpair2, vector<lpair2> ,greater<lpair2> > pq;
    double dist[1010] = {};
    rep(i,1,N+2) dist[i] = INF;
    rep(i,0,N+2) pq.push(make_pair(dist[i], i));
    ll is_visit[1010] = {};
    while(!pq.empty()){
        lpair2 l1 = pq.top();
        pq.pop();
        is_visit[l1.second] = 1;
        for(auto &e: tree[l1.second]){
            if(dist[e.first] > dist[l1.second] + e.second){
                if(!is_visit[e.first]){
                    dist[e.first] = dist[l1.second] + e.second;
                    pq.push(make_pair(dist[e.first], e.first));
                }
            }
        }
    }
    // printa(dist, N+2);
    cout << setprecision(12) << dist[N+1] << endl;
}
