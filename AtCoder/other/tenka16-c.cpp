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
string A[1010], B[1010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N) cin >> A[i] >> B[i];
    vector< pair<char, char> > alt;
    bool ok = true;
    rep(i,0,N){
        ll sz = min(A[i].size(), B[i].size());
        if(A[i].substr(0,sz) == B[i].substr(0,sz)){
            if(A[i].size() > B[i].size()){
                ok = false;
            }
            continue;
        }
        rep(j,0,sz){
            if(A[i][j] != B[i][j]){
                alt.push_back(make_pair(A[i][j], B[i][j]));
                break;
            }

        }
    }
    if(!ok){
        print(-1);
        return 0;
    }
    vector<ll> tree[30];
    ll n = alt.size();
    // for(auto &e: alt){
    //     print2(e.first, e.second);
    // }
    ll h[30] = {};
    rep(i,0,n){
        tree[alt[i].first - 'a'].push_back(alt[i].second - 'a');
        h[alt[i].second - 'a']++;
    }
    priority_queue< ll, vector<ll>, greater<ll> > pq;
    rep(i,0,26){
        if(h[i] == 0) pq.push(i);
    }
    vector<ll> ans;
    while(!pq.empty()){
        ll pos = pq.top();
        // print(pos);
        pq.pop();
        ans.push_back(pos);
        for(auto &e: tree[pos]){
            h[e]--;
            if(h[e] == 0) pq.push(e);
        }
    }
    if(ans.size() != 26){
        print(-1);
        return 0;
    }
    map<ll,ll> mp;
    rep(i,0,26){
        mp[ans[i]]++;
    }
    for(auto &e: mp){
        if(e.second != 1) ok = false;
    }

    if(!ok){
        print(-1);
        return 0;
    }
    rep(i,0,26){
        char c = ans[i] + 'a';
        cout << c;
    }
    cout << endl;
    // rep(i,0,alt.size()){
    //     cout << alt[i].first << " " << alt[i].second << endl;
    // }

}