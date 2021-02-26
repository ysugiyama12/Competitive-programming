#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    ll A[100010];
    ll X[100010];
    cin >> N >> Q;
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,Q){
        cin >> X[i];
    }
    sort(A, A+N);
    vector<lpair> lp;
    rep(i,0,Q){
        lp.push_back(make_pair(X[i], i));
    }
    sort(lp.begin(), lp.end());
    ll score = 0;
    rep(i,0,(N+1)/2){
        score += A[N-1-i];
    }
    ll ans[100010] = {};
    ll diff[100010] = {};
    rep(i,0,N){
        diff[i] = abs(lp[0].first - A[i]);
    }
    rep(i,1,Q){
        ll x = lp[i].first;
        ll idx = lp[i].second;
        ans[idx] = 0;
        
    }
}
