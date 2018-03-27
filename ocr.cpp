#include <iostream>
using namespace std;

string word[501],test[501];
int b[501],T[501][501],M[501][501];

int main(){
	int m,q,n;

	for(int i = 1;i<=m;++i){
		cin>>word[i];
	}
	for(int i = 1;i<=m;++i){
		cin>>b[i];
	}
	for(int i = 1;i<=m;++i){
		for(int j = 1;j<=m;++j){
			cin>>T[i][j];
		}
	}
	for(int i = 1;i<=m;++i){
		for(int j = 1;j<=m;++j){
			cin>>M[i][j];
		}
	}
	for(int i = 0;i<q;i++){
		scanf("%d",&n);
		for(int j = 0;j<n;j++){
			cin>>test[j];
		}
	}

	return 0;
}