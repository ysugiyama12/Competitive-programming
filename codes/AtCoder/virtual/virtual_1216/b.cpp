#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
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
    ll N;
    ll A,B,C,D;
    cin >> N;
    cin >> A >> B >> C >> D;
    bool is_ok = false;
    ll val = B - A;
    rep(i,0,N){
        ll plus_val = N-1-i;
        ll plus_min = (N-1-i) * C;
        ll plus_max = (N-1-i) * D;

        ll minus_min = -i * D;
        ll minus_max = -i * C;
        ll v1 = plus_max + minus_max;
        ll v2 = plus_min + minus_min;
        if(val >= v2 && val <= v1){
            is_ok = true;
        }
    }
    if(is_ok){
        print("YES");
    }else{
        print("NO");
    }
    // rep(i,1,N-1){
    //     if(B - val >= D){
    //         val += D;
    //     }else if(val - B >= D){
    //         val -= D;
    //     }else if(B - val >= 0){
    //         val += C;
    //     }else{
    //         val -= C;
    //     }
    //     print(val);
    // }
    // if(abs(val - B) >= C && abs(val-B) <= D){
    //     print("YES");
    // }else{
    //     print("NO");
    // }

}
