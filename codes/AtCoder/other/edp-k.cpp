#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    ll a[110];
    cin >> N >> K;
    rep(i,0,N){
        cin >> a[i];
    }
    ll grundy[100010] = {};
    rep(i,0,K+1){
        map<ll,ll> mp;
        rep(j,0,N){
            if(i - a[j] >= 0){
                mp[grundy[i-a[j]]]++;
            }
        }
        ll min_val = 0;
        rep(j,0,N+1){
            if(mp[j] == 0){
                min_val = j;
                break;
            }
        }
        grundy[i] = min_val;
    }
    // printa(grundy, K);
    if(grundy[K] == 0){
        print("Second");
    }else{
        print("First");
    }
}
