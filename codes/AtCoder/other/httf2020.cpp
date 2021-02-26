/*** author: yuji9511 ***/
#include <bits/stdc++.h>
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
typedef struct {
    ll y;
    ll x;
    ll d;
    char dir;
} P;

typedef struct {
    ll y;
    ll x;
    char d;
} Q;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,B;
    cin >> N >> M >> B;
    ll gy,gx;
    cin >> gy >> gx;
    ll ry[110], rx[110];
    char c[110];
    rep(i,0,M) cin >> ry[i] >> rx[i] >> c[i];
    ll by[310], bx[310];
    rep(i,0,B) cin >> by[i] >> bx[i];
    char s[41][41];
    rep(i,0,N){
        rep(j,0,N){
            s[i][j] = '.';
        }
    }
    rep(i,0,B){
        s[by[i]][bx[i]] = '#';
    }
    rep(i,0,M){
        s[ry[i]][rx[i]] = c[i];
    }
    ll dist[41][41] = {};
    s[gy][gx] = 'g';
    ll min_val = INF;
    vector<Q> ans_true;
    ll dy[4] = {-1,0,0,1};
    ll idx = 0;
    do{
        idx++;
        rep(t,0,2){
            ll dx[4];
            bool zero = false;
            rep(i,0,4){
                if(dy[i] != 0){
                    dx[i] = 0;
                }else{
                    if(t == 0){
                        dx[i] = (zero) ? 1 : -1;
                    }else{
                        dx[i] = (zero) ? -1 : 1;
                    }
                    zero = true;
                }
            }
            char dd[4];
            rep(i,0,4){
                if(dy[i] == 1 && dx[i] == 0) dd[i] = 'U';
                if(dy[i] == -1 && dx[i] == 0) dd[i] = 'D';
                if(dy[i] == 0 && dx[i] == 1) dd[i] = 'L';
                if(dy[i] == 0 && dx[i] == -1) dd[i] = 'R';
            }
            bool visit[41][41] = {};
            rep(i,0,N){
                rep(j,0,N){
                    dist[i][j] = -1;
                }
            }
            queue<P> que;
            que.push((P){gy, gx, 0, '*'});
            char lr[41][41];
            rep(i,0,N) rep(j,0,N) lr[i][j] = '#';
            while(not que.empty()){
                P p1 = que.front();
                que.pop();
                if(visit[p1.y][p1.x]) continue;
                visit[p1.y][p1.x] = true;
                dist[p1.y][p1.x] = p1.d;
                lr[p1.y][p1.x] = p1.dir;
                rep(k,0,4){
                    ll k2 = (k - idx + 100) % 4;
                    ll y2 = (p1.y + dy[k2] + N) % N;
                    ll x2 = (p1.x + dx[k2] + N) % N;
                    while(1){
                        if(visit[y2][x2] == true || s[y2][x2] == '#') break;
                        que.push((P){y2, x2, p1.d+1, dd[k2]});
                        y2 = (y2 + dy[k] + N) % N;
                        x2 = (x2 + dx[k] + N) % N;
                    }
                }
            }

            bool impossible[110] = {};
            rep(i,0,M){
                if(dist[ry[i]][rx[i]] == -1) impossible[i] = true;
            }

            vector<Q> ans;
            rep(i,0,N){
                rep(j,0,N){
                    if(lr[i][j] != '#' && lr[i][j] != '*'){
                        ans.push_back((Q){i, j, lr[i][j]});
                    }
                }
            }
            // print(ans.size());
            // for(auto &e: ans){
            //     print(e.y, e.x, e.d);
            // }
            // return 0;



            char stage[41][41];
            rep(i,0,N)rep(j,0,N) stage[i][j] = '.';
            stage[gy][gx] = 'g';
            rep(i,0,B) stage[by[i]][bx[i]] = '#';
            for(auto &e: ans){
                stage[e.y][e.x] = e.d;
            }
            vector<Q> ans_good;

            for(auto &e: ans){
                stage[e.y][e.x] = '.';
                bool ok = true;
                rep(i,0,M){
                    if(impossible[i]) continue;
                    ll py = ry[i], px = rx[i];
                    char muki = c[i];
                    bool itta[41][41] = {};
                    while(1){
                        if(itta[py][px]){
                            ok = false;
                            break;
                        }
                        itta[py][px] = true;
                        if(stage[py][px] == 'g'){
                            break;
                        }
                        if(stage[py][px] == '.'){
                            if(muki == 'R'){
                                px = (px+1)%N;
                            }else if(muki == 'L'){
                                px = (px-1+N)%N;
                            }else if(muki == 'U'){
                                py = (py-1+N)%N;
                            }else if(muki == 'D'){
                                py = (py+1)%N;
                            }
                        }else{
                            muki = stage[py][px];
                            if(stage[py][px] == 'R'){
                                px = (px+1)%N;
                            }else if(stage[py][px] == 'L'){
                                px = (px-1+N)%N;
                            }else if(stage[py][px] == 'U'){
                                py = (py-1+N)%N;
                            }else if(stage[py][px] == 'D'){
                                py = (py+1)%N;
                            }
                        }
                        if(stage[py][px] == '#'){
                            ok = false;
                            break;
                        }
                    }
                }
                if(not ok){
                    ans_good.push_back(e);
                    stage[e.y][e.x] = e.d;
                }
            }
            ll cnt = 0;
            bool itta2[41][41] = {};

            rep(i,0,M){
                if(impossible[i]) continue;
                ll py = ry[i], px = rx[i];
                char muki = c[i];
                while(1){
                    if(itta2[py][px]){
                        break;
                    }
                    itta2[py][px] = true;
                    if(stage[py][px] == 'g'){
                        break;
                    }
                    if(stage[py][px] == '.'){
                        if(muki == 'R'){
                            px = (px+1)%N;
                        }else if(muki == 'L'){
                            px = (px-1+N)%N;
                        }else if(muki == 'U'){
                            py = (py-1+N)%N;
                        }else if(muki == 'D'){
                            py = (py+1)%N;
                        }
                    }else{
                        muki = stage[py][px];
                        if(stage[py][px] == 'R'){
                            px = (px+1)%N;
                        }else if(stage[py][px] == 'L'){
                            px = (px-1+N)%N;
                        }else if(stage[py][px] == 'U'){
                            py = (py-1+N)%N;
                        }else if(stage[py][px] == 'D'){
                            py = (py+1)%N;
                        }
                    }
                    if(stage[py][px] == '#'){
                        break;
                    }
                }
            }
            rep(i,0,N){
                rep(j,0,N){
                    if(itta2[i][j]) cnt++;
                }
            }
            ll score = ans_good.size() * 10 - cnt;
            if(min_val > score){
                min_val = score;
                ans_true = ans_good;
            }
        }
    }while(next_permutation(dy, dy+4));

    char stage2[41][41];
    rep(i,0,N){
        rep(j,0,N){
            stage2[i][j] = '.';
        }
    }
    rep(i,0,B) stage2[by[i]][bx[i]] = '#';
    for(auto &e: ans_true){
        stage2[e.y][e.x] = e.d;
    }
    stage2[gy][gx] = 'g';
    vector<Q> ans_new;
    for(auto &e: ans_true){
        ll py = e.y, px = e.x;
        ll cntL = 0, cntR = 0, cntU = 0, cntD = 0;
        while(1){
            py = (py-1+N)%N;
            if(stage2[py][px] != '.') break;
            cntU++;
        }
        py = e.y; px = e.x;
        while(1){
            py = (py+1+N)%N;
            if(stage2[py][px] != '.') break;
            cntD++;
        }
        py = e.y; px = e.x;
        while(1){
            px = (px-1+N)%N;
            if(stage2[py][px] != '.') break;
            cntL++;
        }
        py = e.y; px = e.x;
        while(1){
            px = (px+1+N)%N;
            if(stage2[py][px] != '.') break;
            cntR++;
        }
        py = e.y; px = e.x;


        if(e.d == 'U'){
            ll max_val = max({cntR, cntL, cntD, cntU});
            if(max_val == cntL){
                char cc = stage2[py][(px - cntL - 1 + 2*N) % N];
                if(cc != 'R' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'L'});
                    stage2[py][px] = 'L';
                    continue;
                }
            }else if(max_val == cntR){
                char cc = stage2[py][(px + cntR + 1 + 2*N) % N];
                if(cc != 'L' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'R'});
                    stage2[py][px] = 'R';
                    continue;
                }
            }else if(max_val == cntD){
                char cc = stage2[(py + cntD + 1) % N][px];
                if(cc != 'U' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'D'});
                    stage2[py][px] = 'D';
                    continue;
                }
            }
        }else if(e.d == 'D'){
            ll max_val = max({cntR, cntL, cntD, cntU});
            if(max_val == cntL){
                char cc = stage2[py][(px - cntL - 1 + 2*N) % N];
                if(cc != 'R' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'L'});
                    stage2[py][px] = 'L';
                    continue;
                }
            }else if(max_val == cntR){
                char cc = stage2[py][(px + cntR + 1 + 2*N) % N];
                if(cc != 'L' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'R'});
                    stage2[py][px] = 'R';
                    continue;
                }
            }else if(max_val == cntU){
                char cc = stage2[(py - cntU - 1 + 2*N) % N][px];
                if(cc != 'D' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'U'});
                    stage2[py][px] = 'U';
                    continue;
                }
            }           
        }else if(e.d == 'R'){
            ll max_val = max({cntR, cntL, cntD, cntU});
            if(max_val == cntL){
                char cc = stage2[py][(px - cntL - 1 + 2*N) % N];
                if(cc != 'R' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'L'});
                    stage2[py][px] = 'L';
                    continue;
                }
            }else if(max_val == cntD){
                char cc = stage2[(py + cntD + 1) % N][px];
                if(cc != 'U' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'D'});
                    stage2[py][px] = 'D';
                    continue;
                }
            }else if(max_val == cntU){
                char cc = stage2[(py - cntU - 1 + 2*N) % N][px];
                if(cc != 'D' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'U'});
                    stage2[py][px] = 'U';
                    continue;
                }
            }           
        }else if(e.d == 'L'){
            ll max_val = max({cntR, cntL, cntD, cntU});
            if(max_val == cntR){
                char cc = stage2[py][(px + cntR + 1) % N];
                if(cc != 'L' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'R'});
                    stage2[py][px] = 'R';
                    continue;
                }
            }else if(max_val == cntD){
                char cc = stage2[(py + cntD + 1) % N][px];
                if(cc != 'U' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'D'});
                    stage2[py][px] = 'D';
                    continue;
                }
            }else if(max_val == cntU){
                char cc = stage2[(py - cntU - 1 + 2*N) % N][px];
                if(cc != 'D' && cc != '#'){
                    ans_new.push_back((Q){py, px, 'U'});
                    stage2[py][px] = 'U';
                    continue;
                }
            }           
        }
        ans_new.push_back(e);
    }

    print(ans_new.size());
    for(auto &e: ans_new){
        print(e.y, e.x, e.d);
    }



    

}
