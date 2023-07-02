#include "kanji.h"
#include <stdexcept>
kanji::kanji(std::vector<std::wstring> onReading,std::vector<std::wstring> kunReading, std::wstring character){
    on = onReading;
    kun = kunReading;
}

void kanji::setOn(std::vector<std::wstring> newReadings){
    on = newReadings;
}

void kanji::setKun(std::vector<std::wstring> newReadings){
    kun = newReadings;
}

std::vector<std::wstring> kanji::getOn(){
    return on;
}

std::vector<std::wstring> kanji::getKun(){
    return kun;
}

std::wstring kanji::getOn(int ind){
    try{
        return on[ind];
    }catch(std::out_of_range e){
        return L"";
    }
}

std::wstring kanji::getKun(int ind){
    try{
        return kun[ind];
    }catch(std::out_of_range e){
        return L"";
    }
}

void kanji::addOn(std::wstring addOn){
    on.push_back(addOn);
}

void kanji::addKun(std::wstring addOn){
    kun.push_back(addOn);
}