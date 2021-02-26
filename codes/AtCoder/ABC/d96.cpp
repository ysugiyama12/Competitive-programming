#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i,j,N;
    cin >> N;
    vector<int> p;
    vector<int> is_prime(55556, 0);
    int n = 2;
    while(n <= 55555){
        bool is_calc = true;
        if (is_prime[n] == -1){
            is_calc = false;
        }else{
            is_prime[n] = 1;
        }
        int r = n;
        while(r <= 55555 && is_calc){
            if (r+n > 55555){
                break;
            }
            r += n;
            is_prime[r] = -1;
        }
        n += 1;
    }
    int count = 0;
    for(i = 2; i <= 55555; i++){
        if (is_prime[i] == 1 && i % 10 == 1){
            if (count < N){
                cout << i << " ";
            }
            count += 1;
        }

    }
    cout << endl;
}
