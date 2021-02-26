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
ll N,M;
ll a[100010];
bool comp(lpair l1, lpair l2){
    if(l1.first == l2.first){
        return (l1.second < l2.second);
    }
    return (l1.first > l2.first);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i];
        a[i]--;
    }
    ll cnt[100010] = {};
    rep(i,0,M){
        cnt[a[i]] = i+1;
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(cnt[i], i));
    }
    sort(lp.begin(), lp.end(), comp);
    rep(i,0,N){
        print(lp[i].second+1);
    }



}
