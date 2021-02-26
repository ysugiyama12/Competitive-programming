#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
typedef struct{
    ll from;
    ll to;
    ll cost;
} edge;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L;
    cin >> L;
    ll n = 0;
    rep(i,0,20){
        if(L < (1LL<<i)) break;
        n = i;
    }
    vector<edge> lp;
    rep(i,1,n+1){
        edge e1 = {i, i+1, 0};
        edge e2 = {i, i+1, (1<<(i-1))};
        lp.push_back(e1);
        lp.push_back(e2);
    }
    ll l = L;
    l -= (1<<n);
    ll t = n-1;
    ll num = L;
    while(l > 0){
        if(l >= (1<<t)){
            edge e = {t+1, n+1, L - l};
            l -= (1<<t);
            lp.push_back(e);
        }
        t--;
    }
    cout << n+1 << " " << lp.size() << endl;
    rep(i,0,lp.size()){
        cout << lp[i].from << " " << lp[i].to  << " " << lp[i].cost << endl;
    }
}
