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

typedef struct{
    ll rate;
    ll hand;
    ll idx;
} ee;
bool comp(ee l1, ee l2){
    if(l1.rate == l2.rate){
        return l1.hand < l2.hand;
    }
    return l1.rate < l2.rate;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll R[100010], H[100010];
    cin >> N;
    rep(i,0,N){
        cin >> R[i] >> H[i];
    }
    vector<ee> dt;
    rep(i,0,N){
        ee tmp = {R[i], H[i], i};
        dt.push_back(tmp);
    }
    // vector<lpair> lp;
    // rep(i,0,N){
    //     lp.push_back(make_pair(R[i], H[i]));
    // }
    sort(dt.begin(), dt.end(), comp);
    ll hand[3] = {};
    ll rate = dt[0].rate;
    hand[dt[0].hand-1]++;
    ll start_pos = 0;
    ll ans_win[100010] = {};
    ll ans_even[100010] = {};
    ll ans_lose[100010] = {};
    rep(i,1,N){
        if(dt[i].rate == rate){
            hand[dt[i].hand-1]++;
        }else{
            rep(n,start_pos, i){
                ll j = dt[n].idx;
                ans_win[j] += start_pos;
                ans_lose[j] += N - i;
                if(dt[n].hand == 1){
                    ans_even[j] += hand[0] - 1;
                    ans_win[j] += hand[1];
                    ans_lose[j] += hand[2];

                }else if(dt[n].hand == 2){
                    ans_even[j] += hand[1] - 1;
                    ans_win[j] += hand[2];
                    ans_lose[j] += hand[0];

                }else{
                    ans_even[j] += hand[2] - 1;
                    ans_win[j] += hand[0];
                    ans_lose[j] += hand[1];
                }
            }
            start_pos = i;
            rate = dt[i].rate;
            rep(j,0,3){
                hand[j] = 0;
            }
            hand[dt[i].hand-1]++;
        }
    }
    rep(n,start_pos,N){
        ll j = dt[n].idx;
        ans_win[j] += start_pos;
        if(dt[n].hand == 1){
            ans_even[j] += hand[0] - 1;
            ans_win[j] += hand[1];
            ans_lose[j] += hand[2];

        }else if(dt[n].hand == 2){
            ans_even[j] += hand[1] - 1;
            ans_win[j] += hand[2];
            ans_lose[j] += hand[0];

        }else{
            ans_even[j] += hand[2] - 1;
            ans_win[j] += hand[0];
            ans_lose[j] += hand[1];
        }
    }
    rep(i,0,N){
        cout << ans_win[i] << " " << ans_lose[i] << " " << ans_even[i] << endl;
    }


}
