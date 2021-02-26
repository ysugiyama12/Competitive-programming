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

    int N,Q;
    cin >> N >> Q;
    int X[100001];
    rep(i,0,N){
        cin >> X[i];
    }
    int C[100001], D[100001];
    rep(i,0,Q){
        cin >> C[i] >> D[i];
    }
    ll sum[100001];
    sum[0] = 0;
    rep(i,1,N+1){
        sum[i] = sum[i-1] + X[i-1];
    }

    rep(i,0,Q){
        ll c = C[i];
        ll d = D[i];
        ll result = 0;
        int pos_back = lower_bound(X, X+N, c-d) - X;
        int pos_top = lower_bound(X, X+N, c+d) - X;
        int this_pos = lower_bound(X, X+N, c) - X;
        // print("");
        // print(pos_back);
        // print(pos_top);
        result += pos_back * d;
        result += (N - pos_top) * d;

        result += sum[pos_back] - sum[this_pos] + (this_pos - pos_back) * c;
        result += sum[pos_top] - sum[this_pos] - (pos_top - this_pos) * c;

        // rep(j,pos_back, pos_top){
        //     result += abs(X[j] - c);
        // }

        print(result);

    }
}
