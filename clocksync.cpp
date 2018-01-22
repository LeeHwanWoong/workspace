#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <algorithm>
using namespace std;

const char button[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligen(vector<int> v){
	for(int i = 0;i<16;i++){
		if(v[i] != 12){
			return false;
		}
	}
	return true;
}

void rotate(vector<int> v,int btton){
	for(int i = 0;i<16;i++){
		if(button[btton][i] == 'x'){
			v[i-1] += 3;
			if(v[i-1] == 15){
				v[i-1] = 3;
			}
		}
	}
}

int solve(vector<int> v, int btton){
	int ret = 999;

	if(btton == 17){
		return areAligen(v) ? 0:999;
	}

	for(int i = 0;i<4;i++){
		ret = min(i+solve(v,btton+1),ret);
		rotate(v,btton);
	}
	return ret;
}

int main(){
	int c,temp;

	cin>>c;

	for(int qq = 0; qq< c; qq++){
		vector<int> v;
		// for(int i = 0;i<16;i++){
		// 	cin>>temp;
		// 	v.push_back(temp);
		// }
		v.push_back(12);
		v.push_back(6);
		v.push_back(6);
		v.push_back(6);
		v.push_back(6);
		v.push_back(6);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);
		v.push_back(12);

		temp = solve(v,0);

		if(temp>=999){
			cout<<-1;
		}
		else{
			cout<<temp;
		}
	}

=======
using namespace std;

int main(){
	int c;
	cin>>c;

	for(int qq = 0; qq< c; qq++){
		int test[16];
		for(int i = 0;i<16;i++){
			cin>>test[i];
		}
	}


>>>>>>> 30cf5af6db2c64d2efe0a05eb069524c7c4d8b6d
	return 0;
}