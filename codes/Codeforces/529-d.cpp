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
vector<lpair> lp[200010];
ll N;
ll a1[200010], a2[200010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N){
        cin >> a1[i] >> a2[i];
        a1[i]--; a2[i]--;
    }
    if(N == 3){
        print("1 2 3");
        return 0;
    }
    rep(i,0,N){
        lp[a1[i]].push_back(make_pair(i, a2[i]));
        lp[a2[i]].push_back(make_pair(i, a1[i]));
    }
    ll after[200010];
    rep(i,0,N){
        ll alt1 = lp[i][0].first;
        ll alt2 = lp[i][1].first;
        if(alt1 == lp[i][0].second || alt1 == lp[i][1].second){
            after[alt2] = alt1;
            after[alt1] = i;
        }else{
            after[alt1] = alt2;
            after[alt2] = i;
        }
    }
    ll cnt = 0;
    ll pos = 0;
    cout << 1 << " ";
    while(cnt < N-1){
        cout << after[pos]+1 << " ";
        pos = after[pos];
        cnt++;
    }
    cout << endl;
}
