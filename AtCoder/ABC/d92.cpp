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

    int A,B;
    cin >> A >> B;

    vector< vector<char> > r(100, vector<char>(100, '.'));
    rep(i, 0, 50){
        rep(j,0,100){
            r[i][j] = '#';
        }
    }
    int count_a = A-1;
    int count_b = B-1;
    rep(i,0,50){
        rep(j,0,100){
            if (i%2==0 && count_a > 0 && j%2 == 0){
                r[i][j] = '.';
                count_a--;

            }  
        }
    }
    rep(i,50,100){
        rep(j,0,100){
            if (i%2==0 && count_b > 0 && j%2 == 0 && i != 50){
                r[i][j] = '#';
                count_b--;

            }
        }
   }
   print("100 100");
   rep(i,0,100){
       rep(j,0,100){
           cout << r[i][j];
       }
       print("");
   }
}
