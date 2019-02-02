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
ll dp_x[8010][16010] = {};
ll dp_y[8010][16010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    ll x,y;
    cin >> s >> x >> y;
    ll N = s.size();
    vector<string> st;
    ll idx = 0;
    rep(i,1,N){
        if(s[i] != s[i-1]){
            st.push_back(s.substr(idx,i-idx));
            idx = i;
        }else if(s[i] == 'T' && s[i-1] == 'T'){
            st.push_back(s.substr(idx,i-idx));
            idx = i;
        }
    }
    st.push_back(s.substr(idx, N-idx));
    ll m = st.size();
    vector<ll> xx, yy;
    ll mode = 0;
    rep(i,0,m){
        if(i == 0 && st[i] != "T"){
            x -= st[i].size();
        }else if(i != 0 && st[i] != "T"){
            if(mode == 0){
                xx.push_back(st[i].size());
            }else{
                yy.push_back(st[i].size());
            }
        }else{
            mode = (mode == 0 ? 1 : 0);
        }
    }
    ll mx = xx.size();
    ll my = yy.size();
    // printa(xx,mx);
    // printa(yy,my);
    dp_x[0][8000] = 1;
    dp_y[0][8000] = 1;
    rep(i,0,mx){
        rep(j,0,16000){
            if(j-xx[i] >= 0 && j-xx[i] <= 16000){
                dp_x[i+1][j] |= dp_x[i][j-xx[i]];
            }
            if(j+xx[i] >= 0 && j + xx[i] <= 16000){
                dp_x[i+1][j] |= dp_x[i][j+xx[i]];
            }
        }
    }
    rep(i,0,my){
        rep(j,0,16000){
            if(j-yy[i] >= 0 && j-yy[i] <= 16000){
                dp_y[i+1][j] |= dp_y[i][j-yy[i]];
            }
            if(j+yy[i] >= 0 && j + yy[i] <= 16000){
                dp_y[i+1][j] |= dp_y[i][j+yy[i]];
            }
        }
    }
    if(dp_x[mx][8000+x] && dp_y[my][8000+y]){
        print("Yes");
    }else{
        print("No");
    }

    
    
}
