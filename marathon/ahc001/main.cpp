/*** author: yuji9511 ***/
#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = int;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
void eprint() {}
template <class H,class... T>
void eprint(H&& h, T&&... t){cerr<<h<<" \n"[sizeof...(t)==0];eprint(forward<T>(t)...);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// variables
double timeLimit = 500;
ll N;
vll X,Y,R;
typedef struct{ ll a,b,c,d; } Q;
vector<Q> ans;
vector<vector<bool> > use;
ll W = 10000;
ll L = 1; // 一辺の長さ
ll M = 10000 / L; // 縦横のマス目の数
ll ca[10010] = {}, cb[10010] = {}, cc[10010] = {}, cd[10010] = {};
ll iter = 0;
ll PR;

// utils
mt19937 mrand(random_device{}());

struct::timespec getTime;

double calcMilliSec(){ // milliseconds
    clock_gettime(CLOCK_MONOTONIC, &getTime);
    return (getTime.tv_sec + getTime.tv_nsec*1e-9) * 1000.0;
}

// functions

double get_score(ll i){
    double S = (ans[i].c - ans[i].a) * (ans[i].d - ans[i].b);
    double r = 1 - pow(1 - min((double)R[i], S) / max((double)R[i], S), 2);
    // eprint(i,r, R[i]);
    return r;
}

void eval(){
    double score = 0;
    rep(i,0,N){
        score += get_score(i);
    }
    score /= (double) N;
    score *= 1e9;
    // eprint(setprecision(10),score);
}

void generate_sample(){
    use.assign(M, vector<bool>(M, false));
    rep(i,0,N){
        ll h = X[i] / L, w = Y[i] / L;
        use[h][w] = true;
        ans[i] = {L * h, L * w, L*h+L, L*w+L}; 
        ca[ans[i].a]++;
        cb[ans[i].b]++;
        cc[ans[i].c]++;
        cd[ans[i].d]++;
    }


}

bool checkx(ll y,ll lv,ll rv, ll dir){
    if(use[lv][y]) return false;
    if(use[rv-1][y]) return false;
    ll mid = (rv + lv) / 2;
    if(use[mid][y]) return false;
    if(dir == 0){
        if(cb[y] == 0) return true;
    }else if(dir == 2){
        if(cd[y+1] == 0) return true;
    }

    rep(x,lv,rv){
        if(use[x][y]) return false;
    }
    return true;
}

bool checky(ll x,ll lv,ll rv, ll dir){
    if(use[x][lv]) return false;
    if(use[x][rv-1]) return false;
    ll mid = (rv + lv) / 2;
    if(use[x][mid]) return false;
    if(dir == 1){
        if(ca[x] == 0) return true;
    }else if(dir == 3){
        if(cc[x+1] == 0) return true;
    }
    rep(y,lv,rv){
        if(use[x][y]) return false;
    }
    return true;
}

void update_memo(Q prv, Q nxt){
    ca[prv.a]--;
    cb[prv.b]--;
    cc[prv.c]--;
    cd[prv.d]--;

    ca[nxt.a]++;
    cb[nxt.b]++;
    cc[nxt.c]++;
    cd[nxt.d]++;
}

void move_parallel(ll idx){
    Q &e = ans[idx];
    Q prv = ans[idx];
    ll dir = mrand() % PR;
    if(dir == 0){
        ll ny = e.d;
        if(ny != W){
            bool ok = checkx(ny,e.a,e.c, dir);
            if(Y[idx] == e.b) ok = false;
            if(ok){
                rep(i,e.a,e.c){
                    use[i][ny] = true;
                    use[i][e.b] = false;
                }
                e.d++;
                e.b++;

            }
        }
    }else if(dir == 1){
        ll nx = e.c;
        if(nx != W){
            bool ok = checky(nx,e.b,e.d, dir);
            if(X[idx] == e.a) ok = false;
            if(ok){
                rep(i,e.b,e.d){
                    use[nx][i] = true;
                    use[e.a][i] = false;
                }
                e.c++;
                e.a++;
            }
        }

    }else if(dir == 2){
        ll ny = e.b-1;
        if(ny >= 0){
            bool ok = checkx(ny, e.a, e.c, dir);
            if(Y[idx] == e.d-1) ok = false;
            if(ok){
                rep(i,e.a,e.c){
                    use[i][ny] = true;
                    use[i][e.d-1] = false;
                }
                e.b--;
                e.d--;
            }
        }

    }else if(dir == 3){
        ll nx = e.a-1;
        if(nx >= 0){
            bool ok = checky(nx, e.b, e.d, dir);
            if(X[idx] == e.c-1) ok = false;
            if(ok){
                rep(i,e.b,e.d){
                    use[nx][i] = true;
                    use[e.c-1][i] = false;
                }
                e.a--;
                e.c--;
            }
        }

    }

    update_memo(prv, e);
}

void move_enlarge(ll idx){
    Q &e = ans[idx];
    Q prv = ans[idx];
    ll dir = mrand() % 4;
    if(dir == 0){
        ll ny = e.d;
        if(ny != W){
            bool ok = checkx(ny, e.a, e.c,dir);
            if(ok){
                rep(i,e.a,e.c){
                    use[i][ny] = true;
                }
                e.d++;
            }            
        }
    }else if(dir == 1){
        ll nx = e.c;
        if(nx != W){
            bool ok = checky(nx, e.b, e.d,dir);
            if(ok){
                rep(i,e.b,e.d){
                    use[nx][i] = true;
                }
                e.c++;
            }            
        }
    }else if(dir == 2){
        ll ny = e.b-1;
        if(ny >= 0){
            bool ok = checkx(ny, e.a, e.c,dir);
            if(ok){
                rep(i,e.a,e.c){
                    use[i][ny] = true;
                }
                e.b--;
            }
        }
    }else{
        ll nx = e.a-1;
        if(nx >= 0){
            bool ok = checky(nx, e.b, e.d,dir);
            if(ok){
                rep(i,e.b,e.d){
                    use[nx][i] = true;
                }
                e.a--;
            }
        }
    }

    update_memo(prv, e);

}

void move_shrink(ll idx){
    Q &e = ans[idx];
    Q prv = ans[idx];
    ll dir = mrand() % 4;
    if(dir == 0){
        if(Y[idx] != e.d-1){
            rep(i,e.a,e.c){
                use[i][e.d-1] = false;
            }
            e.d--;
        }
    }else if(dir == 1){
        if(X[idx] != e.c-1){
            rep(i,e.b,e.d){
                use[e.c-1][i] = false;
            }
            e.c--;
        }
    }else if(dir == 2){
        if(Y[idx] != e.b){
            rep(i,e.a,e.c){
                use[i][e.b] = false;
            }
            e.b++;
        }
    }else{
        if(X[idx] != e.a){
            rep(i,e.b,e.d){
                use[e.a][i] = false;
            }
            e.a++;
        }
    }

    update_memo(prv, e);

}

void move_change_shape(ll idx){
    Q &e = ans[idx];
    Q prv = ans[idx];

    ll r = mrand() % PR;

    if(r == 0){
        if(e.b == 0 || e.d == W || e.c - e.a <= 2) return;
        bool ok = checkx(e.d, e.a, e.c, 0);
        if(not checkx(e.b-1,e.a,e.c,2)) ok = false;
        if(X[idx] == e.a || X[idx] == e.c-1) ok = false;
        if(ok){
            rep(i,e.b,e.d){
                use[e.a][i] = false;
                use[e.c-1][i] = false;
            }
            e.a++;
            e.c--;
            rep(i,e.a,e.c){
                use[i][e.d] = true;
                use[i][e.b-1] = true;
            }
            e.d++;
            e.b--;
        }
    }else if(r == 1){
        if(e.a == 0 || e.c == W || e.d - e.b <= 2) return;
        bool ok = checky(e.c, e.b, e.d, 1);
        if(not checky(e.a-1,e.b,e.d,3)) ok = false;
        if(Y[idx] == e.b || Y[idx] == e.d-1) ok = false;
        if(ok){
            rep(i,e.a,e.c){
                use[i][e.b] = false;
                use[i][e.d-1] = false;
            }
            e.b++;
            e.d--;
            rep(i,e.b,e.d){
                use[e.c][i] = true;
                use[e.a-1][i] = true;
            }
            e.c++;
            e.a--;
        }
    }
    update_memo(prv, e);
}




void simulate(ll time = 4900){
    double start = calcMilliSec();
    while(true){
        if(iter % 1000 == 0){
            if(calcMilliSec() - start > time) break;
        }
        iter++;
        PR = 80;

        ll idx = mrand() % N;

        // 平行移動
        Q &e = ans[idx];
        ll S = (e.c - e.a) * (e.d - e.b);
        move_parallel(idx);

        if(R[idx] > 100000) move_change_shape(idx);

        S = (e.c - e.a) * (e.d - e.b);
        double p = (double) S / (double) R[idx];
        if(p < 0.99) move_enlarge(idx);
        S = (e.c - e.a) * (e.d - e.b);
        p = (double) S / (double) R[idx];

        if(p > 1.02) move_shrink(idx);

    }
    eprint(iter);


}

void adjust_right(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].c == ans[j].a && max(ans[i].b, ans[j].b) < min(ans[i].d, ans[j].d)){
            if(Y[j] > ans[i].d || Y[j] < ans[i].b){
                alt = j;
                cnt++;
            }
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    Q prv = ans[j];
    if(ans[j].b > ans[i].b){
        rep(y,ans[j].b, ans[i].d){
            rep(x,ans[j].a, ans[j].c){
                use[x][y] = false;
            }
        }
        ans[j].b = ans[i].d;
    }else if(ans[j].d < ans[i].d){
        rep(y,ans[i].b, ans[j].d){
            rep(x,ans[j].a, ans[j].c){
                use[x][y] = false;
            }
        }
        ans[j].d = ans[i].b;                
    }

    update_memo(prv, ans[j]);
    
    while(true){
        Q prv = ans[i];
        Q &e = ans[i];
        if(get_score(i) >= R[i]) break;
        if(e.c == W) break;
        bool ok = checky(e.c, e.b, e.d,1);
        if(ok){
            rep(y,e.b,e.d){
                use[e.c][y] = true;
            }
            e.c++;
            update_memo(prv, e);
        }else{
            break;
        }
    }    
}

