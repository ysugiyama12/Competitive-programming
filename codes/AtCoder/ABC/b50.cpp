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
    ll R, B, x, y;
    cin >> R >> B >> x >> y;
    ll ans = 0;
    ll left = -1; 
    ll right = 1e18+1;
    while(right - left > 1){
        ll m = (right+left)/2;
        ll red = (R - m)/(x-1);
        ll blue = (B - m)/(y-1);
        if(R - m >= 0 && B - m  >= 0 && red + blue >= m){
            left = m;
        }else{
            right = m;
        }

    }
}