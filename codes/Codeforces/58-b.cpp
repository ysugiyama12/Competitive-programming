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
    string s;
    cin >> s;
    ll pos1 = -1;
    ll N = s.size();
    rep(i,0,N){
        if(s[i] == '['){
            pos1 = i;
            break;
        }
    }
    ll pos2 = -1;
    rep(i,0,N){
        if(s[i] == ':' && i > pos1){
            pos2 = i;
            break;
        }
    }
    ll pos3 = -1;
    rrep(i,N-1,0){
        if(s[i] == ']' && i > pos2){
            pos3 = i;
            break;
        }
    }
    ll pos4 = -1;
    rrep(i,N-1,0){
        if(s[i] == ':' && i < pos3){
            pos4 = i;
            break;
        }
    }
    ll cnt = 0;
    if(pos1 != -1 && pos2 != -1 && pos3 != -1 && pos4 != -1 && pos2 != pos4){
        rep(i,0,N){
            if(i > pos2 && i < pos4 && s[i] == '|') cnt++;
        }
        print(4 + cnt);
    }else{
        print(-1);
    }

}
