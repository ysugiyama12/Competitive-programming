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
    ll N, A[200010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N, greater<ll>());
    ll ans = 0;
    map<ll,ll> mp;
    rep(i,0,N){
        mp[A[i]]++;
    }
    rep(i,0,N){
        if(mp[A[i]] == 0) continue;
        ll nn = 1;
        while(nn <= A[i]){
            nn *= 2;
        }
        ll val = nn - A[i];
        mp[A[i]]--;
        if(mp[val] != 0){
            mp[val]--;
            ans++;
        }
    }
    print(ans);
}
