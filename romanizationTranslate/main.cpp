#include <thread>
#include "kanConv.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <locale>
#include <codecvt>
#include <SFML/Graphics.hpp>

void initEnJpHMap(std::map<std::string,std::wstring>* );
void enToH(std::map<std::string,std::wstring>*, std::string*, std::wstring*);
void enToK(std::map<std::string,std::wstring>*, std::string*, std::wstring*);
void processText(std::string ,std::string&);

std::wstring stringtoWString(std::string start){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring end = converter.from_bytes(start);
    return end;
}



int main(int argc,char** argv){
    kanConv::init();
    std::map<std::string,std::wstring> enJPh;
    std::map<std::string,std::wstring> enJPk;
    initEnJpHMap(&enJPh);
    enJPk = enJPh;
    for (auto i = enJPk.begin();i!=enJPk.end();i++){
        i->second = i->second.at(0) + 0x60;
    }

    SetConsoleOutputCP(CP_UTF8); //set console to UTF8 encoding
    setvbuf(stdout, nullptr, _IOFBF, 1000); //add buffer to prevent unwanted truncation, remember to flush
    std::wcout.imbue(std::locale(std::locale::classic(),new std::codecvt_utf8_utf16<wchar_t>()));

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height),"My Window",sf::Style::Close); //make the window, make sure it is not bigger than the screen
    window.setFramerateLimit(20);
    std::string enT=""; //internal english string
    std::string tempEn = ""; //temp english string
    std::wstring jpHT=L""; //internal Hiragana
    std::wstring jpKT=L""; //internal Katakana
    std::wstring kanT=L""; //internal Kanji
    sf::Font yumin; //font for JP
    sf::Text eng; //display English
    sf::Text jpH; //display Hiragana
    sf::Text jpK; //display Katakana
    sf::Text kan; //display Kanji
    if (!yumin.loadFromFile("resrc\\yumin.ttf")){ //load font
        std::cerr << "Japanese font not found\n";
        return 1;
    }
    jpH.setFont(yumin); //set font
    jpH.setCharacterSize(48); //set character size
    jpH.setFillColor(sf::Color::White); //set color
    jpH.setPosition(300,100); //set start position

    jpK.setFont(yumin);
    jpK.setCharacterSize(48);
    jpK.setFillColor(sf::Color::White);
    jpK.setPosition(300,150);

    kan.setFont(yumin);
    kan.setCharacterSize(48);
    kan.setFillColor(sf::Color::White);
    kan.setPosition(300,200);

    sf::Font arial;
    if (!arial.loadFromFile("resrc\\arial.ttf")){
        std::cerr << "English font not found\n";
        return 1;
    }
    eng.setFont(arial);
    eng.setCharacterSize(48);
    eng.setFillColor(sf::Color::White);
    eng.setPosition(300,50);

    while(window.isOpen()){
        window.clear(); //clear window
        sf::Event event;
        while(window.pollEvent(event)){ //poll an event
            switch(event.type){
                case sf::Event::Closed: //if the event is "Close"
                    window.close();
                    break;
                case sf::Event::TextEntered: //if the event is "Text Entered" aka when the user enters text
                    switch(event.text.unicode){
                        case (8): //backspace
                            enT=enT.substr(0,enT.length()-1);
                            eng.setString(enT);
                            break;
                        case (13): //enter
                            break;
                        default: //any other character
                            enT+=(wchar_t) event.text.unicode;
                            eng.setString(enT);
                            break;
                    }
                case sf::Event::KeyReleased: //when the user releases a key
                    switch(event.key.code){
                        case sf::Keyboard::Enter: //if that key is enter
                            //set internal texts, kanji gonna suck
                            processText(enT,tempEn); //process the english text into something I can process
                            enToH(&enJPh,&tempEn,&jpHT); //convert to hiragana and store in jpHT
                            enToK(&enJPk,&tempEn,&jpKT); //convert to katakana and store in jpKT
                            //convert to kanji/hiragana and store in kanT
                            tempEn=""; //reset the temp english string
                            jpH.setString(jpHT); //set display string to jpHT
                            jpK.setString(jpKT); //set display string to jpKT
                            kan.setString(kanT); //set distplay string to kanT
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        window.draw(jpH); //draw Hiragana
        window.draw(jpK); //draw Katakana
        window.draw(kan); //draw Kanji
        window.draw(eng); //draw English
        window.display(); //display drawn text
        tempEn = ""; //reset internal english
        jpHT = L""; //reset internal hiragana
        jpKT = L""; //reset internal katakana
        kanT = L""; //reset internal kanji
    }
}

void initEnJpHMap(std::map<std::string,std::wstring>* enJPh){
    typedef std::pair<std::string,std::wstring> tra;
    enJPh->insert(tra("a",L"\u3042")); //A-group
    enJPh->insert(tra("i",L"\u3044"));
    enJPh->insert(tra("u",L"\u3046"));
    enJPh->insert(tra("e",L"\u3048"));
    enJPh->insert(tra("o",L"\u304A"));
    enJPh->insert(tra("ka",L"\u304B")); //K-group
    enJPh->insert(tra("ki",L"\u304D"));
    enJPh->insert(tra("ku",L"\u304F"));
    enJPh->insert(tra("ke",L"\u3051"));
    enJPh->insert(tra("ko",L"\u3053"));
    enJPh->insert(tra("sa",L"\u3055")); //S-Group
    enJPh->insert(tra("shi",L"\u3057"));
    enJPh->insert(tra("su",L"\u3059"));
    enJPh->insert(tra("se",L"\u305B"));
    enJPh->insert(tra("so",L"\u305D"));
    enJPh->insert(tra("ta",L"\u305F")); //T-Group
    enJPh->insert(tra("chi",L"\u3061"));
    enJPh->insert(tra("tsu",L"\u3064"));
    enJPh->insert(tra("te",L"\u3066"));
    enJPh->insert(tra("to",L"\u3068"));
    enJPh->insert(tra("na",L"\u306A")); //N-Group
    enJPh->insert(tra("ni",L"\u306b"));
    enJPh->insert(tra("nu",L"\u306c"));
    enJPh->insert(tra("ne",L"\u306D"));
    enJPh->insert(tra("no",L"\u306E"));
    enJPh->insert(tra("ha",L"\u306f")); //H-Group
    enJPh->insert(tra("hi",L"\u3072"));
    enJPh->insert(tra("hu",L"\u3075"));
    enJPh->insert(tra("he",L"\u3078"));
    enJPh->insert(tra("ho",L"\u307B"));
    enJPh->insert(tra("fa",L"\u306f")); //H-Group - F variant
    enJPh->insert(tra("fi",L"\u3072"));
    enJPh->insert(tra("fu",L"\u3075"));
    enJPh->insert(tra("fe",L"\u3078"));
    enJPh->insert(tra("fo",L"\u307B"));
    enJPh->insert(tra("ma",L"\u307e")); //M-Group
    enJPh->insert(tra("mi",L"\u307F"));
    enJPh->insert(tra("mu",L"\u3080"));
    enJPh->insert(tra("me",L"\u3081"));
    enJPh->insert(tra("mo",L"\u3082"));
    enJPh->insert(tra("ya",L"\u3084")); //Y-group
    enJPh->insert(tra("yu",L"\u3086"));
    enJPh->insert(tra("yo",L"\u3088"));
    enJPh->insert(tra("ra",L"\u3089")); //R-Group
    enJPh->insert(tra("ri",L"\u308A"));
    enJPh->insert(tra("ru",L"\u308b"));
    enJPh->insert(tra("re",L"\u308c"));
    enJPh->insert(tra("ro",L"\u308D"));
    enJPh->insert(tra("la",L"\u3089")); //R-Group - L variant
    enJPh->insert(tra("li",L"\u308A"));
    enJPh->insert(tra("lu",L"\u308b"));
    enJPh->insert(tra("le",L"\u308c"));
    enJPh->insert(tra("lo",L"\u308D"));
    enJPh->insert(tra("wa",L"\u308f")); //W-Group
    enJPh->insert(tra("wo",L"\u3092"));
    enJPh->insert(tra("ga",L"\u304c")); //G-Group
    enJPh->insert(tra("gi",L"\u304e"));
    enJPh->insert(tra("gu",L"\u3050"));
    enJPh->insert(tra("ge",L"\u3052"));
    enJPh->insert(tra("go",L"\u3054"));
    enJPh->insert(tra("za",L"\u3056")); //Z-Group
    enJPh->insert(tra("ji",L"\u3058"));
    enJPh->insert(tra("zu",L"\u305A"));
    enJPh->insert(tra("ze",L"\u305c"));
    enJPh->insert(tra("zo",L"\u305e"));
    enJPh->insert(tra("da",L"\u3060")); //D-Group
    enJPh->insert(tra("ji",L"\u3062"));
    enJPh->insert(tra("zu",L"\u3065"));
    enJPh->insert(tra("de",L"\u3067"));
    enJPh->insert(tra("do",L"\u3069"));
    enJPh->insert(tra("ba",L"\u3070")); //B-Group
    enJPh->insert(tra("bi",L"\u3073"));
    enJPh->insert(tra("bu",L"\u3076"));
    enJPh->insert(tra("be",L"\u3079"));
    enJPh->insert(tra("bo",L"\u307C"));
    enJPh->insert(tra("pa",L"\u3071")); //P-Group
    enJPh->insert(tra("pi",L"\u3074"));
    enJPh->insert(tra("pu",L"\u3077"));
    enJPh->insert(tra("pe",L"\u307A"));
    enJPh->insert(tra("po",L"\u307D"));
    enJPh->insert(tra("Na",L"\u3093")); //N
    enJPh->insert(tra("Stsu",L"\u3063")); //small tsu
    enJPh->insert(tra("Sya",L"\u3083")); //small Y-Group
    enJPh->insert(tra("Syu",L"\u3085"));
    enJPh->insert(tra("Syo",L"\u3087"));
}

void enToH(std::map<std::string,std::wstring>* map, std::string* in, std::wstring* out){
    char vowels[] = {'a','i','u','e','o'};
    int temp = 0xfffffff;
    std::string toFind;
    for (int i=0;i<in->length();){
        for (char vowel : vowels){
            if (temp > in->find(vowel,i) && in->find(vowel,i)>=i){
                temp = in->find(vowel,i);
            }
        }
        toFind = in->substr(i,temp-i+1);
        try{
            *(out) += map->at(toFind);
        }catch(std::out_of_range e){
            std::cerr << "Invalid input to map\n" << toFind << "\n";
        }

        i = temp+1;
        temp = 0xfffffff;
    }
}

void enToK(std::map<std::string,std::wstring>* map, std::string* in, std::wstring* out){
    enToH(map,in,out);
}

void processText(std::string in,std::string& out){
    char vowels[] = {'a','i','u','e','o'};
    int temp; //temp index
    std::string tempStr; //temp string
    std::string subStr; //sub string of in containing all consonant leading to the next vowel
    for (int i=0; i<in.length();){
        if (in.substr(i) == "n"){ //if "n" is the entire input string
            out += "Na";
            return;
        }
        temp = 0xfffffff;
        for (char vowel : vowels){ //find index of earliest vowel in input and store in temp
            if (temp > in.find(vowel,i) && in.find(vowel,i)>=i){
                temp = in.find(vowel,i);
            }
        }

        subStr = in.substr(i,temp-i+1); //store the relevant sub-string for reference
        if (subStr.length() > 1 && subStr.at(0) == subStr.at(1)){ //small tsu
            if (subStr.at(0)=='n'){
                out+="Na";
            }else{
                out+="Stsu";
            }
            subStr=subStr.substr(1);
        }
        if (subStr.at(0) == 'n'){ //test for standalone n
            bool vw = false; //if the next character is a vowel
            for (char vowel : vowels){
                if (!vw){
                    vw = subStr.at(1) == vowel;
                }
            }
            if (!vw){ //if next char is not vowel
                out += "Na";
                subStr = subStr.substr(1); //truncate to get rid of standalone n
            }
        }
        if (subStr.length() > 1 && subStr.at(1) == 'y'){ //small ya,yu,yo
            tempStr = subStr.at(0);
            tempStr += "iSy";
            tempStr += subStr.back();
            out += tempStr;
        }else if(subStr.at(0) == 'c' && subStr.at(subStr.length()-1)!='i'){ //if the character is "chi"
            tempStr = "chiSy";
            tempStr += subStr.back();
            out += tempStr;
        }else if(subStr.at(0) == 'j' && subStr.at(subStr.length()-1)!='i'){ //if the character is ji as small ya,yu,yo does not add a y (ja,ju,jo)
            tempStr = "jiSy";
            tempStr += subStr.at(subStr.length()-1);
            out += tempStr;
        }else if(subStr.substr(0,2) == "sh" && subStr.back()!='i'){ //if the character is shi
            tempStr = "shiSy";
            tempStr += subStr.back();
            out += tempStr;
        }else{
            out += subStr;
        }

        i = temp + 1;
        temp = 0xfffffff;
    }
}