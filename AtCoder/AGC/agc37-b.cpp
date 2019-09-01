/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll pos[300010] = {};
    set<ll> rpos, gpos, bpos;
    rep(i,0,3*N){
        if(S[i] == 'R') rpos.insert(i);
        else if(S[i] == 'G') gpos.insert(i);
        else bpos.insert(i);
    }

    rrep(i,3*N-1,0){
        if(pos[i] == 0){
            pos[i] = 3;
            if(S[i] == 'R'){
                auto it1 = gpos.lower_bound(i);
                auto it2 = bpos.lower_bound(i);
                it1--; it2--;
                ll vg = *it1, vb = *it2;
                if(vg > vb){ // delete G
                    pos[vg] = 2;
                    pos[vb] = 1;
                }else{
                    pos[vb] = 2;
                    pos[vg] = 1;
                }
                gpos.erase(it1);
                bpos.erase(it2);

            }else if(S[i] == 'G'){
                auto it1 = rpos.lower_bound(i);
                auto it2 = bpos.lower_bound(i);
                it1--; it2--;
                ll vr = *it1, vb = *it2;
                if(vr > vb){ // delete G
                    pos[vr] = 2;
                    pos[vb] = 1;
                }else{
                    pos[vb] = 2;
                    pos[vr] = 1;
                }
                rpos.erase(it1);
                bpos.erase(it2);
            }else{
                auto it1 = rpos.lower_bound(i);
                auto it2 = gpos.lower_bound(i);
                it1--; it2--;
                ll vr = *it1, vg = *it2;
                if(vr > vg){ // delete G
                    pos[vr] = 2;
                    pos[vg] = 1;
                }else{
                    pos[vg] = 2;
                    pos[vr] = 1;
                }
                rpos.erase(it1);
                gpos.erase(it2);
            }
        }
    }
    // printa(pos, 3*N);
    ll ans = 1;
    map<ll, ll> mp;
    mp[0] = N;
    rep(i,0,3*N){
        ans *= mp[pos[i]-1];
        ans %= MOD;
        mp[pos[i]-1]--;
        mp[pos[i]]++;
    }
    print(ans);
    
}