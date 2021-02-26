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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        string D;
        cin >> D;
        vector<ll> pos[11];
        rep(i,0,N){
            ll n = D[i] - '0';
            pos[n].push_back(i);
        }
        map<ll,ll> mp;
        ll last_pos = -1;
        rep(k,0,10){
            bool end = false;
            rep(i,0,pos[k].size()){
                if(last_pos < pos[k][i]){
                    // print2(k, pos[k]);
                    mp[pos[k][i]]++;
                    last_pos = pos[k][i];
                }else{
                    end = true;
                }
            }
            if(end) break;
        }
        ll last_val = -1;
        bool ok = true;
        rep(i,0,N){
            if(mp[i] == 0){
                if(last_val > D[i] - '0'){
                    ok = false;
                    break;
                }else{
                    last_val = D[i] - '0';
                }
            }
        }
        if(not ok){
            print("-");
        }else{
            rep(i,0,N){
                if(mp[i] == 0) cout << '2';
                else cout << '1';
            }
            cout << endl;
        }


    }
}