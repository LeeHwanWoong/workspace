#include <iostream>
#include <cstring>
using namespace std;

int caches[100][100],*numn,*numm,n,m;

int jlis(int i,int j){
	int& ret = caches[i][j];

	if(ret != -1){
		return ret;
	}
	ret = 2;
	int mx = max(numn[i],numm[j]);

	for(int nextA = i+1;nextA<n;nextA++){
		if(mx<numn[nextA]){
			ret = max(ret,jlis(nextA,j)+1);
		}
	}
	for(int nextB = j+1;nextB<m;nextB++){
		if(mx<numm[nextB]){
			ret = max(ret,jlis(i,nextB)+1);
		}
	}
	return ret;
}

int main(){
	int c;

	scanf("%d",&c);

	for(int cc = 0;cc<c;cc++){
		memset(caches,-1,sizeof(caches));
		scanf("%d %d",&n,&m);
		numn = new int[n];
		numm = new int[m];
		for(int i = 0;i<n;i++){
			scanf("%d",&numn[i]);
		}
		for(int i = 0;i<m;i++){
			scanf("%d",&numm[i]);
		}
		int ret = 2;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				ret = max(ret,jlis(i,j));
			}
		}

		printf("%d\n",ret);
	}
	return 0;
}