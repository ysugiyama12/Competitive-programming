/*** author: yuji9511 ***/
#include <bits/stdc++.h>
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// variables
ll N;
vector<vll> A;
ll Q = 1000;
double timeLimit = 5900;
vll X(Q), Y(Q), H(Q);
typedef struct {ll x,y,h;} P;
ll best_score = 0;
ll current_score = 0;
vector<vll> B;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
struct::timespec getTime;

// utils
mt19937 mrand(random_device{}());
double calcMilliSec(){ // milliseconds
    clock_gettime(CLOCK_MONOTONIC, &getTime);
    return (getTime.tv_sec + getTime.tv_nsec*1e-9) * 1000.0;
}

double rnd_d(){
    return (double) (mrand() % 100000) / 100000.0;
}

// functions

void change_diff(P nxt, char c){
    ll lx = max(0, nxt.x - nxt.h), rx = min(N, nxt.x + nxt.h + 1);
    rep(x,lx,rx){
        ll ly = max(0, nxt.y - nxt.h + abs(nxt.x - x));
        ll ry = min(N, nxt.h - abs(nxt.x - x) + nxt.y + 1);
        rep(y,ly,ry){
            ll v = nxt.h - abs(nxt.x-x) - abs(nxt.y-y);
            if(v >= 1){
                ll a = A[x][y];
                current_score += abs(a - B[x][y]);
                if(c == '+'){
                    B[x][y] += v;
                }else{
                    B[x][y] -= v;
                }
                current_score -= abs(a - B[x][y]);
            }
        }
    }
}

void eval(){
    current_score = 200000000;
    rep(i,0,N){
        rep(j,0,N){
            current_score -= abs(A[i][j] - B[i][j]);
        }
    }
}

void generate_sample(){
    rep(i,0,Q){
        X[i] = mrand() % N;
        Y[i] = mrand() % N;
        H[i] = mrand() % N + 1;
    }
    rep(i,0,Q){
        change_diff({X[i], Y[i], H[i]}, '+');
    }
}

void simulate(){
    double st = calcMilliSec();
    double et = st + timeLimit;
    ll n_loop = 0, ok = 0;

    double C = timeLimit * 100;
    double forceLine;

    while(true){
        double t = calcMilliSec();
        if(t >= et) break;
        n_loop++;
        ll idx = mrand() % Q;
        // ll x = mrand() % N, y = mrand() % N, h = mrand() % N+1;
        ll x = X[idx], y = Y[idx], h = H[idx];
        ll n = (ll)(t - st) / 1200;
        ll d = 3;

        x += mrand() % 3 - 1;
        y += mrand() % 3 - 1;
        h += mrand() % d - d/2;
        if(X[idx] == x && Y[idx] == y && H[idx] == h) continue;
        x = clamp(x,0,N-1);
        y = clamp(y,0,N-1);
        h = clamp(h,1,N);
        P nxt = {x,y,h};
        P tmp = {X[idx], Y[idx], H[idx]};
        change_diff(tmp, '-');
        change_diff(nxt, '+');
        // ll cur = calcMilliSec();
        forceLine = (et - t) / C;
        if(chmax(best_score, current_score)){
            ok++;
            X[idx] = nxt.x;
            Y[idx] = nxt.y;
            H[idx] = nxt.h;
        }else{
            change_diff(tmp, '+');
            change_diff(nxt, '-');
        }
    }

}

void get_input(){
    N = 100;
    A.assign(N, vll(N));
    rep(i,0,N){
        rep(j,0,N){
            cin >> A[i][j];
        }
    }


void output(){
    print(Q);
    rep(i,0,Q){
        print(Y[i], X[i], H[i]);
    }
}



void solve(){
    get_input();
    B.assign(N, vll(N, 0));
    generate_sample();
    eval();
    simulate();
    // print(best_score);
    output();
    cerr << best_score << endl;
    // eval();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}