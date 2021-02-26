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
    int N,H;
    cin >> N >> H;
    ll a[100010], b[100010];
    rep(i,0,N){
        cin >> a[i] >> b[i];
    }
    sort(b, b+N, greater<int>());
    sort(a, a+N, greater<int>());
    int h = H;
    int pb = 0;
    ll ans = 0;
    while(h > 0){
        if(a[0] <= b[pb] && pb < N){
            ans++;
            h -= b[pb];
            pb++;
        }else{
            ll val = h / a[0];
            if(h % a[0] != 0) val++;
            ans += val;
            break;
        }

    }
    print(ans);



}