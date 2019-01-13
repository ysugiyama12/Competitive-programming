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
bool comp(lpair l1, lpair l2){
    if(l1.first == l2.first){
        return l1.second < l2.second;
    }
    return l1.first < l2.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll x[2010], y[2010];
    ll a[2010], b[2010];
    cin >> N;
    rep(i,0,N){
        cin >> x[i] >> y[i];
    }
    rep(i,0,N){
        cin >> a[i] >> b[i];
    }
    vector<lpair> lp1, lp2;
    rep(i,0,N){
        lp1.push_back(make_pair(x[i], y[i]));
        lp2.push_back(make_pair(a[i], b[i]));
    }
    sort(lp1.begin(), lp1.end(), comp);
    sort(lp2.begin(), lp2.end(), comp);
    cout << lp1[0].first + lp2[N-1].first << " " << lp1[0].second + lp2[N-1].second << endl;



}
