#include <iostream>
#include <vector>
using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k){
	if(a.size()<b.size() + k){
		a.resize(b.size()+k);
	}
	for(int i = 0;i<b.size();i++){
		a[i+k] += b[i];
	}
}

void nomalize(vector<int>& a){
	// a.push_back(0);
	// for(int i = 0;i<a.size();i++){
	// 	if(a[i] > 10){
	// 		a[i+1] += a[i]/10;
	// 		a[i] = a[i]%10;
	// 	}
	// }
	// while(a.size()>1 && a.back() == 0){
	// 	a.pop_back();
	// }
}

void subFrom(vector<int>& a, const vector<int>& b){
	for(int i = 0;i<b.size();i++){
		a[i] -= b[i];
	}
	nomalize(a);
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
	vector<int> ret(a.size() + b.size() + 1,0);

	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			ret[i+j] += a[i] * b[j];
		}
	}

	nomalize(ret);

	return ret;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
	if(a.size()<b.size()){
		return karatsuba(b,a);
	}
	if(a.size() == 0 || b.size() == 0){
		return vector<int>();
	}
	if(a.size()<=50){
		return multiply(a,b);
	}
	int half = a.size()/2;
	vector<int> a0(a.begin(),a.begin()+half),a1(a.begin()+half,a.end()),b0(b.begin(),b.begin()+min<int>(b.size(),half)),b1(b.begin()+min<int>(b.size(),half),b.end()),ret,a1b1,a0b0,a1b0;

	a1b1 = karatsuba(a1,b1);
	a0b0 = karatsuba(a0,b0);
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	a1b0 = karatsuba(a0,b0);
	subFrom(a1b0,a1b1);
	subFrom(a1b0,a0b0);
	addTo(ret,a1b1,half+half);
	addTo(ret,a0b0,0);
	addTo(ret,a1b0,half);

	return ret;
}

int hug(string members, string fans){
	int n = members.size(), m = fans.size(), ret;
	vector<int> A(n),B(m),C;
	for(int i = 0;i<n;i++){
		A[i] = (members[i] == 'M');
	}
	for(int i = 0;i<m;i++){
		B[m-i-1] = (fans[i] == 'M');
	}
	C = karatsuba(A,B);
	ret = 0;
	for(int i = n-1;i<m;i++){
		if(C[i] == 0){
			ret++;
		}
	}
	return ret;
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