#include <iostream>
using namespace std;

int ccw(int x1,int y1,int x2,int y2,int x3,int y3){
	return ((x2-x1)*(y3-y2))-((y2-y1)*(x3-x2));
}

bool connect(int x1,int y1,int x2,int y2,int x3,int y3){
	if((y2-y1)*(y3-y1) == (x3-x1)*(x2-x1)){

	}
	else{
		return false;
	}
}

int main(){
	int xs,ys,xe,ye,xl,yt,xr,yb;
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		cin>>xs>>ys>>xe>>ye>>xl>>yt>>xr>>yb;

		if((ccw(xs,ys,xe,ye,xl,yt)*ccw(xs,ys,xe,ye,xr,yb))<0){
			cout<<'T'<<endl;
		}
		else if()
	}
}