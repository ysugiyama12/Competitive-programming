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
    string S;
    cin >> N >> S;
    ll depth = 0;
    ll cnt = 0;
    rep(i,0,N){
        if(S[i] == '('){
            cnt++;
        }else{
            cnt--;
        }
        depth = max(depth, cnt);
    }
    ll v = (depth + 1) / 2;
    cnt = 0;
    rep(i,0,N){
        if(S[i] == '('){
            cnt++;
            if(cnt > v){
                cout << '1';
            }else{
                cout << '0';
            }
        }else{
            if(cnt > v){
                cout << '1';
            }else{
                cout << '0';
            }
            cnt--;
        }
    }
    cout << endl;

    
}