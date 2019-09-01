/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    ll A[500010];
    rep(i,0,N) cin >> A[i];
    ll val = 0;
    ll cnt_minus = 0;
    rep(i,0,N){
        if(A[i] != -1) val ^= A[i];
        else cnt_minus++;
    }
    if(cnt_minus == 0){
        if(val == X){
            printa(A,N);
        }else{
            print(-1);
        }
        return 0;
    }
    ll n = 1;
    vector<ll> ans;
    while(n <= X){
        n *= 2LL;
    }
    val ^= X;
    if(val >= n){
        print(-1);
        return 0;
    }else{
        if(cnt_minus == 1){
            if(val <= X){
                rep(i,0,N){
                    if(A[i] == -1){
                        ans.push_back(val);
                    }else{
                        ans.push_back(A[i]);
                    }
                }
            }else{
                print(-1);
                return 0;
            }

        }else{
            ll v1 = 0, v2 = 0;
            if(val >= (n/2)){
                v1 = n/2;
                v2 = (val ^ v1);
            }else{
                v1 = val;
                v2 = 0;
            }
            ll cnt = 1;
            rep(i,0,N){
                if(A[i] == -1){
                    if(cnt == 1){
                        ans.push_back(v1);
                        cnt++;
                    }else if(cnt == 2){
                        ans.push_back(v2);
                        cnt++;
                    }else{
                        ans.push_back(0);
                    }
                }else{
                    ans.push_back(A[i]);
                }
            }
        }
    }
    printa(ans, N);
    
}