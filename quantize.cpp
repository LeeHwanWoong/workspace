#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
int n,s;
int caches[100][11];

int minError(int a, int b){
	int temp = 0,ret = 0;
	double temp2;
	for(int i = a;i<=b;i++){
		temp += num[i];
	}
	temp2 = temp/(b-a+1);
	temp = int(temp2+0.5);

	for(int i = a;i<=b;i++){
		ret += (num[i]-temp)*(num[i]-temp);
	}

	return ret;
}

int quantize(int from, int parts){
	if(from == n){
		return 0;
	}
	if(parts == 0){
		return 987654321;
	}
	int &ret = caches[from][parts];
	if(ret != -1){
		return ret;
	}

	ret = 987654321;
	for(int size = 1;size<=n-from;size++){
		ret = min(ret, minError(from,from+size-1)+quantize(from+size,parts-1));
	}
	return ret;
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;cc++){
		scanf("%d%d",&n,&s);
		int temp,dif = 1;
		for(int i = 0;i<n;i++){
			scanf("%d",&temp);
			num.push_back(temp);
		}
		sort(num.begin(),num.end());
		temp = num[0];
		for(int i = 1;i<n;i++){
			if(num[i] != temp){
				dif++;
				temp = num[i];
			}
		}
		for(int i = 0;i<100;i++){
			for(int j = 0;j<11;j++){
				caches[i][j] = -1;
			}
		}
		if(dif<=s){
			printf("0\n");
		}
		else{
			temp = quantize(0,s);
			printf("%d\n",temp);
		}
		num.clear();
	}
	return 0;
}