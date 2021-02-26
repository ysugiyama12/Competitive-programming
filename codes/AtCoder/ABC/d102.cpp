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
    int A[200001];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    int sum[200010];
    sum[0] = 0;
    rep(i,1,N+1){
        sum[i] = sum[i-1] + A[i-1];
    }
    int max_val[200010] = {}, min_val[200010] = {}; 
    int left = 0;
    rep(i,1,N-2){
        ll min_dif = 1e18;
        while(1){
            ll val_1 = sum[left + 1];
            ll val_2 = sum[i + 1] - sum[left + 1];
            min_dif = min(min_dif, abs(val_1 - val_2));


        }

    }



}
