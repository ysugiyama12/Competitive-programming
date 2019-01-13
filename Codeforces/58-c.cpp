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
bool comp(pair<lpair, ll> l1, pair<lpair, ll> l2){
    if(l1.first.first == l2.first.first){
        return l1.first.second < l2.first.second;
    }
    return l1.first.first < l2.first.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    rep(i,0,T){
        ll N;
        ll l[100010], r[100010];
        cin >> N;
        rep(i,0,N){
            cin >> l[i] >> r[i];
        }
        vector< pair<lpair, ll> > lp;
        rep(i,0,N){
            lp.push_back(make_pair(make_pair(l[i], r[i]), i));
        }
        sort(lp.begin(), lp.end(), comp);
        ll mv1 = -1, mv2 = -1;
        bool flg = true;
        bool one_flg = true;
        ll ans[100010] = {};
        mv1 = lp[0].first.second;
        ans[lp[0].second] = 1;
        rep(i,1,N){
            ll idx = lp[i].second;
            if(mv1 < lp[i].first.first){
                ans[idx] = 2;
                mv2 = max(mv2, lp[i].first.second);
                one_flg = false;
            }else{
                if(mv2 < lp[i].first.first){
                    ans[idx] = 1;
                    mv1 = max(mv1, lp[i].first.second);
                }else{
                    flg = false;
                }
            }
        }
        if(one_flg || !flg){
            print(-1);
        }else{
            rep(i,0,N){
                if(i == N-1){
                    cout << ans[i];
                }else{
                    cout << ans[i] << " ";
                }
            }
            cout << endl;
        }


    }
}
