/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
vector<ll> tree[1000010];
ll cnt[1000010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[1010][1010];
    rep(i,0,N){
        rep(j,0,N){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    rep(i,0,N){
        rep(j,0,N-2){
            ll from = i * N + A[i][j];
            ll to = i * N + A[i][j+1];
            tree[from].push_back(to);
            cnt[to]++;
        }
    }
    priority_queue<lpøair, vector<lpair>, greater<lpair> > pq;
    rep(i,0,N)



    
}