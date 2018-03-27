#include <iostream>
#include <vector>
using namespace std;

int caches[10002];
vector<int> v;
int N;
const int INF = 987654321;

int difficulty(int a,int b){
	for(int i = a+1;i<b+1;i++){
		if(v[i] != v[i-1]){
			break;
		}
		if(i ==b){
			return 1;
		}
	}

	int v1 = v[a],v2 = v[1+a];
	for(int i = a+2;i<b+1;i++){
		if(i%2 == 0){
			if(v[i] != v1){
				break;
			}
		}
		else{
			if(v[i] != v2){
				break;
			}
		}
		if(i == b){
			return 4;
		}
	}

	int gap = v[a+1]-v[a];
	for(int i = a+2;i<b+1;i++){
		if(v[i]-v[i-1] != gap){
			break;
		}
		if(i == b){
			if(gap == 1 || gap == -1){
				return 2;
			}
			else{
				return 5;
			}
		}
	}

	return 10;
}

int sumpi(int a){
	int &ret = caches[a];

	if(a == N){
		return 0;
	}

	if(ret != -1){
		return ret;
	}

	ret = INF;

	for(int i = 3;i<=5;i++){
		if(a+i<=N-1){
			ret = min(ret, difficulty(a,a+i-1)+sumpi(a+i));
		}
	}

	return ret;
}

int main(){
	int c,tt;
	scanf("%d",&c);

	for(int cc = 0;cc<c;cc++){
		scanf("%d",&tt);
		vector<int> par;

		par.push_back(tt%10);
		int a = 10,b = 100;
		while(true){
			int temp = tt%b;
			if(temp/a == 0){
				break;
			}
			par.push_back(temp/a);
			b = b*10;
			a = a*10;
		}
		for(int i = par.size()-1;i>=0;i--){
			v.push_back(par[i]);
		}
		for(int i = 0;i<10002;i++){
			caches[i] = -1;
		}
		N = v.size();

		cout<<sumpi(0)<<endl;
	}

	return 0;
}