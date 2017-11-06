#include <iostream>
using namespace std;

int main(){
	int c,n,m;

	cin>>c;
	for(int j = 0;j<c;j++){
		cin>>n>>m;

		bool areFriend[n][n];

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				areFriend[i][j] = false;
			}
		}

		for(int i = 0;i<m;i++){
			int t1,t2;
			cin>>t1>>t2;
			areFriend[t1][t2] = true;
			areFriend[t2][t1] = true;
		}
	}

	return 0;
}
