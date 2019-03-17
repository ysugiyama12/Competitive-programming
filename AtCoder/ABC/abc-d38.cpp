#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

bool comp(lpair l1, lpair l2){
    if(l1.first == l2.first){
        return l1.second > l2.second;
    }
    return l1.first < l2.first;
}

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll w[100010], h[100010];
    cin >> N;
    vector<lpair> lp;
    rep(i,0,N){
        cin >> w[i] >> h[i];
        lp.push_back(make_pair(w[i], h[i]));
    }
    sort(lp.begin(), lp.end(), comp);
    ll dp[100010];
    fill(dp, dp+N, INF);
    rep(i,0,N){
        ll pos = lower_bound(dp, dp+N, lp[i].second) - dp;
        dp[pos] = lp[i].second;
    }
    rrep(i,N-1,0){
        if(dp[i] != INF){
            print(i+1);
            return 0;
        }
    }
}
