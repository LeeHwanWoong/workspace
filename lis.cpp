#include <iostream>
#include <cstring>

using namespace std;

int n,caches[101],num[100];

int lis2(int start){
	int& ret = caches[start];
	if(ret != -1){
		return ret;
	}
	ret = 1;
	for(int i = start+1;i<n;i++){
		if(num[start]<num[i]){
			ret = max(ret,lis2(i)+1);
		}
	}
	return ret;
}

int main(){
	int C;

	cin>>C;

	for(int cc = 0;cc<C;cc++){
		cin>>n;
		int ret;
		memset(caches,-1,sizeof(caches));
		for(int i = 0;i<n;i++){
			cin>>num[i];
		}
		ret = lis2(0);
		cout<<ret<<endl;
	}
	return 0;
}