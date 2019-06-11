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
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;
    string S;
    cin >> S;
    ll ng[200010] = {};
    rep(i,0,N){
        if(S[i] == '#') ng[i] = 1;
    }
    bool ok = true;
    ll pos = A;
    while(1){
        if(pos == C) break;
        if(pos >= N){
            ok = false;
            break;
        }
        if(ng[pos+1] == 0){
            pos++;
        }else if(ng[pos+2] == 0){
            pos += 2;
        }else{
            ok = false;
            break;
        }
    }
    pos = B;
    while(1){
        if(pos == D) break;
        if(pos >= N){
            ok = false;
            break;
        }
        if(ng[pos+1] == 0){
            pos++;
        }else if(ng[pos+2] == 0){
            pos += 2;
        }else{
            ok = false;
            break;
        }
    }
    if(D < C){
        bool ok2 = false;
        rep(i,B,D+1){
            if(S[i-1] == '.' && S[i] == '.' &&  S[i+1] == '.'){
                ok2 = true;
            }
        }
        if(not ok2) ok = false;
    }
    if(ok){
        print("Yes");
    }else{
        print("No");
    }
}
