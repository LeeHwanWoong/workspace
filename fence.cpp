#include <iostream>
#include <algorithm>
using namespace std;

// int maxsize(int *number,int num){
// 	int *ret = new int[num];

// 	for(int i = 0;i<num;i++){
// 		int min = 0;
// 		if(number[i] == 1){
// 			ret[i] = num;
// 			continue;
// 		}
// 		for(int j = i+1;j<num;j++){
// 			if(number[j]>=number[i]){
// 				min++;
// 			}
// 			else{
// 				j = num+1;
// 			}
// 		}
// 		for(int j = i-1;j>=0;j--){
// 			if(number[j]>=number[i]){
// 				min++;
// 			}
// 			else{
// 				j = -1;
// 			}
// 		}
// 		if(min == 0){
// 			ret[i] = max(number[i],num);
// 		}
// 		else{
// 			ret[i] = max(number[i]*(min+1),num);
// 		}
// 	}
// 	int maxnum = 0;

// 	for(int i = 0;i<num;i++){
// 		if(ret[i]>maxnum){
// 			maxnum = ret[i];
// 		}
// 	}

// 	return maxnum;
// }

int maxsize(int *number,int left, int right){
	if(left == right){
		return number[right];
	}
	int mid = (left+right)/2,lvalue,mvalue = 0,rvalue;

	lvalue = maxsize(number,left,mid);
	rvalue = maxsize(number,mid+1,right);

	int ml = mid,mr = mid+1,height = min(number[ml],number[mr]);
	mvalue = height*2;

	while(left<ml || mr<right){
		if(mr<right && (left == ml || number[ml-1]<number[mr+1])){
			mr++;
			height = min(height,number[mr]);
		}
		else{
			ml--;
			height = min(height,number[ml]);
		}
		mvalue = max(mvalue,height*(mr-ml+1));
	}

	return max(lvalue,max(rvalue,mvalue));
}

int main(){
	int t;

	scanf("%d",&t);

	for(int cc = 0;cc<t;cc++){
		int num,rett;
		scanf("%d",&num);
		int *number = new int[num];

		for(int i = 0;i<num;i++){
			scanf("%d",&number[i]);
		}
		rett = maxsize(number,0,num-1);
		printf("%d\n",rett);
	}
	return 0;
}