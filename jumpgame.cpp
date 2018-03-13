#include <iostream>
using namespace std;

bool isjump[100][100];

bool jump(int **test,int i,int j){
	if(i == 0 && j == 0){
		return isjump[0][0] = true;
	}

	if(isjump[i][j]){
		return true;
	}

	for(int n = 0;n<i;n++){
		if(n+test[n][j] == i){
			if(jump(test,n,j)){
				return isjump[i][j] = true;
			}
		}
	}
	for(int n = 0;n<j;n++){
		if(n+test[i][n] == j){
			if(jump(test,i,n)){
				return isjump[i][j] = true;
			}
		}
	}

	return false;
}

int main(){
	int c,n;

	scanf("%d",&c);
	for(int cc = 0;cc<c;cc++){
		scanf("%d",&n);
		int **test = new int*[n];
		for(int i = 0;i<n;i++){
			test[i] = new int[n];
			for(int j = 0;j<n;j++){
				scanf("%d",&test[i][j]);
				isjump[i][j] = false;
			}
		}

		if(jump(test,n-1,n-1)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}