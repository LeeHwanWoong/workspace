#include <iostream>
#include <cstring>
using namespace std;

int skip,bino[201][201];

void calcBino(){
	memset(bino,-1,sizeof(bino));

	for(int i = 0;i<=200;i++){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1;j<i;j++){
			bino[i][j] = min(1000000100,bino[i-1][j-1]+bino[i-1][j]);
		}
	}
}


string generate(int n,int m,int skip){

	if(n == 0) return string(m,'o');
	if(skip < bino[n+m-1][n-1]) return '-'+generate(n-1,m,skip);
	return "o"+generate(n,m-1,skip-bino[n+m-1][n-1]);
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;++cc){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);

		skip = k-1;
		calcBino();
		cout<<generate(n,m,skip)<<endl;
	}

	return 0;
}