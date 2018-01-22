#include <iostream>
using namespace std;

bool **areFriend;
bool *taken;
int n;

int countPairings(){
	int firstfree = -1;
	for(int i = 0;i<n;i++){
		if(!taken[i]){
			firstfree = i;
			break;
		}
	}

	if(firstfree == -1){
		return 1;
	}
	int ret = 0;

	for(int i = firstfree+1;i<n;i++){
		if(!taken[i] && areFriend[i][firstfree]){
			taken[i] = true;
			taken[firstfree] = true;
			ret += countPairings();
			taken[i] = false;
			taken[firstfree] = false;
		}
	}
	return ret;
}

int main(){
	int c,m;

	cin>>c;
	for(int t = 0;t<c;t++){
		cin>>n>>m;

		areFriend = new bool*[n];
		taken = new bool[n];
		for(int i = 0;i<n;i++){
			areFriend[i] = new bool[n];
		}

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
		cout<<countPairings()<<endl;
	}

	return 0;
}
