#include <iostream>
#include "evaluador.h"

using namespace std;

int main(){
    eval ev;

    //ev.Tokenizar("[(23)+56.45)]*23+1");
    //std::cout<< ev.isNumber("-1");
    std::cout << ev.evaluarExpresion("[(34+4)-3]*3") <<endl;

    return 0;
}