#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
vector<ll> tate[1010], yoko[1010];
ll A[1010][1010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,N){
        rep(j,0,M){
            cin >> A[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,M){
            yoko[i].push_back(A[i][j]);
            tate[j].push_back(A[i][j]);
        }
    }
    rep(i,0,N){
        sort(yoko[i].begin(), yoko[i].end());
    }
    rep(i,0,M){
        sort(tate[i].begin(), tate[i].end());
    }
    rep(i,0,N){
        // unique(yoko[i].begin(), yoko[i].end());
        yoko[i].erase(unique(yoko[i].begin(), yoko[i].end()), yoko[i].end());
    }
    rep(i,0,M){
        // unique(tate[i].begin(), tate[i].end());
        tate[i].erase(unique(tate[i].begin(), tate[i].end()), tate[i].end());
    }
    rep(i,0,N){
        rep(j,0,M){
            ll max_yoko = yoko[i].size();
            ll max_tate = tate[j].size();
            ll pos_yoko = upper_bound(yoko[i].begin(), yoko[i].end(), A[i][j]) - yoko[i].begin();
            ll pos_tate = upper_bound(tate[j].begin(), tate[j].end(), A[i][j]) - tate[j].begin();
            // print2(max_yoko, max_tate);
            // print2(pos_yoko, pos_tate);
            ll v1 = pos_tate;
            if(v1 - pos_yoko < 0){
                v1 += abs(v1 - pos_yoko);
            }
            ll ans = max(v1+(max_tate - pos_tate), v1+(max_yoko - pos_yoko));

            // ll v1 = pos_yoko;
            // if(pos_yoko - pos_tate < 0){
            //     v1 += abs(pos_yoko - pos_tate);
            // }
            // v1 += (max_tate - pos_tate);
            // v1 = min(v1, max_yoko);

            // ll v2 = pos_tate;
            // if(pos_tate-pos_yoko < 0){
            //     v2 += abs(pos_yoko - pos_tate);
            // }
            // v2 += max_yoko - pos_yoko;
            // v2 = min(v2, max_tate);
            cout << ans << " \n"[j == M-1];
        }
    }

    
}