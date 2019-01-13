#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
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

    int K;
    cin >> K;
    vector<ll> v;
    rep(i,0,9){
        v.push_back(i+1);
    }
    rep(i,0,9){
        ll num = (i+1) * 10 + 9;
        v.push_back(num);
    }
    rep(i,0,9){
        ll num = (i+1) * 100 + 99;
        v.push_back(num);
    }
    rep(i,4,16){
        int max = 9 + (i-3)* 10;
        
        rep(j,10,max+1){
            if(j <= 99){
                ll num = (j+1) * pow(10,i-2) - 1;
                v.push_back(num);
            }else{
                ll num = (j+1) * pow(10,i-3) - 1;
                v.push_back(num);
            }
        }
        if(max <= 99){
        ll tmp = (max+1) * pow(10,i-2) - 1;
        tmp += pow(10,i-1);
        while(tmp <= pow(10, i)){
            v.push_back(tmp);
            tmp += pow(10,i-1);
        }
        }else{
                    ll tmp = (max+1) * pow(10,i-3) - 1;
        tmp += pow(10,i-2);
        while(tmp <= pow(10, i-1)){
            v.push_back(tmp);
            tmp += pow(10,i-2);
        }
        }

    }
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    rep(i,0,K){
        print(v[i]);
    }

    // int count[100001];
    // rep(i,1,100001){
    //     int cn = 0;
    //     int n = i;
    //     while(n > 0){
    //         cn += n % 10;
    //         n /= 10;

    //     }
    //     count[i] = cn;
    // }
    // rep(i,1,100001){
    //     bool flg = true;
    //     rep(j, i+1, 100001){
    //         double n1 = double(i)/double(count[i]);
    //         double n2 = double(j)/double(count[j]);
    //         if(n1 >= n2){
    //             flg = false;
    //         }
    //     }
    //     if(flg){
    //         print(i);
    //     }
    // }

}
