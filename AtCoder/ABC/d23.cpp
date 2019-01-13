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
    cin >> N;
    ll H[100001], S[100001], T[100001];
    rep(i,0,N){
        cin >> H[i] >> S[i];
    }
    ll left = -1;
    ll right = 1e18+1;
    while(right - left > 1){
        ll X = (right + left)/2;
        // print(X);

        bool is_ok = true;
        bool is_minus = true;
        rep(i,0,N){
            ll t = (X - H[i])/S[i];
            T[i] = t;
            if(X < H[i]) is_minus = false;
        }
        sort(T, T+N);
        rep(i,0,N){
            if(T[i] < i) is_ok = false;
        }

        if(!is_minus){
            left = X;
        }else if(!is_ok){
            left = X;
        }else{
            right = X;
        }
    }
    print(right);
}
