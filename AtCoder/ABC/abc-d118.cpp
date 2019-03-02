#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
bool comp(string s1, string s2){
    if(s1.size() == s2.size()){
        return s1 > s2;
    }
    return s1.size() > s2.size();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll A[10];
    cin >> N >> M;
    rep(i,0,M) cin >> A[i];
    ll cnt[10] = {0,2,5,5,4,5,6,3,7,6};
    vector<lpair> lp;
    rep(i,0,M){
        lp.push_back(make_pair(A[i], cnt[A[i]]));
    }
    sort(lp.begin(), lp.end(), greater<lpair>());
    ll dp[10010] = {};
    rep(i,0,N+1){
        dp[i] = -INF;
    }
    dp[0] = 0;
    rep(i,1,N+1){
        rep(j,0,M){
            if(i - cnt[A[j]] >= 0){
                dp[i] = max(dp[i], dp[i - cnt[A[j]]] + 1);
            }
        }
    }
    // printa(dp, N+1);
    string ans = "";
    ll tt = N;
    rep(i,0,dp[N]){
        // print(tt);
        rep(j,0,M){
            ll num = lp[j].first;
            ll v = lp[j].second;
            // print(v);
            if(i == dp[N]-1){
                if(tt == v){
                    ans += to_string(num);
                    break;
                }
            }else if(dp[tt - v] + 1 == dp[tt]){
                tt -= v;
                ans += to_string(num);
                // print(ans);
                break;
            }
        }
    }
    print(ans);

}
