#include <bits/stdc++.h>
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    string ss = "";
    rep(i,0,N){
        if(S[i] != 'x') ss += S[i];
    }
    string tt = ss;
    reverse(tt.begin(), tt.end());
    if(ss != tt){
        print(-1);
        return 0;
    }
    ll rec_num = 0;
    ll idx = 0;
    ll pos[100010] = {};
    rep(i,0,N){
        if(S[i] != 'x'){
            rec_num++;
            pos[idx] = i;
            idx++;
        }
    }
    // printa(pos, N);
    ll x_cnt[100010] = {};
    rep(j,0,pos[0]){
        if(S[j] == 'x') x_cnt[0]++;
    }
    rep(i,0,rec_num-1){
        rep(j,pos[i], pos[i+1]){
            if(S[j] == 'x') x_cnt[i+1]++;
        }
    }
    rep(j,pos[rec_num-1], N){
        if(S[j] == 'x') x_cnt[rec_num]++;
    }
    // printa(x_cnt, N);
    ll ans = 0;
    // print(rec_num);
    rep(i,0,(rec_num+1)/2){
        ans += max(x_cnt[i], x_cnt[rec_num - i]) - min(x_cnt[i], x_cnt[rec_num - i]);
    }
    print(ans);

    // xxabxbxbaxxx
}
