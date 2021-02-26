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
    cin >> N >> M;
    ll A[100010];
    rep(i,0,N){
        cin >> A[i];
        A[i]--;
    }
    map<ll, ll> mp;
    rep(i,0,N-1){
        mp[A[i+1]] += (A[i+1] - A[i] + M) % M - 1;
    }
    ll sum[100010] = {};
    rep(i,0,N-1){
        if(A[i] < A[i+1]){
            sum[A[i]+1]++;
            sum[A[i+1]]--;
        }else{
            sum[A[i]+1]++;
            sum[0]++;
            sum[A[i+1]]--;
        }
    }
    rep(i,0,M+1) sum[i+1] += sum[i];
    ll val = 0;
    rep(i,0,N-1){
        val += min((A[i+1] - A[i] + M) % M, 1 + (A[i+1] + M) % M);
    }
    ll ans = INF;
    rep(i,0,M){
        ans = min(ans, val);
        val -= sum[i];
        val += mp[i];
    }
    print(ans);
}