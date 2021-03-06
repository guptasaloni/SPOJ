#include <iostream>
#include <stdio.h>
#include <tr1/unordered_map>
using namespace std;
long long getValue(long long n,tr1::unordered_map<long long,long long>*Cache);
int main()
{	
	int n=0;
	tr1::unordered_map<long long,long long>Cache;
	(Cache).insert(tr1::unordered_map<long long,long long>::value_type(0,0));
	while(cin>>n)
	{
		printf("%llu\n",getValue(n,&Cache));
	}
	return 0;
}
long long getValue(long long n,tr1::unordered_map<long long,long long>*Cache)
{
	long long retVal;
	tr1::unordered_map<long long,long long>::iterator itr = (*Cache).find(n);
	if(itr!=(*Cache).end())
		return  (itr)->second;
	else
	{
		long long a,b,c;
		a = getValue(n/2,Cache);
		b = getValue(n/3,Cache);
		c = getValue(n/4,Cache);
		retVal = a+b+c > n ? a+b+c : n;
	}
	(*Cache).insert(tr1::unordered_map<long long,long long>::value_type(n,retVal));
	return retVal;
}
