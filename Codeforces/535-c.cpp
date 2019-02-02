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
    ll N;
    string S;
    cin >> N >> S;
    string rgb = "BGR";
    string ss = "";
    ll min_val = INF;
    do{
        ll v = 0;
        rep(i,0,N){
            if(S[i] != rgb[i%3]) v++;
        }
        // print(rgb);
        // print(v);
        if(min_val > v){
            min_val = v;
            ss = rgb;
        }


    }while(next_permutation(rgb.begin(), rgb.end()));
    print(min_val);
    rep(i,0,N){
        cout << ss[i%3];
    }
    cout << endl;
}
