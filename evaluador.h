#ifndef E_H
#define E_H

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>

class eval
{
public:

    eval() = default; //define una funcion con una implementacion por default c++11
    
    
    std::vector<std::string> Tokenizar(std::string operacion);
    bool isNumber(std::string token);
    bool isToken(char token);
    bool isOperator(char token);
    bool isOther(char token);
    bool evaluarExpresion(std::string expresion);
    bool verificarParen(std::string expresion);
    bool verificarCorch(std::string expresion);
    bool verificarOperaciones(std::string expresion);
    bool verificarExtra(std::string expresion);
    bool verificarPoCExtra(std::string expresion);

};


#endif // !1E_H