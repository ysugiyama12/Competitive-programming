#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;
int test(){
    //[0,2,2,6,8,8,10]
    int a[7];
    for(int i = 0; i < 5; i++){
        a[i] = i * 2;
    }
    a[2] = 2;
    a[5] = 8;
    a[6] = 10;
    cout << upper_bound(a, a+7, 12) - lower_bound(a, a+7, 11) << endl;
    return 0;
}

int main(){
    //test();
    int N,i,j,k;
    cin >> N;
    ll a[N], b[N];
    for(i = 0; i < N; i++){
        cin >> a[i];
    }
    for(i = 0; i < N; i++){
        cin >> b[i];
    }

    ll ans = 0;
    for(k = 0; k < 30; k++){
        ll a1[N], b1[N];
        ll T = pow(2,k);
        for( j = 0; j < N; j++){
            a1[j] = a[j] % (2 * T);
            b1[j] = b[j] % (2 * T);
        }
        sort(b1, b1+N);
        ll count = 0;
        for(j = 0; j < N; j++){
            //int pos_1 = lower_bound(b1, b1+N, T - a1[j]);
            //int pos_2 = lower_bound(b1, b1+N, 2 * T - a1[j]);
            //int pos_3 = lower_bound(b1, b1+N, 3 * T - a1[j]);
            //int pos_4 = lower_bound(b1, b1+N, 4 * T - a1[j]);
            //cout << pos_1 << pos_2 << pos_3 << pos_4 << endl;
            //count += pos_2 - pos_1 + pos_4 - pos_3;
            
            count += lower_bound(b1, b1+N, 4 * T - a1[j]) - lower_bound(b1, b1+N, 3 * T - a1[j]) + lower_bound(b1, b1+N, 2 * T - a1[j]) - lower_bound(b1, b1+N, T - a1[j]);
        }
        if(count % 2 == 1){
            ans += pow(2, k);
        }
    }
    cout << ans << endl;
}
