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
    ll N,L;
    ll a[100010];
    cin >> N >> L;
    rep(i,0,N){
        cin >> a[i];
    }
    ll sum[100010] = {};
    rep(i,0,N){
        sum[i+1] = sum[i] + a[i];
    }
    ll val = sum[N];
    // print(val);
    ll rv = N-1;
    ll lv = 0;
    vector<ll> ans;
    ll cnt = 0;
    bool is_ok = false;
    ll pos = -1;
    rep(i,0,N-1){
        if(a[i] + a[i+1] >= L){
            is_ok = true;
            pos = i;
        }
    }
    // print(pos);
    if(!is_ok){
        print("Impossible");
        return 0;
    }
    print("Possible");
    rep(i,0,pos){
        print(i+1);
    }
    for(int i = N-2; i >= pos+1; i--){
        print(i+1);
    }
    print(pos+1);

}
