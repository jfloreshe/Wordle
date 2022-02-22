#include "./include/APP/wordle.hpp"
#include <iostream>
#include <string>
#include <locale>
#include <set>
#include<time.h>

int main(){
  srand(time(0));
  WORDLE::Game* app = new WORDLE::Game {UI::Languages::SPANISH, 6, 5};
  app -> run();
  delete app;    
  return 0;
}