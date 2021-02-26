#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
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
    int N,M,R;
    int r[10];
    ll A[30000], B[30000], C[30000];
    cin >> N >> M >> R;
    rep(i,0,R){
        cin >> r[i];
        r[i]--;
    }
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }
    ll d[210][210] = {};
    rep(i,0,N){
        rep(j,0,N){
            d[i][j] = INF;
        }
    }
    rep(i,0,M){
        d[A[i]][B[i]] = C[i];
        d[B[i]][A[i]] = C[i];
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<int> v(R);
    iota(v.begin(), v.end(), 0);
    ll ans = 1e9;
    do{
        ll ans_tmp = 0;

        rep(i,0,R-1){
            int r0 = r[v[i]];
            int r1 = r[v[i+1]];
            ans_tmp += d[r0][r1];
        }
        ans = min(ans, ans_tmp);

    }while(next_permutation(v.begin(), v.end()));
    print(ans);
}
