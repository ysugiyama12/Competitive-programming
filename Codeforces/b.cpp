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
    ll N,K;
    cin >> N >> K;
    ll a[100010];
    rep(i,0,N){
        cin >> a[i];
    }
    sort(a, a+N);
    ll val = a[0];
    vector<ll> v;
    v.push_back(a[0]);
    rep(i,1,N){
        if(a[i] != a[i-1]){
            v.push_back(a[i]);
        }
    }
    ll n = v.size();
    ll cnt = 0;
    rep(i,0,K){
        if(i >= n){
            print(0);
        }else{
            print(v[i] - cnt);
            cnt += v[i]-cnt;
        }
    }

}
