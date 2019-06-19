#include "evaluador.h"

//funcion separa por tokens la expresion matematica
std::vector<std::string>  eval::Tokenizar(std::string expres){

    std::vector<std::string> tokens;
    
    //definicio de datos mediante parentesis string a('crwe') c++11
    std::string expresion(expres);

    //regular expresion, permite generar expresiones regulares y tokenizarlas c++11
    std::regex expre("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\/\\*\\%\\^\\[\\]]");

    //tipo de dato que reconoce que tipo es "auto" c++11
    auto inicio = std::sregex_iterator(expresion.begin(), expresion.end(), expre);

    auto final = std::sregex_iterator();

    for (std::sregex_iterator i = inicio; i != final; ++i) {
        //std::cout << (*i).str() << std::endl;
        tokens.push_back((*i).str());
    }

    return tokens;
}

//si es numero
bool eval::isNumber(std::string token){
    std::string tokens = "[]()+-/%*^";
    bool esNumero = true;
    for(int i=0; i< tokens.length();i++){
        if(token == std::string(1,tokens[i])){
            esNumero = false;
        }
    }
    
    return esNumero;

}

//si es un token
bool eval::isToken(char token){
    std::string tokens = "[]()";
    bool esToken = false;
    for(int i=0; i< tokens.length();i++){
        if(token ==tokens[i]){
            esToken = true;
        }
    }

    return esToken;
}

//si es un operador
bool eval::isOperator(char token){
    std::string tokens = "+-*/%^";
    bool esOperacion = false;
    for(int i=0; i< tokens.length();i++){
        if(token == tokens[i]){
            esOperacion = true;
        }
    }

    return esOperacion;
}

bool eval::isOther(char token){
    std::string opInvalidos = " !#$=?¡'¿qwertyuiop´¨~asdfghjklñ{}`<>zxcvbnm;,:_QWERTYUIOPASDFGHJKLÑZXCVBNM";
    bool esOtro= false;
    for(int i = 0; i < opInvalidos.length();i++){
        if(token==opInvalidos[i]){
            esOtro= true;
        }
    }
    return esOtro;
}

bool eval::evaluarExpresion(std::string expresion){
    bool ev = true;
    bool evaluacion[]={
        verificarParen(expresion),
        verificarCorch(expresion),
        verificarOperaciones(expresion),
        verificarExtra(expresion),
        verificarPoCExtra(expresion)
    };

    if(!evaluacion[0]){
        std::cout<<"Verifique algun parentesis"<< std::endl;
        ev = false;
    } 
    if(!evaluacion[1]){
        std::cout<<"Verifique algun corchete"<< std::endl;
         ev = false;
    } 
    if(!evaluacion[2]){
        std::cout<<"Verifique alguna operacion"<< std::endl;
         ev = false;
    } 
    if(!evaluacion[3]){
        std::cout<<"Verifique si no hay un simbolo invalido"<< std::endl;
         ev = false;
    }
    if(!evaluacion[4]){
        std::cout<<"Verifique algun caso invalido"<< std::endl;
         ev = false;
    }

    return ev;
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
    //si encuentra un operador primero entonces la expresion esta mal
    //si encuentra un numero debe segirle un operador
    //ejemplo = ((23+4))*4 = para esta funcion = 23+4*4-1
    //bool verificacion = true;
    int contadornumeros= 0;
    int contadorsignos=0;

    //feature de c++17 permite decirle al compilador que ignore este warning de variable no usada

    [[maybe_unused]]int otrocont = 0;

    //eliminar corchetes y parentesis para que solo quede la expresion
    std::string operacion = expresion;

    //actualizaciones a la libreria algorithm uso de remove c++17
    operacion.erase(std::remove(operacion.begin(),operacion.end(),'('),operacion.end());
    operacion.erase(std::remove(operacion.begin(),operacion.end(),')'),operacion.end());
    operacion.erase(std::remove(operacion.begin(),operacion.end(),'['),operacion.end());
    operacion.erase(std::remove(operacion.begin(),operacion.end(),']'),operacion.end());

    std::vector<std::string> exp = Tokenizar(operacion);
    //verifica si hay algun operador al inicio o al final
    if(isOperator(operacion[0]) || isOperator(operacion[operacion.length()-1])){
        return false;
    }else{
        
        for(int i=0; i< exp.size();i++){
            if(isNumber(exp[i])){
                contadornumeros++;
                
            }

            if(isOperator(exp[i][0])){
                contadorsignos++;
            }

        }
    }

    if(contadorsignos == (contadornumeros-1)){
        return true;
    }else{
        return false;
    }
}

bool eval::verificarExtra(std::string expresion){
    std::string opInvalidos = " !#$=?¡'¿qwertyuiop´¨~asdfghjklñ{}`<>zxcvbnm;,:QWERTYUIOPASDFGHJKLÑZXCVBNM";
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

        if(expresion[i]== '(' && isOperator(expresion[i+1])){
            verificacion = false;
        }

        if(expresion[i]== '[' && isOperator(expresion[i+1])){
            verificacion = false;
        }

        if(expresion[i]== '(' && isOther(expresion[i+1])){
            verificacion = false;
        }

        if(expresion[i]== '[' && isOther(expresion[i+1])){
            verificacion = false;
        }

    }
    return verificacion;
}

