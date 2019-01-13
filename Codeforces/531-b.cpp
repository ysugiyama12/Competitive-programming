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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll a[5010];
    rep(i,0,N){
        cin >> a[i];
    }
    map<ll, ll> mp;
    rep(i,0,N){
        mp[a[i]]++;
    }
    rep(i,0,5010){
        if(mp[i] > K){
            print("NO");
            return 0;
        }
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(a[i], i));
    }
    sort(lp.begin(), lp.end());
    ll ans[5010] = {};
    rep(i,0,N){
        ans[lp[i].second] = (i % K) + 1;
    }
    print("YES");
    printa(ans, N);
    // map<ll, ll> cnt;
    // print("YES");
    // rep(i,0,N){
    //     cout << cnt[a[i]]+1;
    //     cnt[a[i]]++;
    //     if(i != N-1) cout << " ";
    // }
    // cout << endl;
}
