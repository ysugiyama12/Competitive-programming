#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
void comb(vector< vector<ll> > &v){
    rep(i,0,v.size()){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    rep(i,1,v.size()){
        rep(j,1,i){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    ll v[55];
    cin >> N >> A >> B;
    rep(i,0,N){
        cin >> v[i];
    }
    vector< vector<ll> > nck(N+1, vector< ll >(N+1,0));
    comb(nck);
    sort(v,v+N, greater<ll>());
    double ave_max = 0.0;
    rep(i,0,A){
        ave_max += v[i];
    }
    ave_max /= A;
    ll cnt_part = 0, cnt_all = 0;
    ll ans = 0;
    rep(i,0,N){
        if(v[A-1] == v[i]){
            cnt_all++;
            if(i <= A-1){
                cnt_part++;
            }
        }
    }
    ans += nck[cnt_all][cnt_part];
    rep(i,A+1,B+1){
        if(v[i-1] == v[0]){
            ans += nck[cnt_all][i];
        }
    }
    printf("%lf\n", ave_max);
    printf("%lld\n", ans);

}
