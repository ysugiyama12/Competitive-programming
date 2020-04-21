#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
const ll maxn=1e6+100;
const ll mod=1e9+7;
//ll fact[maxn];
int main()
{
	int t,i,j,k,n;
	cin>>t;
	while(t--)
	{
 	cin>>n;
		int flag=0;
		int a[n],b[n],c[n],d[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			if(b[i]>a[i])
			{
				flag=1;
				
			}
			c[i]=a[i];
			d[i]=b[i];
		}
		if(flag==1)
			cout<<"NO"<<endl;
		else
		{
			flag=0;
			for(i=0;i<n-1;i++)
			{
				if(a[i]>a[i+1] || b[i]>b[i+1] || (a[i]==a[i+1] && b[i+1]>b[i]))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				
				sort(c,c+n);
				sort(d,d+n);
				for(i=0;i<n;i++)
				{
					if(a[i]!=c[i] || b[i]!=d[i])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
				
			else
				cout<<"NO"<<endl;
		}
	}
	
	
	
	
}
