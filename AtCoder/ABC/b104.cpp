#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int n = S.size();
    int count = 0;
    int s = 2;
    int g = n - 2;
    if(S[0] == 'A'){
        rep(i,s,g+1){

            if(S[i] == 'C'){
                count++;
            }
        }
        int count2 = 0;
        if(count == 1){
            rep(i,0,n){
                if(S[i] - 'a' < 0){
                    count2++;
                }
            }
            if(count2 == 2){
                print("AC");
                return 0;
            }
        }
    }
    print("WA");
}