std::vector<operador> eval::PesosOP(){
    std::vector <operador> lista = {
        operador({1,'+'}),
        operador({1,'-'}),
        operador({2,'*'}),
        operador({2,'/'}),
        operador({3,'^'}),
        operador({3,'%'})
    };
    return lista;
}

std::vector<std::string> eval::passPosfix(std::vector<std::string> expresion){
    std::stack<std::string>signos;
    std::stack<std::string>numeros;
    std::vector<std::string>posfijo;

    std::string a;
    int cont=0;
    std::vector<operador> pesos = PesosOP();
    // + - -> 1 * / -> 2 y ^ % -> 3
    for(int i=0;i< expresion.size(); i++){
        if(isToken(expresion[i][0])){
            if(expresion[i]=="(" || expresion[i]=="["){
                    signos.push(expresion[i]);
            }else{
                for(int a = 0; a < cont;a++){
                    numeros.push(signos.top());
                    signos.pop();                   
                }
                signos.pop();
                cont=0;
            }
        }else if(isNumber(expresion[i])){
            numeros.push(expresion[i]);
        }else if(isOperator(expresion[i][0])){
            if(signos.empty()){
                signos.push(expresion[i]);
            }else{
                    if(verificarIgualPeso(expresion[i],signos)){
                            numeros.push(signos.top());
                            signos.pop();
                            signos.push(expresion[i]);
                    }else if(verificarPesoMayor(expresion[i],signos)){
                            signos.push(expresion[i]);
                    }else if(verificarPesoMenor(expresion[i],signos)){
                            numeros.push(signos.top());
                            signos.pop();
                            signos.push(expresion[i]);
                    }else{
                            signos.push(expresion[i]);
                            cont++;
                    }
                }
            }
        }

        if(signos.empty()){
            while(!numeros.empty()){
                posfijo.push_back(numeros.top());
                numeros.pop();
            }
            return posfijo;
        }else{
            while(!numeros.empty()){
                posfijo.push_back(numeros.top());
                numeros.pop();
            }

            std::reverse(posfijo.begin(),posfijo.end());
            
            while(!signos.empty()){
                posfijo.push_back(signos.top());
                signos.pop();
            }

            return posfijo;
        }
}


bool eval::verificarIgualPeso(std::string token,std::stack<std::string> pila){
        if(token[0]=='+'){
            if(pila.top()=="+"||pila.top()=="-"){
                return true;
            }
        }else if (token[0]=='-'){
            if(pila.top()=="-"||pila.top()=="+"){
                return true;
            }
        }else if (token[0]=='*'){
            if(pila.top()=="*"||pila.top()=="/"){
                return true;
            }
        }else if (token[0]=='/'){
           if(pila.top()=="/"||pila.top()=="*"){
                return true;
            }
        }else if (token[0]=='^'){
            if(pila.top()=="^"||pila.top()=="%"){
                return true;
            }
        }else if(token[0]=='%'){
            if(pila.top()=="%"||pila.top()=="^"){
                return true;
            }
        }else{
            return false;
        }    
}

bool eval::verificarPesoMenor(std::string token,std::stack<std::string> pila){

        if(token[0]=='+'){
            if(pila.top()== "*"||pila.top()== "/"||pila.top()== "%"||pila.top()== "^"){
                return true;
            }
        }else if (token[0]=='-'){
            if(pila.top()== "*"||pila.top()== "/"||pila.top()== "%"||pila.top()== "^"){
                return true;
            }
        }else if (token[0]=='*'){
            if(pila.top()== "%"||pila.top()== "^"){
                return true;
            }else{
                return false;
            }
        }else if (token[0]=='/'){
            if(pila.top()== "%"||pila.top()== "^"){
                return true;
            }else{
                return false;
            }
        }else if (token[0]=='^'){
            return false;
        }else if(token[0]=='%'){
            return false;
        }
        
    }


bool eval::verificarPesoMayor(std::string token,std::stack<std::string> pila){
        if(token[0]=='+'){
            if(pila.top()== "*"||pila.top()== "/"||pila.top()== "%"||pila.top()== "^"){
                return false;
            }
        }else if (token[0]=='-'){
            if(pila.top()== "*"||pila.top()== "/"||pila.top()== "%"||pila.top()== "^"){
                return false;
            }
        }else if (token[0]=='*'){
            if(pila.top()== "%"||pila.top()== "^"){
                return false;
            }else{
                return true;
            }
        }else if (token[0]=='/'){
            if(pila.top()== "%"||pila.top()== "^"){
                return false;
            }else{
                return true;
            }
        }else if (token[0]=='^'){
            return true;
        }else if(token[0]=='%'){
            return true;
        }
                 
}
