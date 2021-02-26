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
bool comp2(lpair p1, lpair p2){
    if(p1.first == p2.first){
        return (p1.second < p2.second);
    }
    return (p1.first < p2.first);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll P[100010], Y[100010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> P[i] >> Y[i];
    }
    vector<lpair> lp;
    map<lpair, ll> mp;
    rep(i,0,M){
        lpair lp1 = make_pair(P[i], Y[i]);
        lp.push_back(lp1);
        mp[lp1] = i;
    }
    sort(lp.begin(), lp.end(), comp2);
    vector<lpair> ans(100010);
    ll rank = 1;
    rep(i,0,M){
        ll pre_num = lp[i].first;
        if(i != 0){
            if(pre_num == lp[i-1].first){
                rank++;
            }else{
                rank = 1;
            }
        }
        ll n = mp[lp[i]];
        ans[n].first = pre_num;
        ans[n].second = rank;

    }
    rep(i,0,M){
        cout << setfill('0') << right << setw(6) << ans[i].first;
        cout << setfill('0') << right << setw(6) << ans[i].second << endl;
    }
}
