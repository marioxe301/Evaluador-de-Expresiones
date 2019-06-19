#ifndef E_H
#define E_H

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <math.h>

struct operador{
    int peso;
    char op;
};

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
    bool verificarIgualPeso(std::string,std::stack<std::string>);
    bool verificarPesoMayor(std::string,std::stack<std::string>);
    bool verificarPesoMenor(std::string,std::stack<std::string>);


    std::vector<operador> PesosOP();
    std::vector<std::string>passPosfix(std::vector<std::string>);
    double evaluarExpresion(std::vector<std::string>);
    //^ % mismo peso 
    //* / mismo peso
    // + - msimo peso

};


#endif // !1E_H