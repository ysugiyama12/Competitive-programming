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
    int A,B,N;
    cin >> A >> B >> N;
    string X;
    cin >> X;
    
    int count_a = A;
    int count_b = B;
    rep(i, 0, N){
        if(X[i] == 'S'){
            if(count_a > 0){
                count_a--;
            }
        }
        if(X[i] == 'C'){
            if(count_b > 0){
                count_b--;
            }
        }
        if(X[i] == 'E'){
            if(count_a == count_b && count_a > 0){
                count_a--;
            }else if(count_a > count_b){
                count_a--;
            }else if(count_a < count_b){
                count_b--;
            }
        }




    }
    print(count_a);
    print(count_b);
}
