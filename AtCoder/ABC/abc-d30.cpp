#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,a;
    string k;
    ll b[100010];
    cin >> N >> a;
    cin >> k;
    ll nk = atol(k.c_str());
    ll jump[100010] = {};
    rep(i,0,N){
        cin >> b[i];
        jump[i+1] = b[i];
    }
    ll cnt[100010] = {};
    rep(i,1,N+1){
        cnt[i] = -1;

    }
    ll pos = a;
    ll turn = 0;
    ll C = -1;
    ll T = -1;
    ll sp = -1;
    while(1){
        if(cnt[pos] != -1){
            C = turn - cnt[pos];
            T = cnt[pos];
            sp = pos;
            break;
        }
        cnt[pos] = turn;
        turn++;
        pos = jump[pos];
    }
    ll amari[100010] = {};
    rep(i,1,N+1){
        amari[i] = -1;
    }
    amari[sp] = 0;
    pos = sp;
    ll idx = 1;
    rep(i,0,C-1){
        pos = jump[pos];
        amari[pos] = idx;
        idx++;
    }
    if(nk <= 100010){
        ll ss = a;
        rep(i,0,nk){
            // print(ss);
            ss = jump[ss];
        }
        print(ss);
    }else{
        ll kmod_C = 0;
        rep(i,0,k.size()){
            kmod_C = (kmod_C*10 + (k[i] - '0')) % C;
        }
        kmod_C = (kmod_C - (T % C) + C) % C;
        ll num = nk - T;
        rep(i,1,N+1){
            if(amari[i] == kmod_C){
                print(i);
                return 0;
            }
        }
    }
    // printa(cnt,N+1);
    // print(C);
}
