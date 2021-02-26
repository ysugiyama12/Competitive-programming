#include <bits/stdc++.h>
#include <unordered_map>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
bool comp(lpair l1, lpair l2){
    if(l1.first == l2.first){
        return l1.second > l2.second;
    }
    return l1.first > l2.first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[1010], B[1010];
    bool flg = true;
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,M){
        cin >> B[i];
    }
    sort(A, A+N);
    sort(B, B+M);
    rep(i,0,N-1){
        if(A[i] == A[i+1]) flg = false;
    }
    rep(i,0,M-1){
        if(B[i] == B[i+1]) flg = false;
    }
    


}
