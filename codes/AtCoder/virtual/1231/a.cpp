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
    ll N,C;
    ll L[100010];
    cin >> N >> C;
    rep(i,0,N){
        cin >> L[i];
    }
    sort(L, L+N, greater<ll>());
    // printa(L,N);
    ll lv = (N+1)/2 - 1, rv = N;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        bool ok = true;
        ll idx = 1;
        rep(i,mid,N){
            if(L[i] + L[mid-idx] > C-1){
                ok = false;
            }
            idx++;
        }
        // print(mid);
        // print(ok);
        // print("--");
        if(ok){
            rv = mid; 
        }else{
            lv = mid;
        }

    }
    print(rv);


}
