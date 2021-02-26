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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll B[110];
    cin >> N;
    rep(i,0,N) cin >> B[i];
    vector<ll> pos;
    rep(i,0,N) pos.push_back(B[i]);
    bool ok = true;
    vector<ll> ans;
    rep(t,0,N){
        ll pp = -1;
        rrep(i,N-t-1,0){
            if(pos[i] == i+1){
                pp = i+1;
                break;
            }
        }
        if(pp == -1){
            ok = false;
            break;
        }
        ans.push_back(pp);
        pos.erase(pos.begin() + pp-1);
    }
    if(not ok){
        print(-1);
        return 0;
    }
    reverse(ans.begin(), ans.end());
    rep(i,0,ans.size()) print(ans[i]);
    // vector<ll> v;
    // ll pos[110] = {};
    // rep(i,1,N+1) pos[i] = B[i-1];
    // bool ok = true;
    // vector<ll> ans;
    // rep(t,0,N){
    //     ll pp = -1;
    //     rrep(i,N-t,1){
    //         if(i == pos[i]){
    //             pp = i;
    //             break;
    //         }
    //     }
    //     if(pp == -1){
    //         ok = false;
    //         break;
    //     }
    //     ans.push_back(pp);
    //     rep(i,pp+1,N-t+1){
    //         pos[i-1] = pos[i];
    //     }
    // }
    // reverse(ans.begin(), ans.end());
    // if(!ok){
    //     print(-1);
    //     return 0;
    // }
    // rep(i,0,N){
    //     print(ans[i]);
    // }
    // rep(i,0,N) v.push_back(B[i]);
    // rep(t,0,N){

    // }
    
}