#include <iostream>
using namespace std;

int nr[30][30];

int bino(int n, int r){
	int ret1,ret2;

	if(r == 0 || n == r){
		nr[n][r] = 1;
		return 1;
	}

	if(nr[n][r] != -1){
		return nr[n][r];
	}

	return nr[n][r] = nr[n-1][r-1]+nr[n-1][r];
}

int main(){
	int n,r,ret;

	memset(nr,-1,sizeof(nr));
	scanf("%d %d",&n,&r);
	ret = bino(n,r);
	printf("%d\n",ret);

	return 0;
}