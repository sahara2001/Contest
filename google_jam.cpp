

#include<iostream>


using namespace std;

int dam(string tmp){
    unsigned int a = 0;
    unsigned int two = 1;
    for(int c = 0; c < tmp.size(); c++){
			if(tmp[c] == 'C'){two *= 2;}
			else{a += two ;}
		}
	return a;
}
string hack(string tmp){
    bool swapped = false;
    if(tmp.size() > 1){
        unsigned int a = tmp.size();
        for(int i = 0; i < a && a >= i + 2 ; i++){
        if(tmp[a - i - 1] == 'S' && tmp[a - 2 - i] == 'C'){
            swap(tmp[a-i-1], tmp[a-i-2]);
            swapped = true;
            break;
        }
    }
    }
    return (swapped)?tmp:"";
}
int main(){
	
	unsigned int len;
	cin >> len;
	unsigned int sheld[len] = {0};
	string damage[len] = {""};
	for(int i = 0; i < len; i++){

		cin >> sheld[i];
		cin >> damage[i];
	}	

	for(int b = 0; b < len; b++ ){
		unsigned int a = sheld[b];
		
		string tmp = damage[b];
		bool status = true;
		unsigned int num = 0;
		if(tmp.size()>1){
		while(dam(tmp) > sheld[b] && status ){
		    tmp = hack(tmp);
		    if(tmp.empty()){
		        status = false;
		        break;
		    }
		    num++;
		}
		}
		if(status){
		  cout << "Case #" << b+1 <<": "<<num<<endl;
		}else{
		  cout << "Case #" << b+1 <<": "<<"IMPOSSIBLE"<<endl;
		}
		
	}
  return 0;
}