#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    ll a[100001];
    ll x;
    cin >> N >> x;
    rep(i,0,N) cin >> a[i];
    ll ans = 0;
    if(a[0] > x){
        ans += a[0] - x;
        a[0] = x;
    }
    rep(i,1,N){
        if(a[i] + a[i-1] > x){
            ans += a[i] + a[i-1] - x;
            a[i] -= (a[i] + a[i-1] - x);
        }   
    }
    print(ans);


}
