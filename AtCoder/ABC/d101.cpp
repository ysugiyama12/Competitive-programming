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
ll keta(ll n){
    ll res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    vector<ll> num;
    rep(i,0,16){
        rep(k,1,150){
            if(i == 0 && k == 1) continue; 
            num.push_back(k * pow(10,i) - 1);
        }
    }
    sort(num.begin(), num.end());
    unique(num.begin(), num.end());
    // printa(num, num.size());
    vector<ll> ans;
    ll N = num.size();
    rep(i,0,N){
        // print(i);
        bool ok = true;
        rep(j,i+1,N){
            double d1 = (double)num[i] / (double)keta(num[i]);
            double d2 = (double)num[j] / (double)keta(num[j]);
            // print2(d1,d2);
            if(d1 > d2){
                ok = false;
            }
        }
        if(ok) ans.push_back(num[i]);
    }
    rep(i,0,K){
        print(ans[i]);
    }
}
