
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
    ll N,K;
    cin >> N >> K;
    ll X[100010];
    map<ll,ll> mp;
    rep(i,0,N){
        cin >> X[i];
        mp[X[i]] = i+1;
    }
    priority_queue< ll, vector<ll> > pq1;
    // priority_queue< ll, vector<ll>, greater<ll> > pq2;
    rep(i,0,K){
        pq1.push(X[i]);
    }
    rep(i,0,N-K+1){
        ll v = pq1.top();
        print(mp[v]);
        if(v > X[i+K]){
            pq1.pop();
            pq1.push(X[i+K]);
        }
    }

}
