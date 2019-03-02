#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    ll sum = 0;
    rep(i,0,N) sum += A[i];
    ll n = N*(N+1)/2;
    if(sum % n != 0){
        print("NO");
        return 0;
    }
    ll v = sum / n;
    ll cnt4 = 0;
    bool ok = true;
    rep(i,0,N-1){
        ll diff = A[i+1] - A[i];
        if(diff > v){
            ok = false;
        }else if(diff == v){
            continue;
        }else{
            ll v2 = v - diff;
            if(v2 % N != 0){
                ok = false;
            }else{
                cnt4 += v2/N;
            }
        }
    }
    if(!ok){
        print("NO");
    }else{
        if(cnt4 <= v){
            print("YES")
        }else{
            print("NO");

        }
    }



}