void adjust_left(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].a == ans[j].c && max(ans[i].b, ans[j].b) < min(ans[i].d, ans[j].d)){
            if(Y[j] > ans[i].d || Y[j] < ans[i].b){
                alt = j;
                cnt++;
            }
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    Q prv = ans[j];
    if(ans[j].b > ans[i].b){
        rep(y,ans[j].b, ans[i].d){
            rep(x,ans[j].a, ans[j].c){
                use[x][y] = false;
            }
        }
        ans[j].b = ans[i].d;
    }else if(ans[j].d < ans[i].d){
        rep(y,ans[i].b, ans[j].d){
            rep(x,ans[j].a, ans[j].c){
                use[x][y] = false;
            }
        }
        ans[j].d = ans[i].b;                
    }

    update_memo(prv, ans[j]);
    
    while(true){
        Q prv = ans[i];
        Q &e = ans[i];
        if(get_score(i) >= R[i]) break;
        if(e.a == 0) break;
        bool ok = checky(e.a-1, e.b, e.d,3);
        if(ok){
            rep(y,e.b,e.d){
                use[e.a-1][y] = true;
            }
            e.a--;
            update_memo(prv, e);
        }else{
            break;
        }
    }    
}

void adjust_bottom(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].d == ans[j].b && max(ans[i].a, ans[j].a) < min(ans[i].c, ans[j].c)){
            if(X[j] > ans[i].c || X[j] < ans[i].a){
                alt = j;
                cnt++;
            }
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    Q prv = ans[j];
    if(ans[j].a > ans[i].a){
        rep(x,ans[j].a, ans[i].c){
            rep(y,ans[j].b, ans[j].d){
                use[x][y] = false;
            }
        }
        ans[j].a = ans[i].c;
    }else if(ans[j].c < ans[i].c){
        rep(x,ans[i].a, ans[j].c){
            rep(y,ans[j].b, ans[j].d){
                use[x][y] = false;
            }
        }
        ans[j].c = ans[i].a;                
    }

    update_memo(prv, ans[j]);
    
    while(true){
        Q prv = ans[i];
        Q &e = ans[i];
        if(get_score(i) >= R[i]) break;
        if(e.d == W) break;
        bool ok = checkx(e.d, e.a, e.c,0);
        if(ok){
            rep(x,e.a,e.c){
                use[x][e.d] = true;
            }
            e.d++;
            update_memo(prv, e);
        }else{
            break;
        }
    }    
}

