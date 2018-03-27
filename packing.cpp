#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string name[101];
int vol[101],hope[101],n,w,caches[1001][101],choice[101];

int take(int cvol,int start){
	int &ret = caches[cvol][start];

	if(cvol > w || start>=n) return 0;
	if(ret != -1) return ret;

	ret = take(cvol,start+1);

	if(cvol>=vol[start]){
		ret = max(ret,take(cvol-vol[start],start+1)+hope[start]);
	}

	return ret;
}

void reconstruct(int cap,int item,vector<string>& picked){
	if(item == n) return;

	if(take(cap,item) == take(cap,item+1)){
		reconstruct(cap,item+1,picked);
	}
	else{
		picked.push_back(name[item]);
		reconstruct(cap-vol[item],item+1,picked);
	}
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;++cc){
		scanf("%d %d",&n,&w);
		memset(caches,-1,sizeof(caches));
		memset(vol,-1,sizeof(vol));
		memset(hope,-1,sizeof(hope));
		memset(choice,-1,sizeof(choice));
		for(int i = 1;i<=n;i++){
			cin>>name[i]>>vol[i]>>hope[i];
		}
		vector<string> picked;
		reconstruct(w,1,picked);
		cout<<take(w,1)<<" "<<picked.size()<<endl;
		for(int i = 0;i<picked.size();++i){
			cout<<picked[i]<<endl;
		}
	}

	return 0;
}