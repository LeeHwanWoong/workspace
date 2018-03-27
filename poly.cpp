#include <iostream>
#include <cstring>
using namespace std;

int caches[101][101];

int poly(int n,int t){
	if(n == t){
		return 1;
	}

	int &ret = caches[n][t];

	if(ret != -1){
		return ret;
	}

	ret = 0;

	for(int i = 1;i<=n-t;i++){
		int add = t-1+i;
		add *= poly(n-t,i);
		add %= 10000000;
		ret += add;
		ret %= 10000000;
	}

	return ret;
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;cc++){
		int n,temp = 0;
		scanf("%d",&n);
		memset(caches,-1,sizeof(caches));
		for(int i = 0;i<n;i++){
			(temp += poly(n,i+1))%=10000000;
		}
		printf("%d\n",temp);
	}
	return 0;
}