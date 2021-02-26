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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll X[100010], Y[100010];
    cin >> N >> M;
    rep(i,0,N) cin >> X[i] >> Y[i];
    priority_queue<lpair, vector<lpair>, greater<lpair> > pq;
    rep(i,0,min(N,M)) pq.push(make_pair(X[i]-Y[i], i));
    ll tt = 0;
    rep(i,0,min(N,M)){
        tt += X[i];
    }
    ll ans = tt;
    rep(i,M,N){
        tt += X[i];
        lpair l1 = pq.top();
        pq.pop();
        tt -= l1.first;
        pq.push(make_pair(X[i] - Y[i], i));
        ans = max(ans, tt);
    }
    print(ans);
    // ll tmp = 0;
    // rep(i,M,N){
    //     lpair v = pq.top();
    //     ll idx = v.second;
    //     if(Y[i] + X[idx] < X[i] + Y[idx]){
    //         pq.pop();
    //         pq.push(make_pair(X[i]-Y[i], i));
    //         ans += (X[i] - (X[idx] - Y[idx])) + tmp;
    //         tmp = 0;
    //     }else{
    //         tmp += Y[i];
    //     }
    // }
    // print(ans);

}