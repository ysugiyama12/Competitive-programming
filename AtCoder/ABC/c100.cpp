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
    int a[10001];
    cin >> N;
    rep(i,0,N){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    int ans = 0;
    rep(i,0,N){
        while(a[i] % 2 == 0){
            a[i] /= 2;
            ans++;
        }
    }
    print(ans);

}
