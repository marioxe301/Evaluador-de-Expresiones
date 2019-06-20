#ifndef E_H
#define E_H

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <thread>
#include <thread>
#include <chrono>
#include "progress_bar.hpp"

struct operador{
    int peso;
    char op;
};

struct constantes{
    //variables booleanas en constantes binarias c++14
    inline static const bool r1 = 0b1;
    inline static const bool r2 = 0b0;
};

class eval
{
public:

    eval() = default; //define una funcion con una implementacion por default c++11
    
    
    std::vector<std::string> Tokenizar(std::string operacion);
    //feature c++14 auto en funciones
    auto isNumber(std::string token)-> bool;
    auto isToken(char token)-> bool;
    auto isOperator(char token)-> bool;
    auto isOther(char token) -> bool;

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
    float evaluarExpresion(std::vector<std::string>);
    void FuncionPrincipal(void);
    //^ % mismo peso 
    //* / mismo peso
    // + - msimo peso

};


#endif // !1E_H