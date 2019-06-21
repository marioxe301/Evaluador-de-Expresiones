#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "evaluador.h"

eval ev;
//test operaciones comunes
std::vector<std::string>test1 = ev.passPosfix(ev.Tokenizar("10+3"));
std::vector<std::string>test2 = ev.passPosfix(ev.Tokenizar("1-5"));
std::vector<std::string>test3 = ev.passPosfix(ev.Tokenizar("4*2"));
std::vector<std::string>test4 = ev.passPosfix(ev.Tokenizar("6/2"));
std::vector<std::string>test5 = ev.passPosfix(ev.Tokenizar("2^3"));
std::vector<std::string>test6 = ev.passPosfix(ev.Tokenizar("10%2"));

//test operaciones mezcladas
std::vector<std::string>test7 = ev.passPosfix(ev.Tokenizar("10+2*3"));
std::vector<std::string>test8 = ev.passPosfix(ev.Tokenizar("1+1+1+1+4/4"));
std::vector<std::string>test9 = ev.passPosfix(ev.Tokenizar("10+1+2*3"));
std::vector<std::string>test10 = ev.passPosfix(ev.Tokenizar("10*2+1+6/(3%3)"));
std::vector<std::string>test11 = ev.passPosfix(ev.Tokenizar("2^3+2*2"));
std::vector<std::string>test12 = ev.passPosfix(ev.Tokenizar("2*2*2/4"));
//test operaciones con parentesis
std::vector<std::string>test13 = ev.passPosfix(ev.Tokenizar("10+(1+2)*2"));
std::vector<std::string>test14 = ev.passPosfix(ev.Tokenizar("1+1+1+1+1*(2*1)/4"));
std::vector<std::string>test15 = ev.passPosfix(ev.Tokenizar("10+(1+2*3)"));
std::vector<std::string>test16 = ev.passPosfix(ev.Tokenizar("(1*2)+(3/3)-(5%5)"));
std::vector<std::string>test17 = ev.passPosfix(ev.Tokenizar("2^3"));
std::vector<std::string>test18 = ev.passPosfix(ev.Tokenizar("(1*2)+(3^3)-(5%5)"));
std::vector<std::string>test19 = ev.passPosfix(ev.Tokenizar("(1*2)+(3%3)-(5%5)+(3%2)+(3/2)+21"));

//Test para evaluar errores
bool a1 = ev.evaluarExpresion("10+1+2)*2");
bool a2= ev.evaluarExpresion("1+1+1+1+1*(2*1)a4");
bool a3= ev.evaluarExpresion("10+([1+2*3)");
bool a4= ev.evaluarExpresion("()+(1*2)+(3/3)-(5%5)");
bool a5= ev.evaluarExpresion("2^");
bool a6= ev.evaluarExpresion("(1*2)+(3^3)-(5%5)");
bool a7= ev.evaluarExpresion("(1*2)(3%3)(5%5)+(3%2)+(3/2)21");

TEST_CASE("Test operaciones basicas"){
    CHECK(ev.evaluarExpresion(test1)== 13.0f);
    CHECK(ev.evaluarExpresion(test2)== -4.0f);
    CHECK(ev.evaluarExpresion(test3)== 8.0f);
    CHECK(ev.evaluarExpresion(test4)== 3.0f);
    CHECK(ev.evaluarExpresion(test5)== 8.0f);
    CHECK(ev.evaluarExpresion(test6)== 0.0f);

}

TEST_CASE("Test operaciones mezcladas "){
    CHECK(ev.evaluarExpresion(test7)== 16.0f);
    CHECK(ev.evaluarExpresion(test8)== 5.0f);
    CHECK(ev.evaluarExpresion(test9)== 17.0f);
    CHECK(ev.evaluarExpresion(test10)== INFINITY);
    CHECK(ev.evaluarExpresion(test11)== 12.0f);
    CHECK(ev.evaluarExpresion(test12)== 2.0f);

}

TEST_CASE("Test operaciones complejas"){
    CHECK(ev.evaluarExpresion(test13)== 16.0f);
    CHECK(ev.evaluarExpresion(test14)== 4.5f);
    CHECK(ev.evaluarExpresion(test15)== 17.0f);
    CHECK(ev.evaluarExpresion(test16)== 3.0f);
    CHECK(ev.evaluarExpresion(test17)== 8.0f);
    CHECK(ev.evaluarExpresion(test18)== 29.0f);
    CHECK(ev.evaluarExpresion(test19)== 23.5f);
}

TEST_CASE("Evalua las condiciones"){
    CHECK(a1== false );
    CHECK(a2== false );
    CHECK(a3== false );
    CHECK(a4== false );
    CHECK(a5== false );
    CHECK(a6== true );
    CHECK(a7== false);
}