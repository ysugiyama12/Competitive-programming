#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
struct compare{
    bool operator() (lpair l1, lpair l2){
        // be careful of the opetator!
         if(l1.second == l2.second){
             return l1.first < l2.first;
         }
         return l1.second < l2.second;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll p[20], q[20], c[20];
    cin >> N >> M;
    vector<lpair> tree[20];
    rep(i,0,M){
        cin >> p[i] >> q[i] >> c[i];
        p[i]--; q[i]--;
        tree[p[i]].push_back(make_pair(q[i], c[i]));
        tree[q[i]].push_back(make_pair(p[i], c[i]));
    }
    priority_queue<lpair, vector<lpair> ,greater<lpair> > pq;
    
    // priority_queue<lpair, vector<lpair> ,compare > pq;
    ll dist[100010] = {};
    rep(i,1,N) dist[i] = INF;
    pq.push({0,0});
    while(!pq.empty()){
        lpair l1 = pq.top();
        pq.pop();
        if(dist[l1.second] < l1.first) continue;
        for(auto &e: tree[l1.second]){
            if(dist[e.first] > dist[l1.second] + e.second){
                dist[e.first] = dist[l1.second] + e.second;
                pq.push(make_pair(dist[e.first], e.first));
            }
        }
    }
    print(dist[N-1]);


}
