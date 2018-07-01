/*
prefix

1. momorizing table

2. sequence table

3. times memo

*/

#include<iostream>
#include<cmath>

using namespace std;

int fakt(int n) {

int fact=1;
int i;

for (i=1; i<=n; i++)
fact*=i;

return fact;
}

cin.tie(nullptr);
cout.untie();


//input
vector<string> input = {};
string i = "";
int len[2];
cin >> len[0];
cin >> len[1]
while(len[0]>0){
	cin>> i;
	input.push_back(i);
	len[0]--;

}

//store factor memo
long length = input.size();
long[log(2,length)] arr ={};
for(int i = 1; i < length;i+= i){
	arr[i] *= arr[i/2] ;
	for(int b = i/2; b < i; b+=1){
		arr[i]*= b*b+1;
	} 
}

//sequence

input.sort();

long[] matArr = long[]();
int curIndex = 0;
int curMatch = 0;
while(curIndex != stringToMatch.length){
for(int i = 0; i<input.length; i++ ){
	int a = input[i].length;
	if(curIndex+a+1 < input.length){
		if(match(input[i], stringToMatch.substring(curIndex, curIndex+ a+1))){
			matArr[curMatch] = i+1;
		}
	}
	curMatch++;
}
}

long long result = 1;
for(int i = 0; i < matArr.length; i++){
	result *= fakt(input.length-i)/ fakt(matArr[i]);

}