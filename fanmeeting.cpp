#include <iostream>
using namespace std;

bool ishug(string singer,string fan){
	for(int i = 0;i<singer.size();i++){
		if(singer[i] == 'M' && fan[i] == 'M'){
			return false;
		}
	}
	return true;
}

int hug(string singer, string fan){
	int s = 0,e = singer.size(),count = 0;
	for(;e<=fan.size();s++,e++){
		if(ishug(singer,fan.substr(s,e))){
			count++;
		}
	}
	return count;
}

int main(){
	int c;
	cin>>c;

	for(int cc = 0;cc<c;cc++){
		string singer,fan;
		cin>>singer;
		cin>>fan;
		cout<<hug(singer,fan)<<endl;
	}
	return 0;
}