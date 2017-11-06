#include <iostream>
using namespace std;

int **route;

int main(){
	int N,M;
	string temp;
	cin>>N>>M;
	route = new int*[N];
	for(int i = 0;i<N;i++){
		route[i] = new int[M];
	}
	for(int i = 0;i<N;i++){
		cin>>temp;
		for(int j = 0;j<M;j++){
			route[i][j] = temp[j]-'0';
		}
	}

}