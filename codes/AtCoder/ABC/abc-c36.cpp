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
    ll N;
    ll a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(a[i],i));
    }
    sort(lp.begin(), lp.end());
    ll pos[100010] = {};
    ll num = 0;
    rep(i,1,N){
        if(lp[i-1].first != lp[i].first){
            num++;
        }
        pos[lp[i].second] = num;
    }
    rep(i,0,N){
        print(pos[i]);
    }


}
