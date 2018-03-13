#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string test,wildcard;
int cash[101][101];

// string replaceall(string &str, string from, string to){
// 	int start_pos = 0;
// 	while((start_pos = str.find(from,start_pos)) != string::npos){
// 		str.replace(start_pos,from.length(),to);
// 		start_pos += to.length();
// 	}
// 	return str;
// }

// bool isMatch(string wildcard, string test){
// 	int pos = 0;

// 	while(pos < wildcard.size() && pos < test.size() && (wildcard[pos] == '?' || wildcard[pos] == test[pos])){
// 		pos++;
// 	}

// 	if(pos == wildcard.size()){
// 		return pos == test.size();
// 	}

// 	if(wildcard[pos] == '*'){
// 		for(int i = 0;i+pos <= test.size();i++){
// 			if(isMatch(wildcard.substr(pos+1),test.substr(pos+skip))){
// 				return true;
// 			}
// 		}
// 	}

// 	return false;
// }

int isMatch(int w, int t){
	cout<<w<<" "<<t<<endl;
	int& ret = cash[w][t];
	if(ret != -1){
		return ret;
	}
	while(w<wildcard.size() && t<test.size() && (wildcard[w] == '?' || wildcard[w] == test[w])){
		w++;
		t++;
	}
	if(w == wildcard.size()){
		return ret = (t == test.size());
	}
	if(wildcard[w] == '*'){
		for(int i = 0;i+t<test.size();i++){
			if(isMatch(w+1,t+i) == 1){
				return ret = 1;
			}
		}
		return ret = 0;
	}
	return ret = 0;
}


int main(){
	int c,n;
	char temp[100];
	scanf("%d",&c);

	for(int cc = 0;cc<c;cc++){
		scanf("%s",temp);
		wildcard = temp;
		scanf("%d",&n);
		vector<string> ret;
		for(int ii = 0;ii<n;ii++){
			memset(cash,-1,101*101);
			scanf("%s",temp);
			test = temp;
			if(isMatch(0,0) == 1){
				ret.push_back(test);
			}
		}
		sort(ret.begin(),ret.end());
		for(int i = 0;i<ret.size();i++){
			printf("%s\n",ret[i].c_str());
		}
	}

	return 0;
}