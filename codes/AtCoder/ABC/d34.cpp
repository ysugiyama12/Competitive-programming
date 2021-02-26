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
    int N,K;
    cin >> N >> K;
    double w[1001], p[1001], d[1001];
    rep(i,0,N){
        cin >> w[i] >> p[i];
    }
    double left = 0;
    double right = 100;
    int cnt = 0;
    while(cnt < 100){
        double m = (left+right)/2;
        rep(i,0,N){
            d[i] = w[i] * (p[i] - m);
        }
        sort(d,d+N);
        double sum = 0;
        rep(i,0,K){
            sum += d[N-i-1];
        }
        if(sum >= 0){
            left = m;
        }else{
            right = m;
        }
        cnt++;
    }
    // print(left);
    cout << setprecision(10) << (left + right) / 2.0 << endl;

}
