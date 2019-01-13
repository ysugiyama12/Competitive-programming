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
    ll N,R;
    char S[110];
    cin >> N >> R;
    rep(i,0,N){
        cin >> S[i];
    }
    ll pos = 0;
    rrep(i,N-1,0){
        if(S[i] == '.'){
            pos = max(0LL, i-R+1);
            break;
        }
    }
    ll cnt = 0;
    rep(i,0,N){
        if(S[i] == '.'){
            cnt++;
            ll mv = min(N, i+R);
            rep(j,i,mv){
                S[j] = 'o';
            }
        }
    }
    print(pos + cnt);
    // ll pos = 0;
    // while(cnt > 0){
    //     ll mv = min(N, pos+R);
    //     ll tt = 0;
    //     bool flg = false;
    //     rep(i,pos, mv){
    //         if(S[i] == '.'){
    //             flg = true; tt++;
    //         }
    //     }
    //     print(flg);
    //     if(!flg){
    //         ans++;
    //         pos++;
    //     }else{
    //         cnt -= tt;
    //         ans++;
    //         rep(i,pos,mv){
    //             S[i] = 'o';
    //         }
    //     }
    // }
    // print(ans);
}
