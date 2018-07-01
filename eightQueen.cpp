#include<iostream>

using namespace std;
int main(void){
	cin.tie(nullptr);
	cout.sync_with_stdio(false);


	bool isValid = true;
	bool horzLine[8];
	bool vertLine[8];
	bool diagPos[17];
	bool diagNeg[17];
	string inputLine = "";

	int outCount = 1;
	while(getline(cin, inputLine) && isValid ){
		int count = 1;
		for(char i : inputLine){
			if( i == '*'){
				
				if(horzLine[outCount-1] || vertLine[count-1] || diagPos[count+outCount-1] || diagNeg[outCount - count + 8 -1]){
					isValid = false;
				}
				horzLine[outCount-1] = vertLine[count-1] = diagPos[count+outCount-1] = diagNeg[outCount - count + 8 -1] = true;

				
			}
			count++;
		}
		outCount ++;
	}
	cout << (isValid)? "valid":"invalid";
	return 0;
}