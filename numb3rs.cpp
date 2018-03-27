#include <iostream>
#include <cstring>
using namespace std;

int **map,p,n,numtown2[50];
double caches[101][50];

int numtown(int q){
	int &ret = numtown2[q];

	if(ret != -1){
		return ret;
	}

	ret = 0;
	for(int i = 0;i<n;i++){
		if(map[i][q] == 1){
			ret++;
		}
	}

	return ret;
}

double ptown(int d,int q){
	double &ret = caches[d][q];
	if(ret != -1){

		return ret;
	}

	if(d == 1){
		if(map[p][q] == 1 && numtown(q) != 0){
			return ret = (double)1/(double)numtown(p);
			//cout<<d<<" "<<q<<" "<<ret<<endl;
			//return ret;
		}
		else{
			return ret = 0;
		}
	}

	ret = 0;

	for(int i = 0;i<n;i++){
		if(map[i][q] == 1 && numtown(i) != 0){
			ret += (double)ptown(d-1,i) / (double)numtown(i);
			//cout<<d-1<<" "<<i<<" "<<numtown(i)<<" "<<(double)1/(double)numtown(i)<<endl;
		}
	}

	return ret;
}

int main(){
	int C;
	scanf("%d",&C);

	for(int cc = 0;cc<C;cc++){
		int d,t,*q;
		double temp;
		scanf("%d %d %d",&n,&d,&p);

		map = new int*[n];
		for(int i = 0;i<n;i++){
			map[i] = new int[n];
		}

		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				scanf("%d",&map[i][j]);
			}
		}

		scanf("%d",&t);
		q = new int[t];
		for(int i = 0;i<t;i++){
			scanf("%d",&q[i]);
		}

		for(int i = 0;i<101;i++){
			for(int j = 0;j<50;j++){
				caches[i][j] = -1;
			}
		}
		memset(numtown2,-1,sizeof(numtown2));

		printf("\n");
		for(int i = 0;i<t;i++){
			temp = ptown(d,q[i]);
			printf("%.8f ",temp);
		}
	}
	printf("\n");
	return 0;
}