#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
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
    ll N,x;
    cin >> N >> x;
    ll ans[250010];
    if(x == 1 || x == 2*N-1){
        print("No");
    }else{
        print("Yes");
        ans[N-1] = x;
        vector<ll> v;
        rep(i,1,2*N){
            if(i != x){
                v.push_back(i);
            }
        }
        // printa(v,v.size());
        vector<ll> v2;
        rep(i,0,N-1){
            v2.push_back(v[i]);
            v2.push_back(v[2*(N-1)-i-1]);
        }
        // printa(v2,v2.size());
        ll diff = 1;
        // printa(v,v.size());
        rep(i,0,N-1){
            ans[N-1-diff] = v2[2*i];
            ans[N-1+diff] = v2[2*i+1];
            diff++;
            // ans[N-1-diff] = cnt;
            // cnt++;
            // ans[N-1+diff] = cnt;
            // cnt++;
            // diff++;
        }
        printa(ans,2*N-1);
    }

}
