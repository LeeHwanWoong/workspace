#include <iostream>
using namespace std;

int position(string s, int idx){    //idx = from 'x'
    int count = 4;

    for(int i = idx+1;i<s.size();i++){
        if(s[i] != 'x'){
            count--;
            if(count == 0){
                return i;
            }
        }
        else{
            count += 3;
        }
    }
    return 0;
}

string reverse(string s){
    string temp[4],ret;

    for(int i = 1,ti = 0;s[i] != '\0';i++){
        if(s[i] == 'x'){
            int ri = position(s,i);
            temp[ti] = reverse(s.substr(i,ri));
            i = ri;
            ti++;
        }
        else{
            temp[ti] = s[i];
            ti++;
        }
        if(ti == 4){
            return 'x'+temp[2]+temp[3]+temp[0]+temp[1];
        }
    }
    return "";
}

int main(){
    int t;
    string s;

    cin>>t;

    for(int cc = 0;cc<t;cc++){
        cin>>s;
        if(s == "b" || s == "w"){
            cout<<s+'\n';
            continue;
        }
        cout<<reverse(s)+"\n";
    }
}
