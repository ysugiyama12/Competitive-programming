/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll num_henka[2010][2010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    string S[2010];
    rep(i,0,N) cin >> S[i];
    ll ans = 0;
    //ヨコ
    rep(i,0,N){
        vector<ll> pos;
        rep(j,0,N){
            if(S[i][j] == 'B') pos.push_back(j);
        }
        ll sz = pos.size();
        if(sz == 0){
            ans++;
            continue;
        }
        ll start = pos[0];
        ll end = pos[sz-1];
        if(end - start > K) continue;
        ll top = max(0LL, i - K+1);
        ll bottom = i;
        ll lv = max(0LL, end - K + 1);
        ll rv = start;
        num_henka[top][lv]++;
        num_henka[top][rv+1]--;
        num_henka[bottom+1][lv]--;
        num_henka[bottom+1][rv+1]++;
    }
    //タテ
    rep(j,0,N){
        vector<ll> pos;
        rep(i,0,N){
            if(S[i][j] == 'B') pos.push_back(i);
        }
        ll sz = pos.size();
        if(sz == 0){
            ans++;
            continue;
        }
        ll start = pos[0];
        ll end = pos[sz-1];
        if(end - start > K) continue;
        ll top = max(0LL, end - K+1);
        ll bottom = start;
        ll lv = max(0LL, j - K + 1);
        ll rv = j;
        num_henka[top][lv]++;
        num_henka[top][rv+1]--;
        num_henka[bottom+1][lv]--;
        num_henka[bottom+1][rv+1]++;
    }
    rep(i,0,N){
        rep(j,0,N+1){
            num_henka[i][j+1] += num_henka[i][j];
        }
    }
    rep(j,0,N){
        rep(i,0,N+1){
            num_henka[i+1][j] += num_henka[i][j];
        }
    }
    ll ans2 = 0;
    rep(i,0,N-K+1){
        rep(j,0,N-K+1){
            ans2 = max(ans2, num_henka[i][j]);
        }
    }
    ans += ans2;
    print(ans);

}