/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool up[200010] = {}, down[200010] = {};
    rep(i,K,N){
        if(S[i] - '0' < S[i%K] - '0') up[i] = true;
        else if(S[i] - '0' > S[i%K] - '0') down[i] = true;
    }
    bool ok = true;
    rep(i,K,N){
        if(up[i] == true){
            break;
        }else if(down[i] == true){
            ok = false;
            break;
        }
    }
    // print(ok);
    if(ok){
        print(N);
        rep(i,0,N){
            cout << S[i%K];
        }
        cout << endl;
        return 0;
    }
    rrep(i,K-1,0){
        if(S[i] != '9'){
            char c = S[i] + 1;
            S[i] = c;
            break;
        }else{
            S[i] = '0';
        }
    }
    print(N);
    rep(i,0,N){
        cout << S[i%K];
    }
    cout << endl;





    

}