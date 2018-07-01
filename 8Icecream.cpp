#include<iostream>
#include<stdlib.h>

using namespace std;
bool hasMinDist(int* xVal, int* yVal, int x){
    for(int a = 0; a < x; a++){
        
            if(abs(xVal[x]-xVal[a] + yVal[x] - yVal[a]) < 4){
                return false;
            }
        
    }
    return true;
}


int main(void){
 
 


    bool isValid = true;
    bool horzLine[8] = {0};
    bool vertLine[8] = {0};

    int xVal[8] ={-1};
    int yVal[8] ={-1};
    int queenNum = 0;
    int lastQueen[8] = {0};

int lastX[8] = {-1};
int lastY[8] = {-1};
    

    for(int i = 0; i< 8; i++){
        
        int tempQueen = 0;
        for(int j = lastX[i]+1; j < 8 ; j++){


                
                lastX[i] = i;
                lastY[i] = j;
                
                if(horzLine[i] || vertLine[j] || !hasMinDist(xVal,  yVal, i)){
                    tempQueen = 0;
                    continue;
                }
                horzLine[i] = vertLine[j]= true;
                xVal[i] = i;
                yVal[i] = j;
                tempQueen = 1;
                
                break;

                
                
            
            
            
        }
      
      if(i == 0){
        lastQueen[i] = lastQueen[i-1] + tempQueen;
      } 
      else{
        lastQueen[i] = lastQueen[i];
      }
        
    

    queenNum = lastQueen[i]+tempQueen;

    if( queenNum >= 4){
        for(int i = 0; i < 4 ; i++)
            cout << "x" << xVal[i]<< " y"<<yVal[i] ;
    }
    
    if(i == 7 && lastY[7] == 7){
      for(int b = 7; b >=0; b++){
        if( lastY[b] != 7 && lastY[b] != -1){
          i = lastX[b];
        }
      }
    }

}
   
        
  

  return 0;

}