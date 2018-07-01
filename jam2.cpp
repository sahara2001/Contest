

#include<iostream>


using namespace std;


int main(){
	
	unsigned int cases;
	cin >> cases;

	for(int a = 0; a< cases; a++ ){

	unsigned int len;
	cin >> len;
	unsigned int sheld[len] = {0};
	char odd[len/2+1] = {'0'};
	char even[len/2+1] = {'0'}
	if(len % 2 == 0){

		for(int i = 0; i < len/2; i++){

			cin >> odd[i];
			cin >> even[i];
		}

	}else{
		for(int i = 0; i < (len-1)/2; i++){

			cin >> odd[i];
			cin >> even[i];
		}
		cin >> odd[len/2];
	}

	map<char, queue<int>> map1 = new map<>();
	map<char, queue<int>> map2 = new map<>();
	
	//put into map
	for(int i = 0; i < odd.size(); i++){
		if(!map1.contains((char)i)){
			map1[(char)i] =  new queue<int>();
		}
		map1[(char)i].enqueue(odd[i]*2);
	}

	for(int i = 0; i < even.size(); i++){
		if(!map2.contains((char)i)){
			map2[(char)i] =  new queue<int>();
		}
		map2[(char)i].enqueue(even[i]*2+1);
	}



	bool status = true;

	sort(begin(odd),end(odd));
	sort(begin(even),end(even));

	int coordinate = -1;
	for(int b = 0; b < len/2-1 && coordinate==-1; b++ ){
		if(odd[b] > even[b]){
			status = false;
			coordinate = map1[odd[b]].dequeue();
			break;
		}
		if(even[b] > odd[b+1]){
			status = false;
			coordinate = map2[even[b]].dequeue();
			break;
		}
		map1[b].dequeue();
		map2[b].dequeue();





	}
	if(status && odd[len/2] > even[len/2]){
			status = false;
			coordinate = map1[odd[len/2]].dequeue();
			
		}

	if(status && odd[len/2+1] < even[len/2]){
			status = false;
			coordinate = map2[odd[len/2]].dequeue();
			
	}


		
	
	if(!status){
		  cout << "Case #" << a+1 <<": "<<coordinate<<endl;
		}else{
		  cout << "Case #" << a+1 <<": "<<"OK"<<endl;
		}

	delete(map1);
	delete(map2);

}
  return 0;
}