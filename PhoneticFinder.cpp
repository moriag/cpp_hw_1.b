// cases: w,v  g,j  s,z  d,t  o,u  i,y  b,p,f  c,k,q
#include "PhoneticFinder.hpp"
#include <string>

namespace phonetic{
string find(string t,string w){
    
    string abc="abcdebghigclmnobcrsdovvxisAAAAAAabcdebghigclmnobcrsdovvxis";
    
    int start=w.find_first_not_of(" ");
    int end=w.find_last_not_of(" ");
    string word2,word=w.substr(start,end-start+1);
    
    if(word.empty()||word.find_first_of(' ')<word.length()){
        throw std::exception();
    }
    
    string txt=t.substr(t.find_first_not_of(" "))+" ";

    while(txt.length()>word.length()){
        
        word2=txt.substr(0,txt.find_first_of(" "));
        txt=txt.substr(txt.find_first_of(" ")+1);
                    
        if(word.length()!=word2.length())continue;
        bool find=true;
        for(int i=0;i<word.length();i++){
            if( abc[word[i]-'A'] == abc[word2[i]-'A'] )continue;
            find=false;break;
        }
        if(find)return word2;
    }
    throw std::exception();
}
}