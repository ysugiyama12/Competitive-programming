#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

ll gcd( ll m, ll n )
{
    if (n == 0){
        return m;
    }else{
        return gcd(n, m % n);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    string S,T;
    cin >> N >> M;
    cin >> S >> T;
    ll gval = gcd(N,M);
    ll lval = N / gval;
    lval *= M;
    ll v1 = lval/N;
    ll v2 = lval/M;
    bool is_ok = true;
    if(S[0] != T[0]){
        is_ok = false;
    }
    vector<char> s_char;
    vector<char> t_char;
    rep(i,1,N){
        if(i % v2 == 0){
            s_char.push_back(S[i]);
        }
    }
    rep(i,1,M){
        if(i % v1 == 0){
            t_char.push_back(T[i]);
        }
    }
    rep(i,0,s_char.size()){
        if(s_char[i] != t_char[i]){
            is_ok = false;
        }
    }
    if(is_ok){
        print(lval);
    }else{
        print(-1);
    }

}
