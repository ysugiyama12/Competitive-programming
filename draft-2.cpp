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

    ll dist[2010][2010];
    ll H,W;
    string a[2010];

    Grid(){}

    void bfs(P start){
        Fill(dist, INF);
        dist[start.h][start.w] = 0;
        bool done[30] = {};
        vector<P> pos[30];
        rep(i,0,H){
            rep(j,0,W){
                if(a[i][j] >= 'a' && a[i][j] <= 'z'){
                    pos[a[i][j]-'a'].push_back({i,j});
                }
            }
        }

        queue<P> que;
        que.push(start);
        while(not que.empty()){
            P cur = que.front();
            que.pop();
            ll d_cur = dist[cur.h][cur.w];
            rep(k,0,4){
                P nxt = {cur.h + dh[k], cur.w + dw[k]};
                if(in_map(nxt) && a[nxt.h][nxt.w] != '#' && dist[nxt.h][nxt.w] == INF){
                    dist[nxt.h][nxt.w] = d_cur + 1;
                    que.push(nxt); 
                }
            }
            char c = a[cur.h][cur.w];
            if(c >= 'a' && c <= 'z'){
                if(done[c - 'a']) continue;
                done[c - 'a'] = true;
                for(auto &e: pos[c - 'a']){
                    if(dist[e.h][e.w] == INF){
                        dist[e.h][e.w] = d_cur + 1;
                        que.push(e);
                    }
                }

            }
        }
    }

    bool in_map(P p){
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
    grid.H = H; grid.W = W;
    rep(i,0,H) cin >> grid.a[i];
    P start, goal;
    rep(i,0,H){
        rep(j,0,W){
            if(grid.a[i][j] == 'S'){
                start = {i,j};
            }else if(grid.a[i][j] == 'G'){
                goal = {i,j};
            }
        }
    }

    grid.bfs(start);
    // grid.vis_map();
    if(grid.dist[goal.h][goal.w] == INF){
        print(-1);
    }else{
        print(grid.dist[goal.h][goal.w]);
    }
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}