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
ll N;
ll A[100010], B[100010];
bool comp(lpair l1, lpair l2){
    return l1.first + l1.second > l2.first + l2.second;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010], B[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i] >> B[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back(make_pair(A[i], B[i]));
    sort(lp.begin(), lp.end(), comp);
    ll ans = 0;
    rep(i,0,N){
        if(i % 2 == 0){
            ans += lp[i].first;
        }else{
            ans -= lp[i].second;
        }
    }
    print(ans);
}
