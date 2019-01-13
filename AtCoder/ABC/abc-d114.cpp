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
vector<ll> v;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

inline bool isPrime(ll x){ //素数かどうか判定
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,1,N+1){
        v.push_back(i);
    }
    ll ans_all = 0;
    ll ans = 0;
    ll fac[3] = {4,4,2};
    ll fac_n[110] = {};
    rep(i,2,N+1){
        ll cnt_tmp = 0;
        rep(j,1,N+1){
            ll tt = j;
            while(tt % i == 0){
                cnt_tmp++;
                tt /= i;
            }
        }
        if(isPrime(i)) fac_n[i] = cnt_tmp;
    }

    rep(i,1,N+1){
        rep(j,1,N+1){
            rep(k,1,N+1){
                if(i == j || j == k || i == k) continue;
                if(fac_n[i] >= 4 && fac_n[j] >= 4 && fac_n[k] >= 2){
                    ans++;
                }
            }
        }
    }
    ans_all += ans/2;
    ans = 0;
    rep(i,1,N+1){
        rep(j,1,N+1){
            if(i == j) continue;
            if(fac_n[i] >= 14 && fac_n[j] >= 4){
                ans++;
            }
        }
    }
    ans_all += ans;
    ans = 0;
    rep(i,1,N+1){
        rep(j,1,N+1){
            if(i == j) continue;
            if(fac_n[i] >= 24 && fac_n[j] >= 2){
                ans++;
            }
        }
    }
    ans_all += ans;
    ans = 0;
    if(fac_n[2] >= 74) ans_all++;
    print(ans_all);

}
