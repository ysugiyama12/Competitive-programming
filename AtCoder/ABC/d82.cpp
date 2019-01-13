#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
bool dp[8010][16010];

vector<string> split(string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);
 
    vector<string> result;
 
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
    string s;
    int x,y;
    cin >> s >> x >> y;
    int m = 8010;
    
    int N = s.size();
    vector<string> result = split(s, 'T');
    printa(result, result.size());
    vector<int> rl;
    vector<int> ud;
    rep(i,0,result.size()){
        if(i % 2 == 0){
            rl.push_back(result[i].size());
        }else{
            ud.push_back(result[i].size());
        }
    }
    printa(rl, rl.size());
    printa(ud, ud.size());
    rep(i,0,8010){
        rep(j,0,16010){
            dp[i][j] = false;
        }
    }
    dp[0][rl[0]+m] = true;
    int n1 = rl.size();
    rep(i,1,n1){
        rep(j,0,x+1){
            dp[i][j+m] = dp[i-1][j-rl[i]] | dp[i-1][j+rl[i]];
        }
    }
    print(dp[n1-1][x]);

}
