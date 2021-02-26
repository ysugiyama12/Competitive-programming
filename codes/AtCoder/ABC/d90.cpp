#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(){
    int N,K,i,j;
    cin >> N >> K;
    ll ans = 0;
    for(int b = 1; b <= N; b++){
        if (b > K){
            ans += (N/b) * (b - K);
            int tmp = (N/b) * b;

            int last_num = N - tmp;
            
            if(last_num - K >= 0){
                if (K == 0){
                    ans += last_num - K;
                }else{
                    ans += last_num - K + 1;
                }
            }
        }

    }
    cout << ans << endl;
}
