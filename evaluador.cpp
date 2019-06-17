#include "evaluador.h"
#include <regex>

//funcion separa por tokens la expresion matematica
std::vector<std::string>  eval::Tokenizar(std::string expres){

    std::vector<std::string> tokens;
    
    //definicio de datos mediante parentesis string a('crwe') c++11
    std::string expresion(expres);

    //regular expresion, permite generar expresiones regulares y tokenizarlas c++11
    std::regex expre("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*]");

    //tipo de dato que reconoce que tipo es "auto" c++11
    auto inicio = std::sregex_iterator(expresion.begin(), expresion.end(), expre);

    auto final = std::sregex_iterator();

    for (std::sregex_iterator i = inicio; i != final; ++i) {
        std::cout << (*i).str() << std::endl;
        tokens.push_back((*i).str());
    }

    return tokens;
}

//si es numero
bool eval::isNumber(char token){
    std::string tokens = "0123456789.";
    bool esNumero = false;
    for(int i=0; i< tokens.length();i++){
        if(token == tokens[i]){
            esNumero = true;
        }
    }
    
    return esNumero;

}

//si es un token
bool eval::isToken(char token){
    std::string tokens = "[]()";
    bool esToken = true;
    for(int i=0; i< tokens.length();i++){
        if(token !=tokens[i]){
            esToken = false;
        }
    }

    return esToken;
}

//si es un operador
bool eval::isOperator(char token){
    std::string tokens = "+-*/%^";
    bool esOperacion = true;
    for(int i=0; i< tokens.length();i++){
        if(token != tokens[i]){
            esOperacion = false;
        }
    }

    return esOperacion;
}

bool eval::evaluarExpresion(std::string expresion){
    
}

bool eval::verificarParen(std::string expresion){
    int cantidadPA = 0;
    int cantidadPC = 0;
    for(int i = 0; i<expresion.length();i++){
        if(expresion[i]== '('){
            cantidadPA++;
        }

        if(expresion[i]==')'){
            cantidadPC++;
        }
    }
    //si tiene a misma cantidad de parentesis entonces todos estan bien
    if(cantidadPA == cantidadPC){
        return true;
    }else{
        return false;
    }
}

bool eval::verificarCorch(std::string expresion){
    int cantidadLA = 0;
    int cantidadLC = 0;
    for(int i = 0; i< expresion.length();i++){
        if(expresion[i]=='['){
            cantidadLA++;
        }

        if(expresion[i]== ']'){
            cantidadLC++;
        }
    }

    if(cantidadLA == cantidadLC){
        return true;
    }else{
        return false;
    }
}

bool eval::verificarOperaciones(std::string expresion){
    //si verifica que ya no es un numero debe ir seguido de una operacion junto con otro numero
    for(int i=0; i< expresion.length();i++){
        
    }
}

bool eval::verificarExtra(std::string expresion){
    std::string opInvalidos = " !#$=?¡'¿qwertyuiop´¨~asdfghjklñ{}`<>zxcvbnm;,:-QWERTYUIOPASDFGHJKLÑZXCVBNM";
    bool verificacion= true;
    for(int i=0;i<expresion.length();i++){
        for(int j=0; j< opInvalidos.length();j++){
            if(expresion[i]==opInvalidos[j]){
                verificacion = false;
            }
        }
    }

    return verificacion;
}

bool eval::verificarPoCExtra(std::string expresion){
    bool verificacion = true;
    for(int i = 0; i < expresion.length()-1;i++){
        if(expresion[i] == '(' && expresion[i+1] == ')' ){
            verificacion = false;
        }
        if(expresion[i] == '[' && expresion[i+1] == ']' ){
            verificacion = false;
        }
    }
    return verificacion;
}
