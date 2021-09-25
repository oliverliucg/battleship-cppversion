#include "Board.h"
#include <iostream>
using namespace std;

char checkShip(Board b){
  
  return ' ';
}
void showTest(Board myself){
  cout<<myself.getHeight();
}
void showMyself(Board myself){
  //zeroth line
  cout<<' ';
  for (char k = '0';k<'0'+myself.getWidth()-1;k++){
    cout<<k<<'|';
  }
  cout<<char('0'+myself.getWidth()-1)<<' '<<endl;
  //internal line
  for(char j='A';j<='A'+myself.getHeight()-1;j++){
    cout<<j;
    for(char i='0';i<='8';i++){
    cout<<checkShip(myself);
    cout<<'|';
    }
    cout<<' '<<j<<endl;
  }

  //bottom line
  cout<<' ';
  for (char k = '0';k<'0'+myself.getWidth()-1;k++){
    cout<<k<<'|';
  }
  cout<<char('0'+myself.getWidth()-1)<<' '<<endl;  
}

void show(Board myself, Board other, bool isOnlyMyself){
  if(isOnlyMyself==false){
    }else{
    showMyself(myself);
  }
}
