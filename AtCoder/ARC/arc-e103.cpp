#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
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
    ll n = s.size();
    bool ok = true;
    if(s[0] == '0' || s[n-1] == '1') ok = false;
    rep(i,0,n/2){
        if(s[i] != s[n-2-i]) ok = false;
    }
    if(!ok){
        print(-1);
        return 0;
    }
    ll pos = 1, num = 2;;
    vector<lpair> lp;
    rep(i,0,n-1){
        if(s[i] == '1'){
            lp.push_back(make_pair(pos, num));
            pos = num;
            num++;
        }else{
            lp.push_back(make_pair(pos,num));
            num++;
        }
    }
    rep(i,0,n-1){
        cout << lp[i].first << " " << lp[i].second << endl;
    }
}
