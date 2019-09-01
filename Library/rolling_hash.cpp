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

typedef unsigned long long ull;
const ull B = 1e9 + 7;
void contain(string a, string b){
    ll al = a.size();
    ll bl = b.size();
    if(al > bl) return;
    ull t = 1;
    rep(i,0,al) t *= B;
    ull ah = 0, bh = 0;
    rep(i,0,al) ah = ah * B + a[i];
    rep(i,0,al) bh = bh * B + b[i];
    for(ll i = 0; i + al <= bl; i++){
        if(ah == bh){
            print(i);
        }
        if(i + al < bl) bh = bh * B + b[i + al] - b[i] * t;
    }
    // return false;
    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string A,B;
    cin >> A >> B;
    contain(B, A);
    // print(overlap(A,B));
    
}