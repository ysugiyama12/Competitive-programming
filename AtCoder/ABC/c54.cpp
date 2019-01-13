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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll a[30], b[30];
    cin >> N >> M;
    ll tree[10][10] = {};
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]][b[i]] = 1;
        tree[b[i]][a[i]] = 1;
    }
    vector<ll> v(N);
    iota(v.begin(), v.end(), 0);
    ll ans = 0;
    do {
        if(v[0] == 0){
            bool is_ok = true;
            rep(i,0,N-1){
                if(tree[v[i]][v[i+1]] == 0){
                    is_ok = false;
                }
            }
            if(is_ok){
                ans++;
            }

        }
    }while(next_permutation(v.begin(), v.end()));
    print(ans);





}
