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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    ll pos = -1;
    rep(i,0,N){
        if(A[i] == N) pos = i;
    }
    bool ok = true;
    rep(j,pos+1,N-1){
        if(A[j] < A[j+1]) ok = false;
    }
    rrep(j,pos-1,0){
        if(A[j] > A[j+1]) ok = false;
    }
    if(ok){
        print("YES");
    }else{
        print("NO");
    }


    
}