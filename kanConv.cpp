#include "kanConv.h"

std::vector<kanji> kanConv::posskan(std::wstring input){ //pass self as last param
    std::vector<kanji> onRead,kunRead;
    for(kanji possible : KAN){
        for (std::wstring reading : possible.getKun()){
            if (reading == input){
                kunRead.push_back(possible);
            }
        }
        for (std::wstring reading : possible.getOn()){
            if (reading == input){
                kunRead.push_back(possible);
            }
        }
    }
    std::vector<kanji> out(onRead);
    for (kanji kunR : kunRead){
        out.push_back(kunR);
    }
    return out;
} //all possible readings
std::vector<kanji> kanConv::posskan(std::wstring input, bool mode){ //pass self as last param
    std::vector<kanji> out;
    for (kanji possible : KAN){
        for (std::wstring reading : (mode ? possible.getOn() : possible.getKun())){
            if (reading == input){
                out.push_back(possible);
            }
        }
    }
    return out;
} //all possible on/kun readings, true is on false is kun