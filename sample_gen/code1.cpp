#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
typedef long long int ll;
 
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<int> p(n),c(n);
		for(int i=0;i<n;i++){
			cin >> p[i] >> c[i];
		}
		bool ok=1;
		for(int i=1;i<n;i++){
			if(p[i-1]>p[i]||c[i-1]>c[i])ok=0;
		}
		for(int i=0;i<n;i++){
			if(p[i]<c[i])ok=0;
		}
		for(int i=0;i<n;i++){
			p[i]=p[i]-c[i];
		}
		for(int i=1;i<n;i++){
			if(p[i]<p[i-1])ok=0;
		}
		if(ok){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}