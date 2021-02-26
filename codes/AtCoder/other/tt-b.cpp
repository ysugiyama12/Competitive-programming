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
    string S;
    cin >> S;
    ll N = S.size();
    ll pos[110] = {};
    ll is_used[110] = {};
    rrep(i,N-1,0){
        if(is_used[i] == 1) continue;
        is_used[i] = 1;
        if(S[i] == '('){
            pos[i] = 1;
            S[i] = ')';
        }
        ll v = -1;
        rrep(j,i-1,0){
            if(is_used[j] == 0 && S[j] == '('){
                v = j;
                break;
            }
        }
        if(v == -1){
            rep(j,0,i){
                if(is_used[j] == 0 && S[j] == ')'){
                    pos[j] = 1;
                    is_used[j] = 1;
                    S[j] = '(';
                    break;
                }
            }
        }else{
            is_used[v] = 1;
        }

    }
    // printa(pos,N);
    ll ans = 0;
    ll last_pos = 0;
    rep(i,0,N){
        if(pos[i] == 1){
            ans++;
            last_pos = i;
        }
    }
    ans += last_pos;
    print(ans);
    // ll lv = 0, rv = 0;
    // ll ans = 0;
    // ll pos[110] = {};
    // rep(i,0,N){
    //     if(S[i] == '('){
    //         lv++;
    //         if(lv > (N-i)){
    //             pos[i] = 1;
    //             lv--;
                
    //         }
            
    //     }else{
    //         if(lv > 0){
    //             lv--;
    //         }else{
    //             pos[i] = 1;
    //             lv++;
    //         }
    //     }
    // }
    // ll last_pos = 0;
    // rep(i,0,N){
    //     if(pos[i] == 1){
    //         ans++;
    //         last_pos = i;
    //     }
    // }
    // printa(pos,N);
    // ans += last_pos;
    // print(ans);
    
}
