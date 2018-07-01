#include<iostream>
#include<stdlib.h>

using namespace std;
bool hasMinDist(int xVal[8], int yVal[8], int x, int y){
    for(int a = 0; a < x; a++){
        
            if(xVal[a] != -1 && abs(x-xVal[a] + y - yVal[a]) < 4){
                return false;
            }
        
    }
    return true;
}



int main(void){
 
 


    bool isValid = true;
    bool horzLine[8] = {0,0,0,0,0,0,0,0};
    bool vertLine[8] = {0,0,0,0,0,0,0,0};

    int xVal[8] ={-1,-1,-1,-1,-1,-1,-1,-1};
    int yVal[8] ={-1,-1,-1,-1,-1,-1,-1,-1};
    int queenNum = 0;
    int lastQueen[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

int lastX[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int lastY[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    

    for(int i = 0; i< 8; i++){
        
    
        int tempQueen = 0;
        for(int j = lastX[i]+1; j < 8 ; j++){


                
                lastX[i] = i;
                lastY[i] = j;
                
                if(horzLine[i] || vertLine[j] || !hasMinDist(xVal,  yVal, i, j)){
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
        lastQueen[i] = tempQueen;
      } 
      else{
        lastQueen[i] = lastQueen[i-1]+tempQueen;
      }
        
        queenNum = lastQueen[i];

    if( queenNum >= 4){
        for(int i = 0; i < 4 ; i++){
            cout << " x:" << xVal[i]<< " y:"<<yVal[i] ;
        }
    }
    
    /*
    for(int c = 0; c<8; c++){
      cout<<xVal[c]<<" "<<yVal[c];
      cout<<" "<<lastX[c]<<":"<<lastY[c]<<" ";
    } 
    */
    if(i == 7 && lastY[7] == 7){
      for(int b = 7; b >=0; b--){
        if( lastY[b] != 7 && lastY[b] != -1){
          i = lastX[b];
        }else{
            lastY[b] = -1;
            lastY[b] = -1;
        }
      }
    }

}
   
        
  

  return 0;

}