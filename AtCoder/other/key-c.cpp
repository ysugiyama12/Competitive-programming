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
    ll N;
    ll A[100010], B[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,N){
        cin >> B[i];
    }
    ll val = 0;
    ll diff[100010] = {};
    rep(i,0,N){
        val += (B[i] - A[i]);
        diff[i] = (B[i] - A[i]);
    }
    if(val > 0){
        print(-1);
        return 0;
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(diff[i], i));
    }
    sort(lp.begin(), lp.end());
    // printp(lp,N);
    ll plus_cnt = 0;
    ll ans1 = 0;
    rep(i,0,N){
        if(diff[i] > 0){
            plus_cnt += diff[i];
            ans1++;
        }
    }
    if(ans1 == 0){
        print(0);
        return 0;
    }
    // print(ans1);
    ll idx = 0;
    while(1){
        ll pp = lp[idx].second;
        ll diffs = lp[idx].first;
        ll v1 = abs(diffs);
        plus_cnt -= v1;
        if(plus_cnt <= 0) break;
        idx++;
    }
    print(ans1 + idx + 1);


}
