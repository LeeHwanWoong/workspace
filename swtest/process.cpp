#include <iostream>
using namespace std;

int **process;

int maxlen(){

}

int main(){
	int t;

	scanf("%d",&t);

	for(int cc = 0;cc<t;cc++){
		int n;
		scanf("%d",&n);
		process = new int*[n];
		for(int i = 0;i<n;i++){
			process[i] = new int[n];
		}
		for(int i =0;i<n;i++){
			for(int j = 0;j<n;j++){
				scanf("%d",&process[i][j]);
			}
		}
	}
}