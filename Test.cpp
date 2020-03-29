//Moria Gealia

#include "PhoneticFinder.hpp"
#include "doctest.h"
using namespace phonetic;
using namespace std;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
TEST_CASE("abc ABC"){
    CHECK(find("abc","abc")=="abc");
    CHECK(find("ABC","ABC")=="ABC");
    CHECK(find("ABC","abc")=="ABC");
    CHECK(find("abc","ABC")=="abc");
}
TEST_CASE("interchangeables w,v"){
    
    CHECK(find("wWvV","vvvv")=="wWvV");
    CHECK(find("wWvV","VVVV")=="wWvV");
    CHECK(find("wWvV","wwww")=="wWvV");
    CHECK(find("wWvV","WWWW")=="wWvV");

    CHECK(find("V","w")=="V");
    CHECK(find("W","v")=="W");
    CHECK(find("v","W")=="v");
    CHECK(find("w","V")=="w");
}
TEST_CASE("interchangeables j,g"){
    CHECK(find("jJgG","gggg")=="jJgG");
    CHECK(find("jJgG","GGGG")=="jJgG");
    CHECK(find("jJgG","JJJJ")=="jJgG");
    CHECK(find("jJgG","jjjj")=="jJgG");

    CHECK(find("G","j")=="G");
    CHECK(find("J","g")=="J");
    CHECK(find("g","J")=="g");
    CHECK(find("j","G")=="j");
}
TEST_CASE("interchangeables s,z"){
    CHECK(find("SsZz","zzzz")=="SsZz");
    CHECK(find("SsZz","ZZZZ")=="SsZz");
    CHECK(find("SsZz","SSSS")=="SsZz");
    CHECK(find("SsZz","ssss")=="SsZz");

    CHECK(find("S","z")=="S");
    CHECK(find("Z","s")=="Z");
    CHECK(find("s","Z")=="s");
    CHECK(find("z","S")=="z");
}
TEST_CASE("interchangeables d,t"){
    CHECK(find("DdTt","dddd")=="DdTt");
    CHECK(find("DdTt","DDDD")=="DdTt");
    CHECK(find("DdTt","TTTT")=="DdTt");
    CHECK(find("DdTt","tttt")=="DdTt");

    CHECK(find("D","t")=="D");
    CHECK(find("T","d")=="T");
    CHECK(find("d","T")=="d");
    CHECK(find("t","D")=="t");
}
TEST_CASE("interchangeables o,u"){
    CHECK(find("oOuU","oooo")=="oOuU");
    CHECK(find("oOuU","OOOO")=="oOuU");
    CHECK(find("oOuU","uuuu")=="oOuU");
    CHECK(find("oOuU","UUUU")=="oOuU");

    CHECK(find("O","u")=="O");
    CHECK(find("U","o")=="U");
    CHECK(find("o","U")=="o");
    CHECK(find("u","O")=="u");
}
TEST_CASE("interchangeables i,y"){
    CHECK(find("IiYy","iiii")=="IiYy");
    CHECK(find("IiYy","IIII")=="IiYy");
    CHECK(find("IiYy","YYYY")=="IiYy");
    CHECK(find("IiYy","yyyy")=="IiYy");

    CHECK(find("I","y")=="I");
    CHECK(find("Y","i")=="Y");
    CHECK(find("i","Y")=="i");
    CHECK(find("y","I")=="y");
}
TEST_CASE("interchangeables b,p,f"){
    CHECK(find("bBfFpP","bbbbbb")=="bBfFpP");
    CHECK(find("bBfFpP","ffffff")=="bBfFpP"); 
    CHECK(find("bBfFpP","pppppp")=="bBfFpP");
    CHECK(find("bBfFpP","BBBBBB")=="bBfFpP");
    CHECK(find("bBfFpP","FFFFFF")=="bBfFpP"); 
    CHECK(find("bBfFpP","PPPPPP")=="bBfFpP");  

    CHECK(find("B","f")=="B");
    CHECK(find("B","p")=="B");
    CHECK(find("F","b")=="F");
    CHECK(find("F","p")=="F");
    CHECK(find("P","b")=="P");
    CHECK(find("P","f")=="P");
    CHECK(find("b","F")=="b");
    CHECK(find("b","P")=="b");
    CHECK(find("f","B")=="f");
    CHECK(find("f","P")=="f");
    CHECK(find("p","B")=="p");
    CHECK(find("p","F")=="p");
}
TEST_CASE("interchangeables c,k,q"){
    CHECK(find("cCkKqQ","cccccc")=="cCkKqQ");
    CHECK(find("cCkKqQ","CCCCCC")=="cCkKqQ");
    CHECK(find("cCkKqQ","kkkkkk")=="cCkKqQ");
    CHECK(find("cCkKqQ","KKKKKK")=="cCkKqQ");
    CHECK(find("cCkKqQ","qqqqqq")=="cCkKqQ");
    CHECK(find("cCkKqQ","QQQQQQ")=="cCkKqQ");

    CHECK(find("C","k")=="C");
    CHECK(find("C","q")=="C");
    CHECK(find("K","c")=="K");
    CHECK(find("K","q")=="K");
    CHECK(find("Q","c")=="Q");
    CHECK(find("Q","k")=="Q");
    CHECK(find("c","K")=="c");
    CHECK(find("c","Q")=="c");
    CHECK(find("k","C")=="k");
    CHECK(find("k","Q")=="k");
    CHECK(find("q","C")=="q");
    CHECK(find("q","K")=="q");         
}
TEST_CASE("not first word in text"){
    CHECK(find(" abc o","abc")=="abc");
    CHECK(find("abc k","c")=="k");
}
TEST_CASE("find first instance"){
     CHECK(find("abc ABC apk","ABC")=="abc");
     CHECK(find("apk abc ABC","ABC")=="apk");
     CHECK(find("ABC apk abc","ABC")=="ABC");
     CHECK(find("f b p","b")=="f");
}

TEST_CASE("exeptions- word not found in text"){
    CHECK_THROWS_WITH(find(abc,"a"),"cant find a match");
    CHECK_THROWS_WITH(find("b c","a"),"cant find a match");
    CHECK_THROWS_WITH(find("",abc),"cant find a match");



}
TEST_CASE("exeptions- multiple or zero words to find"){
    CHECK_THROWS(find(abc,abc+" "+abc));
    CHECK_THROWS(find(abc,""));
    CHECK_THROWS(find(abc," "));
}