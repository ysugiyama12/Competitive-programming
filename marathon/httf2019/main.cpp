/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
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
double timeLimit = 5900;
ll N,M,L;
vector<string> S;
vector<string> T;

// utils
mt19937 mrand(random_device{}());

struct::timespec getTime;

double calcMilliSec(){ // milliseconds
    clock_gettime(CLOCK_MONOTONIC, &getTime);
    return (getTime.tv_sec + getTime.tv_nsec*1e-9) * 1000.0;
}

// functions
void eval(){

}

void generate_sample(){

}

void simulate(){

}

void get_input(){
    cin >> N >> M >> L;
    S.resize(N);
    rep(i,0,N) cin >> S[i];
    T.resize(M);
    rep(i,0,M){
        if(i == 0 || i == M-1){
            T[i] = string(M, '#');
        }else{
            T[i] = "#" + string(M-2, '.') + "#";
        }
    }



}

void output(){
    rep(i,0,M){
        cout << T[i] << "\r\n";
    }
}



void solve(){
    get_input();
    generate_sample();
    eval();
    simulate();
    output();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}