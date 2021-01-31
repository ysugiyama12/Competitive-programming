/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << "\n"
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja
template <class T> struct BellmanFord {
private:
    typedef struct {
        ll to;
        T d;
    } P;

    typedef struct {
        T dst;
        ll idx;
    } Q;

    vector< vector<P> > tree;
    ll N;
    vector<T> dist;

public:
    
    bool is_minus_loop = false;
    vector<bool> loop;

    BellmanFord(ll n){
        N = n;
        dist.assign(N, INF);
        tree.resize(N+1);
        loop.assign(N, false);
    }

    void add_edge(ll from, ll to, T cost, bool inv=false){
        tree[from].push_back({to, cost});
        if(inv){
            tree[to].push_back({from, cost});
        }
    }
    
    void build(ll s){
        dist[s] = 0;
        rep(i,0,N){
            rep(j,0,N){
                for(auto &e: tree[j]){
                    if(dist[j] == INF) continue;
                    if(dist[e.to] > dist[j] + e.d){
                        dist[e.to] = dist[j] + e.d;
                        if(i == N-1){
                            is_minus_loop = true;
                            loop[e.to] = true;
                        }
                    }
                }
            }
        }
    }

    ll operator[](int x){
        return dist[x];
    }
};

void solve(){
    ll N,M,r;
    cin >> N >> M >> r;
    vll a(M), b(M), c(M);
    BellmanFord<ll> bf(N);
    rep(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        bf.add_edge(a[i], b[i], c[i]);
    }
    bf.build(r);
    printa(bf.loop, N);
    if(bf.is_minus_loop == true){
        print("NEGATIVE CYCLE");
    }else{
        rep(i,0,N){
            if(bf[i] == INF){
                print("INF");
            }else{
                print(bf[i]);
            }
        }
    }


}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}