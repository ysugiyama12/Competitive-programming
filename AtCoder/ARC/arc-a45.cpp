#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
vector<string> split(string str, char del) { //文字列分割
    ll first = 0;
    ll last = str.find_first_of(del);
    vector<string> result;
    if(last == string::npos){
        result.push_back(str);
        return result;
    }
    while (first < str.size()) {
        string subStr(str, first, last - first);

        result.push_back(subStr);

        first = last + 1;
        last = str.find_first_of(del, first);

        if (last == string::npos) {
            last = str.size();
        }
    }
    return result;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    getline(cin, S);
    vector<string> ss = split(S, ' ');
    rep(i,0,ss.size()){
        if(ss[i] == "Right"){
            cout << '>';
        }else if(ss[i] == "Left"){
            cout << '<';
        }else{
            cout << 'A';
        }
        if(i != ss.size()-1) cout << ' ';

    }
    cout << endl;

}
