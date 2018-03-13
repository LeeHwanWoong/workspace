#include <iostream>
#include <vector>
using namespace std;

int difficulty(std::vector<int> v){
	for(int i = 1;i<v.size();i++){
		if(v[i] != v[0]){
			break;
		}
		cout<<"BBB";
		if(i == v.size()-1){
			return 1;
			cout<<"AAA";
		}
	}
}

int main(){
	int c,tt;
	scanf("%d",&c);

	for(int cc = 0;cc<c;cc++){
		scanf("%d",&tt);
		vector<int> v;
		v.push_back(tt%10);
		int a = 10,b = 100;
		while(true){
			int temp = tt%b;
			if(temp/a == 0){
				break;
			}
			v.push_back(temp/a);
			b = b*10;
			a = a*10;
		}
		difficulty(v);
	}
}