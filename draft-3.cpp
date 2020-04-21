#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0;i<n-1;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long count=0,j=0;
    for(int i=1;i<n;i++){
        count++;
        if(a[i]!=a[i+1]){
            cout << count << endl;
            j++;
            count=0;
        }
    }
    for(int i=0;i<n-j;i++) cout << 0 << endl;
}
