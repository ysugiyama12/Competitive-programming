#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int ans = N;
    rep(i,0,N+1){
        int six = i;
        int tmp = 0;
        while(six > 0){
            tmp += six % 6;
            six = (six - (six%6)) / 6;
        }
        int nine = N - i;
        while(nine > 0){
            tmp += nine % 9;
            nine = (nine - (nine%9)) / 9;
        }
        ans = min(ans,tmp);
    }

    print(ans);
    return 0; 
}
