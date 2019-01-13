#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
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
    int B[200001];
    rep(i,0,N){
        B[i] = A[i] - i - 1;
    }
    ll ans = 0;
    sort(B, B+N);
    if(N % 2 != 0){
        int pos = (N - 1)/2;
        int tmp = B[pos];
        rep(i,0,N){
            B[i] += (tmp * -1);
        }
    }else{
        int pos = N/2;
        int tmp = B[pos];
        rep(i,0,N){
            B[i] += (tmp * -1);
        }

    }
    rep(i,0,N){
        ans += abs(B[i]);
    }
    print(ans);
    
}
