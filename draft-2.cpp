/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << "\n"

template <class T> struct Dijkstra {
private:
    typedef struct {
        ll to;
        T d;
    } P;

    typedef struct {
        T dst;
        ll idx;
    } Q;

    vector<P> tree[200010];
    ll N;
    vector<T> dist;

public:
    Dijkstra(ll n){
        N = n;
        dist.assign(N, 1e9);
    }

    void add_edge(ll from, ll to, T cost){
        tree[from].push_back({to, cost});
    }
    
    void execute(ll s){
        dist[s] = 0;
        priority_queue pq([](Q l1, Q l2){return l1.dst > l2.dst;}, vector<Q>());
        pq.push({0,s});
        while(!pq.empty()){
            Q l1 = pq.top();
            pq.pop();
            if(dist[l1.idx] < l1.dst) continue;
            for(auto &e: tree[l1.idx]){
                if(dist[e.to] <= dist[l1.idx] + e.d) continue;
                dist[e.to] = dist[l1.idx] + e.d;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    ll operator[](int x){
        return dist[x];
    }


};
Dijkstra<int> ds(200000), ds_inv(200000);

void solve(){
    ll N,M,T;
    cin >> N >> M >> T;
    ll A[100010];
    rep(i,0,N) cin >> A[i];

    rep(i,0,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        ds.add_edge(a, b, c);
        ds_inv.add_edge(b, a, c);
    }
    ds.execute(0);
    ds_inv.execute(0);
    ll ans = 0;
    rep(i,0,N){
        ans = max(ans, (T - (ds[i] + ds_inv[i])) * A[i]);
    }
    print(ans);

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}