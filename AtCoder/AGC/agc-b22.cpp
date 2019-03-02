#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> ans;
    ll v2 = N/2;
    if(v2 % 2 == 1){
        v2++;
    }
    ll idx = 0;
    ll n = 0;
    while(idx < v2){
        if(n % 3 == 0){
            n++;
        }else{
            ans.push_back(2*n);
            idx++;
            n++;
        }
    }
    ll v3 = N - v2;
    ll ss = 0;
    rep(i,0,v3){
        ans.push_back(3*(i+1));
        ss += 3 * (i+1);
    }
    if(ss % 2 == 1){
        ans[N-1] += 3;
    }
    if(N == 3){
        print("2 5 63");
    }else{
        printa(ans, N);
    }
    // bool ok = true;
    // rep(i,0,N){
    //     ll sum = 0;
    //     rep(j,0,N){
    //         if(i == j) continue;
    //         sum += ans[j];
    //     }
    //     if(gcd(ans[i], sum) == 1) ok = false;

    //     print2(sum, gcd(ans[i], sum));
    // }
    // if(!ok) print("invalid");


}
