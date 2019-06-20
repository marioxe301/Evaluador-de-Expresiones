#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "evaluador.h"

eval ev;
std::vector<std::string>test1 = ev.passPosfix(ev.Tokenizar("10+(1+2)*2"));
std::vector<std::string>test2 = ev.passPosfix(ev.Tokenizar("1+1+1+1+1*(2*1)/4"));
std::vector<std::string>test3 = ev.passPosfix(ev.Tokenizar("10+(1+2*3)"));
std::vector<std::string>test4 = ev.passPosfix(ev.Tokenizar("(1*2)+(3/3)-(5/5)"));

TEST_CASE("Test de la evaluacion"){
    CHECK(ev.evaluarExpresion(test1)== 16.0f);
    CHECK(ev.evaluarExpresion(test2)== 4.5f);
    CHECK(ev.evaluarExpresion(test3)== 17.0f);
    CHECK(ev.evaluarExpresion(test4)== 2.0f);
}
