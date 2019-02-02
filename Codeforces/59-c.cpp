#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    ll a[200010];
    string s;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    cin >> s;
    vector<ll> vp;
    priority_queue<ll, vector<ll> > pq;
    pq.push(a[0]);
    ll ans = 0;
    rep(i,1,n){
        if(s[i] == s[i-1]){
            pq.push(a[i]);
        }else{
            ll cnt = 0;
            while(!pq.empty()){
                ll v = pq.top();
                pq.pop();
                if(cnt < k){
                    ans += v;
                    cnt++;
                }
            }
            pq.push(a[i]);
        }
    }
    ll cnt = 0;
    while(!pq.empty()){
        ll v = pq.top();
        pq.pop();
        if(cnt < k){
            ans += v;
            cnt++;
        }
    }
    print(ans);
    // rep(i,1,n){
    //     if(s[i] != s[i-1]){
    //         vp.push_back(cnt);
    //         cnt = 1;
    //     }else{
    //         cnt++;
    //     }
    // }
    // vp.push_back(cnt);

    // rep(i,0,n){
    //     lp[s[i]-'a'].push_back(a[i]);
    // }
    // rep(i,0,26){
    //     sort(lp[i].begin(), lp[i].end(), greater<ll>());
    // }
    // ll ans = 0;
    // rep(i,0,26){
    //     ll sz = lp[i].size();
    //     ll cnt = min(sz, k);
    //     rep(j,0,cnt){
    //         ans += lp[i][j];
    //     }
    //     print(ans);
    // }
    // print(ans);
}