void adjust_top(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].b == ans[j].d && max(ans[i].a, ans[j].a) < min(ans[i].c, ans[j].c)){
            if(X[j] > ans[i].c || X[j] < ans[i].a){
                alt = j;
                cnt++;
            }
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    Q prv = ans[j];
    if(ans[j].a > ans[i].a){
        rep(x,ans[j].a, ans[i].c){
            rep(y,ans[j].b, ans[j].d){
                use[x][y] = false;
            }
        }
        ans[j].a = ans[i].c;
    }else if(ans[j].c < ans[i].c){
        rep(x,ans[i].a, ans[j].c){
            rep(y,ans[j].b, ans[j].d){
                use[x][y] = false;
            }
        }
        ans[j].c = ans[i].a;                
    }

    update_memo(prv, ans[j]);
    
    while(true){
        Q prv = ans[i];
        Q &e = ans[i];
        if(get_score(i) >= R[i]) break;
        if(e.b == 0) break;
        bool ok = checkx(e.b-1, e.a, e.c,2);
        if(ok){
            rep(x,e.a,e.c){
                use[x][e.b-1] = true;
            }
            e.b--;
            update_memo(prv, e);
        }else{
            break;
        }
    }    
}

void push_right(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].c == ans[j].a && max(ans[i].b, ans[j].b) < min(ans[i].d, ans[j].d)){
            cnt++;
            alt = j;
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    if(X[j] == ans[j].a) return;
    Q prv_i = ans[i], prv_j = ans[j];
    double pre_score = get_score(i) + get_score(j);
    ans[i].c++; ans[j].a++;
    double after_score = get_score(i) + get_score(j);
    ans[i].c--; ans[j].a--;
    if(pre_score < after_score){
        rep(y,ans[j].b,ans[j].d){
            use[ans[j].a][y] = false;
        }
        rep(y,ans[i].b, ans[i].d){
            use[ans[j].a][y] = true;
        }
        ans[i].c++; ans[j].a++;
        update_memo(prv_i, ans[i]);
        update_memo(prv_j, ans[j]);
    } 
}

