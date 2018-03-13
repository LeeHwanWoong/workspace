#include <iostream>
using namespace std;

int tri[101][101],n,retri[101][101];

int trianglepath(int i,int j){
	if(j<1 || i<1 || i<j){
		return 0;
	}

	int& ret = retri[i][j];

	if(ret != -1){
		return ret;
	}
	return ret = tri[i][j] + max(trianglepath(i-1,j-1),trianglepath(i-1,j));
}

int main(){
	int t;

	scanf("%d",&t);

	for(int cc = 0;cc<t;cc++){
		for(int i = 0;i<101;i++){
			memset(tri[i],-1,101*sizeof(int));
			memset(retri[i],-1,101*sizeof(int));
		}

		scanf("%d",&n);

		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=i;j++){
				scanf("%d",&tri[i][j]);
			}
		}
		int *ret,print = 0;
		ret = new int[n];
		retri[1][1] = tri[1][1];
		for(int i = 0;i<n;i++){
			ret[i] = trianglepath(n,i+1);
		}

		for(int i = 0;i<n;i++){
			if(print<ret[i]){
				print = ret[i];
			}
		}
		printf("%d\n",print);
	}
	return 0;
}