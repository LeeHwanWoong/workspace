#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,lis,before = -1;
double k;
int num[501];
int caches[501];
int cachescnt[501];

bool cmp(int a,int b) {return num[a]<num[b];}

//아래 두개를 바탕으로 답안 재구성
void reconstruct(int start, int klis){
	if(klis == 0) return;

	vector<int> v;
	for(int i = start;i<=n;i++){
		if(caches[i] == klis){
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end(),cmp);

	for(int i = 0;i<v.size();++i){
		if(cachescnt[v[i]]>=k){
			if(before<num[v[i]]){
				printf("%d ",num[v[i]]);
				before = num[v[i]];
				reconstruct(v[i]+1,klis-1);
				return;
			}
		}
		else{
			k -= cachescnt[v[i]];
		}
	}
}
//최적화 문제
int klis(int start){
	int &ret = caches[start];

	if(ret != -1) return ret;

	ret = 1;

	for(int i = start+1;i<=n;++i){
		if(num[start] < num[i]){
			ret = max(ret,1+klis(i));
		}
	}

	return ret;
}
//최적해를 세는 문제
int count(int start){
	int &ret = cachescnt[start];

	if(klis(start) == 1) return ret = 1;

	if(ret != -1) return ret;

	ret = 0;
	for(int i = start+1;i<=n;i++){
		if(num[start]<num[i] && klis(start) == klis(i)+1){
			ret = min(2000000001,ret+count(i));
		}
	}

	return ret;
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;++cc){
		before = -1;
		memset(caches,-1,sizeof(caches));
		memset(cachescnt,-1,sizeof(cachescnt));
		memset(num,-1,sizeof(num));
		scanf("%d %d",&n,&k);
		caches[n] = 1;

		for(int i = 1;i<=n;i++){
			scanf("%d",&num[i]);
		}

		lis = 0;
		for(int i =1;i<n;i++){
			lis = max(lis,klis(i));
		}

		for(int i = 1;i<=n;i++){
			count(i);
		}
		printf("%d\n",lis);
		reconstruct(1,lis);
		printf("\n");
	}
	return 0;
}