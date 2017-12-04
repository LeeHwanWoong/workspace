#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

void display(vector<vector<int> >& board){
	for(int i = 0;i<board.size();i++){
		for(int j = 0;j<board[0].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool set(vector<vector<int> >& board, int y, int x, int type, int delta){
	bool ok = true;
	for(int i = 0;i<3;++i){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()){
			ok = false;
		}
		else if((board[ny][nx] += delta) > 1){
			ok = false;
		}
	}
	return ok;
}

int cover(vector<vector<int> >& board){
	int y = -1, x = -1;
	for(int i = 0;i<board.size();++i){
		for(int j = 0;j<board[0].size();++j){
			if(board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1){
			break;
		}
	}

	if(y == -1){
		return 1;
	}

	int ret = 0;
	for(int type = 0;type<4;++type){
		if(set(board,y,x,type,1)){
			display(board);
			ret += cover(board);
		}
		cout<<endl;
		set(board,y,x,type,-1);
	}
	return ret;
}

int main(){
	int c;
	cin>>c;
	for(int t = 0;t<c;t++){
		int counting = 0;
		int x, y;
		cin>>x>>y;
		vector< vector<int> > board;

		for(int i = 0;i<x;i++){
			vector<int> temp;
			for(int j = 0;j<y;j++){
				char k;
				cin>>k;
				if(k == '.'){
					temp.push_back(0);
					counting+=1;
				}
				else{
					temp.push_back(1);
				}
			}
			board.push_back(temp);
		}

		if(counting%3 != 0){
			cout<<"0"<<endl;
		}
		else{
			cout<<cover(board)<<endl;
		}
	}

	return 0;
}