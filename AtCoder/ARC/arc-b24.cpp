#include <bits/stdc++.h>

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll C[100010];
    cin >> N;
    bool is_one = true, is_zero = true;
    rep(i,0,N){
        cin >> C[i];
        if(C[i] == 1) is_zero = false;
        if(C[i] == 0) is_one = false;
    }
    if(is_one || is_zero){
        print(-1);
        return 0;
    }
    vector<ll> v1,v2;
    ll idx = 0;
    rep(i,0,N){
        if(C[i] == 1){
            idx = i;
            break;
        }
    }
    ll cnt = 0;
    rep(i,0,N){
        if(C[(idx+1+i) % N] == 0){
            cnt++;
        }else{
            v1.push_back(cnt);
            cnt = 0;
        }
    }
    idx = 0;
    rep(i,0,N){
        if(C[i] == 0){
            idx = i;
            break;
        }
    }
    cnt = 0;
    rep(i,0,N){
        if(C[(idx+1+i) % N] == 1){
            cnt++;
        }else{
            v2.push_back(cnt);
            cnt = 0;
        }
    }
    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), greater<ll>());
    ll ans = max(v1[0], v2[0]);
    ans = (ans - 1)/2 + 1;
    // rep(i,0,v1.size()){
    //     if(v1[i] >= 3){
    //         ans += (v1[i] - 3)/2 + 1;
    //     }
    // }
    // rep(i,0,v2.size()){
    //     if(v2[i] >= 3){
    //         ans += (v2[i] - 3)/2 + 1;
    //     }
    // }
    print(ans);
}
