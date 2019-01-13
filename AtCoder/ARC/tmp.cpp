#include<iostream>
#include<algorithm>
#include <math.h>
#include <cmath>
using namespace std;
#define ll long long
 
ll a[200050] = {};
ll A[200050] = {};
 
int main()
{
	ll n;
	ll ans = 0;
	cin >> n;
 
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
        a[i] -= i+1;
		A[i] = a[i];
	}
 
	sort(a, a + n);
	ll b;
	if (n % 2 != 0) {
		b = a[(n - 1) / 2];
	}
	else {
		b = (a[n / 2] + a[(n / 2) - 1]) / 2;
	}
 
	// b = b - (n - 1) / 2;
 
	// for (ll i = 0; i < n; i++)
	// {
	// 	ans += abs(A[i] - b);
	// 	b++;
	// }
    for (ll i = 0; i < n; i++){
        ans += abs(A[i] - b);
    }
 
	cout << ans << endl;
}