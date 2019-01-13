#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
inline bool isPrime(ll x){ //素数かどうか判定
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=3;i<=sqrt(x)+1;i+=2) if(x%i==0) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    bool prime = false;
    if(N == 1){
        prime = false;
    }else if(isPrime(N)){
        prime = true;
    }else{
        ll sum = 0;
        ll n = N;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        if((N % 10) % 2 == 1 && N%10 != 5 && sum % 3 != 0){
            prime = true;
        }else{
            prime = false;
        }
    }
    if(prime){
        print("Prime");
    }else{
        print("Not Prime");
    }


}
