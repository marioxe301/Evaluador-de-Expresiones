#include <iostream>
#include "evaluador.h"

using namespace std;

int main(){
    eval ev;

    //ev.Tokenizar("[(34+4)-3]*3");
    //std::cout<< ev.isNumber("-1");
    //std::cout << ev.evaluarExpresion("[(34+4)-3]*3") <<endl;
    //ev.PesosOP();
    vector<string>test = ev.passPosfix(ev.Tokenizar("(1*2)+(3%3)-(5%5)+(3%2)+(3/2)+21"));
    for(int i = 0;  i < test.size() ;i++){
        cout<< test[i]<<" ";
    }
    cout << endl;
    cout << ev.evaluarExpresion(test) << endl;
    //cout << to_string(-14.5);
    //cout <<<<endl;
    return 0;
}
