#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "evaluador.h"

eval ev;
std::vector<std::string>test1 = ev.passPosfix(ev.Tokenizar("10+(1+2)*2"));
std::vector<std::string>test2 = ev.passPosfix(ev.Tokenizar("10*2"));
std::vector<std::string>test3 = ev.passPosfix(ev.Tokenizar("10+(1+2)"));
std::vector<std::string>test4 = ev.passPosfix(ev.Tokenizar("(1+2)*2"));

TEST_CASE("Test de la evaluacion"){
    CHECK(ev.evaluarExpresion(test1)== 16);
    CHECK(ev.evaluarExpresion(test2)== 20);
    CHECK(ev.evaluarExpresion(test3)== 13);
    CHECK(ev.evaluarExpresion(test4)== 6);
}
