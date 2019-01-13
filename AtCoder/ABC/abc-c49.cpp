#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll pos = 0;
    bool is_ok = true;
    ll N = S.size();
    reverse(S.begin(), S.end());
    while(1){
        if(pos == N) break;
        if(pos + 5 > N){
            is_ok = false;
            break;
        }
        if(pos + 5 == N){
            string s1 = S.substr(pos,5);
            if(s1 == "maerd" || s1 == "esare"){
                pos += 5;
            }else{
                is_ok = false;
                break;
            }
        }else if(pos + 6 == N){
            string s1 = S.substr(pos,5);
            string s2 = S.substr(pos,6);
            if(s1 == "maerd" || s1 == "esare"){
                pos += 5;
            }else if(s2 == "resare"){
                pos += 6;
            }else{
                is_ok = false;
                break;
            }
        }else{
            string s1 = S.substr(pos,5);
            string s2 = S.substr(pos,6);
            string s3 = S.substr(pos,7);
            if(s1 == "maerd" || s1 == "esare"){
                pos += 5;
            }else if(s2 == "resare"){
                pos += 6;
            }else if(s3 == "remaerd"){
                pos += 7;
            }else{
                is_ok = false;
                break;
            }
        }
    }
    if(is_ok){
        print("YES");
    }else{
        print("NO");
    }
}
