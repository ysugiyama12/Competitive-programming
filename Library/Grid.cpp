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
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef struct {
    ll h,w;
} P;

struct Grid {
private:
    ll dh[4] = {0,0,1,-1};
    ll dw[4] = {1,-1,0,0};

public:

    vector< vector<ll> > dist;
    ll H,W;
    vector<string> a;

    Grid(){}

    void init(ll h, ll w){
        H = h; W = w;
        dist.resize(H+1, vector<ll>(W+1));
        rep(i,0,H) rep(j,0,W) dist[i][j] = INF;
        a.resize(H+1);
    }

    void bfs(P start){
        dist[start.h][start.w] = 0;
        queue<P> que;
        que.push(start);
        while(not que.empty()){
            P cur = que.front();
            que.pop();
            ll d_cur = dist[cur.h][cur.w];
            rep(k,0,4){
                P nxt = {cur.h + dh[k], cur.w + dw[k]};
                if(in_grid(nxt) && a[nxt.h][nxt.w] == '.' && dist[nxt.h][nxt.w] == INF){
                    dist[nxt.h][nxt.w] = d_cur + 1;
                    que.push(nxt);
                }
            }
        }
    }

    bool in_grid(P p){
        if(p.h >= 0 && p.h < H && p.w >= 0 && p.w < W){
            return true;
        }
        return false;
    }

    void vis_map(){
        rep(i,0,H){
            rep(j,0,W){
                if(a[i][j] == '#'){
                    cout << "# ";
                }else if(dist[i][j] == INF){
                    cout << "x ";
                }else{
                    cout << left << setw(2) << dist[i][j];
                }
                cout << " \n"[j==W-1];
            }
        }  
    }
} grid;


void solve(){
    ll H,W;
    cin >> H >> W;
    grid.init(H,W);
    P start, goal;
    cin >> start.h >> start.w;
    cin >> goal.h >> goal.w;
    start.h--; start.w--;
    goal.h--; goal.w--;
    rep(i,0,grid.H) cin >> grid.a[i];
    grid.bfs(start);
    ll ans = grid.dist[goal.h][goal.w];

    if(ans == INF){
        print(-1);
    }else{
        print(ans);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}