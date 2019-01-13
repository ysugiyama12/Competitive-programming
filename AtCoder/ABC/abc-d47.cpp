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
    priority_queue<ll> pq;
    ll N,T;
    ll A[100010];
    cin >> N >> T;
    rep(i,0,N){
        cin >> A[i];
    }
    ll diff_max[100010] = {};
    for(int i = N-2; i >= 0; i--){
        pq.push(A[i+1]);
        ll val = pq.top();
        diff_max[i] = pq.top() - A[i];
    }
    // rep(i,0,N-1){
    //     pq.pop();
    //     ll val = pq.top();
    //     diff_max[i] = max(0, val - A[i]);
    // }
    sort(diff_max, diff_max + N-1, greater<ll>());
    ll ans = 1;
    ll dd = diff_max[0];
    rep(i,1,N){
        if(dd == diff_max[i]){
            ans++;
        }
    }
    print(ans);



}
