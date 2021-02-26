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
    vector<string> S(N);
    rep(i,0,N){ cin >> S[i];}

    ll march[5] = {};
    rep(i,0,N){
        if(S[i][0] == 'M'){ march[0]++;}
        else if(S[i][0] == 'A'){ march[1]++;}
        else if(S[i][0] == 'R'){ march[2]++;}
        else if(S[i][0] == 'C'){ march[3]++;}
        else if(S[i][0] == 'H'){ march[4]++;}
    }
    ll ans = 0;
    rep(i,0,5){
        rep(j,0,5){
            rep(k,0,5){
                if(i != j && j != k && i != k && i < j && j < k){
                    ans += march[i] * march[j] * march[k];

                }
            }
        }
    }
    print(ans);
}
