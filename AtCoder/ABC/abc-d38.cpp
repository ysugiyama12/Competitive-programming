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

bool comp(lpair v1, lpair v2){
    if(v1.first == v2.first){
        return v1.second < v2.second;
    }
    return v1.first < v2.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll h[100010], w[100010];
    cin >> N;
    vector<lpair> lp;
    rep(i,0,N){
        cin >> h[i] >> w[i];
        lp.push_back(make_pair(h[i],w[i]));
    }
    sort(lp.begin(), lp.end(), comp);
    ll ans = 1;
    lpair pp = make_pair(lp[0].first, lp[0].second);
    rep(i,1,N){
        if(lp[i].first != lp[i-1].first){
            if(lp[i].second > pp.second){
                ans++;
                pp.first = lp[i].first;
                pp.second = lp[i].second;
            }
        }
    }
    print(ans);

}