void push_left(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].a == ans[j].c && max(ans[i].b, ans[j].b) < min(ans[i].d, ans[j].d)){
            cnt++;
            alt = j;
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    if(X[j] == ans[j].c-1) return;
    Q prv_i = ans[i], prv_j = ans[j];
    double pre_score = get_score(i) + get_score(j);
    ans[i].a--; ans[j].c--;
    double after_score = get_score(i) + get_score(j);
    ans[i].a++; ans[j].c++;
    if(pre_score < after_score){
        // eprint(i,j);
        rep(y,ans[j].b,ans[j].d){
            use[ans[j].c-1][y] = false;
        }
        rep(y,ans[i].b, ans[i].d){
            use[ans[j].c-1][y] = true;
        }
        ans[i].a--; ans[j].c--;
        update_memo(prv_i, ans[i]);
        update_memo(prv_j, ans[j]);
    } 
}

void push_bottom(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].d == ans[j].b && max(ans[i].a, ans[j].a) < min(ans[i].c, ans[j].c)){
            cnt++;
            alt = j;
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    if(Y[j] == ans[j].b) return;
    Q prv_i = ans[i], prv_j = ans[j];
    double pre_score = get_score(i) + get_score(j);
    ans[i].d++; ans[j].b++;
    double after_score = get_score(i) + get_score(j);
    ans[i].d--; ans[j].b--;
    if(pre_score < after_score){
        rep(x,ans[j].a,ans[j].c){
            use[x][ans[j].b] = false;
        }
        rep(x,ans[i].a, ans[i].c){
            use[x][ans[j].b] = true;
        }
        ans[i].d++; ans[j].b++;
        update_memo(prv_i, ans[i]);
        update_memo(prv_j, ans[j]);
    } 
}

void push_top(ll i){
    ll cnt = 0, alt = -1;
    rep(j,0,N){
        if(i == j) continue;
        if(ans[i].b == ans[j].d && max(ans[i].a, ans[j].a) < min(ans[i].c, ans[j].c)){
            cnt++;
            alt = j;
        }
    }
    if(cnt != 1) return;
    ll j = alt;
    if(Y[j] == ans[j].d-1) return;
    Q prv_i = ans[i], prv_j = ans[j];
    double pre_score = get_score(i) + get_score(j);
    ans[i].b--; ans[j].d--;
    double after_score = get_score(i) + get_score(j);
    ans[i].b++; ans[j].d++;
    if(pre_score < after_score){
        rep(x,ans[j].a,ans[j].c){
            use[x][ans[j].d-1] = false;
        }
        rep(x,ans[i].a, ans[i].c){
            use[x][ans[j].d-1] = true;
        }
        ans[i].b--; ans[j].d--;
        update_memo(prv_i, ans[i]);
        update_memo(prv_j, ans[j]);
    } 
}

void simulate3(){
    // rep(t,0,100){
    rep(i,0,N){
        double score = get_score(i);
        if(score <= 0.99){
            adjust_right(i);
            adjust_bottom(i);
            adjust_left(i);
            adjust_top(i);
        }
    }
    rep(t,0,500){
        bool ok = false;
        rep(i,0,N){
            double score = get_score(i);
            if(score <= 0.99){
                push_right(i);
                push_left(i);
                push_bottom(i);
                push_top(i);
            }
            if(abs(score - get_score(i)) > 1e-9) ok = true;
        }
        if(not ok) break;
    }


    // }
}


void get_input(){
    cin >> N;
    X.resize(N);
    Y.resize(N);
    R.resize(N);
    ans.resize(N);
    rep(i,0,N) cin >> X[i] >> Y[i] >> R[i];


}

void output(){
    rep(i,0,N){
        print(ans[i].a, ans[i].b, ans[i].c, ans[i].d);
    }


}



void solve(){
    get_input();
    generate_sample();
    simulate(timeLimit);
    rep(t,0,10){
        simulate3();
        simulate(timeLimit);
    }
    output();
    eval();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}