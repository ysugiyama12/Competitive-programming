#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
ll N,M,K;
ll a[100010], b[100010];
vector<ll> tree[100010];
ll arr[10] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    if(N > 8 || K > 3) return 0;
    rep(i,0,M){
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    ll ans = 0;
    rep(i,0,pow(K,N)){
        rep(j,0,N){
            arr[j] = 0;
        }
        ll v = i;
        ll idx = 0;
        while(v > 0){
            arr[idx] = v%2;
            v /= 2;
            idx++;
        }
        bool ok = true;
        rep(j,0,M){
            if(arr[a[j]] == arr[b[j]]){
                ok = false;

            }
        }
        if(ok){
            ans++;
        }
    }
    print(ans);

}
