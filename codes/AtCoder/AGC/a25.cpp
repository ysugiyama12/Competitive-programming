#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    int N;
    cin >> N;
    int count_min = 10000000;
    rep(i,1,N){
        int ans = 0;
        string a = to_string(i);
        string b = to_string(N-i);
        rep(j,0,a.size()){
            ans += a[j] - '0';
        }
        rep(j,0,b.size()){
            ans += b[j] - '0';
        }
        count_min = min(count_min,ans); 
    }
    print(count_min);
    
    cin.tie(0);
    ios::sync_with_stdio(false);
}
