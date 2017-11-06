#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	int *coin;
	int *total;

	cin>>n>>k;
	coin = new int[n];	//종류
	total = new int[k+1];	//1,2,3,4.......k

	for(int i = 1;i<k+1;i++){
		total[i] = -1;
	}

	for(int i = 0; i<n; i++){
		cin>>coin[i];
	}

	sort(coin,coin+n);

	for(int i = 0; i<n; i++){
		for(int j = coin[i];j<=k; j = j + coin[i]){
			total[j] = j / coin[i];
		}
	}

	for(int i = 1;i<=k;i++){
		if(total[i] == 1){
			continue;
		}
		vector<int> tmp;
		if(total[i] != -1){
			tmp.push_back(total[i]);
		}
		for(int j = i-1;j>0;j--){
			if(total[j] != -1 && total[i-j] != -1){
				tmp.push_back(total[j] + total[i-j]);
			}
		}
        if(!tmp.empty()){
    		sort(tmp.begin(),tmp.end());
            total[i] = tmp[0];
        }
	}

	cout<<total[k];
	return 0;
}