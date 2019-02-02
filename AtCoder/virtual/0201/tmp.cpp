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
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} //最大公約数
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;} //最小公倍数

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A,B;
    cin >> A >> B;
    ll N = B - A;
    vector<ll> odd, even, v3;
    for(ll i = A; i <= B; i++){
        if(i % 2 == 0){
            even.push_back(i);
        }else if(i % 3 == 0){
            v3.push_back(i);
        }else{
            odd.push_back(i);
        }
    }
    even.push_back(1);
    v3.push_back(1);
    ll no = odd.size();
    ll ne = even.size();
    ll n3 = v3.size();
    ll ans = 0;
    rep(bit,0,pow(2,no)){
        bool ok = true;
        rep(j,0,no){
            rep(k,j+1,no){
                if((bit>>j) & 1 && (bit>>k) & 1 && gcd(odd[j], odd[k]) != 1){
                    ok = false;
                }
            }
        }
        if(!ok) continue;

        // rep(j,0,ne){
        //     bool ok2 = true;
        //     rep(k,0,no){
        //         if((bit>>k) & 1 && gcd(even[j], odd[k]) != 1) ok2 = false;
        //     }
        //     if(ok2) ans++;
        // }
        rep(i,0,ne){
            rep(j,0,n3){
                bool ok2 = true;
                if(gcd(even[i], v3[j]) != 1) ok2 = false;
                rep(k,0,no){
                    if((bit>>k) & 1 && gcd(even[i], odd[k]) != 1) ok2 = false;
                    if((bit>>k) & 1 && gcd(v3[j], odd[k]) != 1) ok2 = false;
                }
                if(ok2) ans++;
            }
        }
    }
    print(ans);
}
