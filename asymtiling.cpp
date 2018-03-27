#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int tile[101];

int tiling(int n){
	if(n<1){
		return 1;
	}
	int &ret = tile[n];
	if(ret != -1){
		return ret;
	}

	return ret = (tiling(n-1)+tiling(n-2))%MOD;
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;cc++){
		int n,temp;
		scanf("%d",&n);

		memset(tile,-1,sizeof(tile));

		tile[0] = 0;
		tile[1] = 1;
		tile[2] = 2;

		if(n%2 == 1){
			temp = (-1*tiling(n/2) + tiling(n)+MOD) % MOD;
		}
		else{
			temp = tiling(n);
			temp = (temp- tiling(n/2)+MOD)%MOD;
			temp = (temp- tiling(n/2-1)+MOD)%MOD;
		}
		printf("%d\n",temp);
	}

	return 0;
}