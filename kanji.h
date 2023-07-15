#include <string>
#include <vector>
class kanji{ //TODO: add more info about each kanji (grammatical use(noun, verb, adverb etc etc), defination/translation, common words using that kanji(?))
    public:
        kanji(std::vector<std::wstring> , std::vector<std::wstring> , std::wstring); //set both readings and character on init
        std::vector<std::wstring> getOn(); //return on readings
        std::vector<std::wstring> getKun(); //return kun readings
        std::wstring getOn(int ); //return on reading
        std::wstring getKun(int ); //return kun reading
        void addOn(std::wstring); //add on reading
        void addKun(std::wstring ); //add kun reading
        std::wstring character;
    private:
        std::vector<std::wstring> on; 
        std::vector<std::wstring> kun;
};
