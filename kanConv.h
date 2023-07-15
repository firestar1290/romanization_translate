
#include "kanji.h"
#include <vector>
class kanConv{
    public:
        std::vector<kanji> posskan(std::wstring); //all possible readings
        std::vector<kanji> posskan(std::wstring, bool); //all possible on/kun readings, true is on false is kun
    private:
        const std::vector<kanji> KAN{ //on, kun
            kanji(std::vector<std::wstring>{L"だい"},std::vector<std::wstring>{L"おお"},L"大"), //big
            kanji(std::vector<std::wstring>{L"がく",L"がっ"},std::vector<std::wstring>{L"まな"},L"学"), //learn
            kanji(std::vector<std::wstring>{L"こう"},std::vector<std::wstring>{},L"校"), //school
            kanji(std::vector<std::wstring>{L"こう"},std::vector<std::wstring>{L"たか"},L"高"), //expensive/tall/high, yes this is used for high school
            kanji(std::vector<std::wstring>{L"せん"},std::vector<std::wstring>{L"さき"},L"先"), //ahead
            kanji(std::vector<std::wstring>{L"せん",L"ぜん"},std::vector<std::wstring>{},L"千"), //1000
            kanji(std::vector<std::wstring>{L"せん"},std::vector<std::wstring>{L"かわ"},L"川"), //river
            kanji(std::vector<std::wstring>{L"せい"},std::vector<std::wstring>{L"なま"},L"生"), //life
            kanji(std::vector<std::wstring>{L"じん",L"にん"},std::vector<std::wstring>{L"ひと"},L"人"), //person
            kanji(std::vector<std::wstring>{L"ざん",L"さん"},std::vector<std::wstring>{L"やま"},L"山"), //mountain
            kanji(std::vector<std::wstring>{L"さん"},std::vector<std::wstring>{L"みっ"},L"三"), //3
            kanji(std::vector<std::wstring>{L"しょう"},std::vector<std::wstring>{L"うえ"},L"上"), //on/above
            kanji(std::vector<std::wstring>{L"しょう"},std::vector<std::wstring>{L"ちい"},L"小"), //small
            kanji(std::vector<std::wstring>{L"げ"},std::vector<std::wstring>{L"した",L"くだ"},L"下"), //under
            kanji(std::vector<std::wstring>{L"げつ",L"がつ"},std::vector<std::wstring>{L"つき"},L"月"), //moon/month
            kanji(std::vector<std::wstring>{L"ちゅう"},std::vector<std::wstring>{L"なか"},L"中"), //middle/in
            kanji(std::vector<std::wstring>{L"いち",L"いっ"},std::vector<std::wstring>{L"ひと"},L"一"), //1
            kanji(std::vector<std::wstring>{L"にち",L"に",L"じつ",L"が"},std::vector<std::wstring>{L"ひ",L"び"},L"日"), //day/sun
            kanji(std::vector<std::wstring>{L"に"},std::vector<std::wstring>{L"ふた"},L"二"), //2
            kanji(std::vector<std::wstring>{L"か"},std::vector<std::wstring>{L"ひ"},L"火"), //fire
            kanji(std::vector<std::wstring>{L"ほん",L"ぼん"},std::vector<std::wstring>{L"もと"},L"本"), //book/root
            kanji(std::vector<std::wstring>{L"よう"},std::vector<std::wstring>{},L"曜"), //day of the week
            kanji(std::vector<std::wstring>{L"すい"},std::vector<std::wstring>{L"みず"},L"水"), //water
            kanji(std::vector<std::wstring>{L"もく"},std::vector<std::wstring>{L"き"},L"木"), //tree
            kanji(std::vector<std::wstring>{L"きん"},std::vector<std::wstring>{L"かね"},L"金"), //gold
            kanji(std::vector<std::wstring>{L"ど"},std::vector<std::wstring>{L"つち"},L"土"), //soil/earth
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"た"},L"田"), //rice field
            kanji(std::vector<std::wstring>{L"きょ",L"こん"},std::vector<std::wstring>{L"いま"},L"今"), //now
            kanji(std::vector<std::wstring>{L"しゅう"},std::vector<std::wstring>{},L"週"), //week
            kanji(std::vector<std::wstring>{L"まつ"},std::vector<std::wstring>{L"すえ"},L"末"), //end
            kanji(std::vector<std::wstring>{L"し"},std::vector<std::wstring>{L"よ",L"よん",L"よっ"},L"四"), //4
            kanji(std::vector<std::wstring>{L"し"},std::vector<std::wstring>{L"わたし"},L"私"), //I/me
            kanji(std::vector<std::wstring>{L"きゅう"},std::vector<std::wstring>{L"やす"},L"休"), //rest/day off
            kanji(std::vector<std::wstring>{L"きゅう",L"く"},std::vector<std::wstring>{L"ここの"},L"九"), //9
            kanji(std::vector<std::wstring>{L"ゆう"},std::vector<std::wstring>{L"とも"},L"友"), //friend
            kanji(std::vector<std::wstring>{L"じ"},std::vector<std::wstring>{L"とき"},L"時"), //hour
            kanji(std::vector<std::wstring>{L"かん"},std::vector<std::wstring>{L"あいだ"},L"間"), //interval
            kanji(std::vector<std::wstring>{L"ふん",L"ぷん"},std::vector<std::wstring>{},L"分"), //minute
            kanji(std::vector<std::wstring>{L"はん"},std::vector<std::wstring>{},L"半"), //half
            kanji(std::vector<std::wstring>{L"まい"},std::vector<std::wstring>{},L"毎"), //every
            kanji(std::vector<std::wstring>{L"ねん"},std::vector<std::wstring>{L"とし"},L"年"), //year
            kanji(std::vector<std::wstring>{L"ご"},std::vector<std::wstring>{},L"語"), //language
            kanji(std::vector<std::wstring>{L"ご"},std::vector<std::wstring>{L"いつ"},L"五"), //5
            kanji(std::vector<std::wstring>{L"ばん"},std::vector<std::wstring>{},L"番"), //number (as in number 1 meaning best)
            kanji(std::vector<std::wstring>{L"しん"},std::vector<std::wstring>{L"あたら"},L"新"), //new
            kanji(std::vector<std::wstring>{L"ほう"},std::vector<std::wstring>{L"かた"},L"方"), //direction
            kanji(std::vector<std::wstring>{L"ひゃく",L"びゃく",L"ぴゃく"},std::vector<std::wstring>{},L"百"), //100
            kanji(std::vector<std::wstring>{L"まん"},std::vector<std::wstring>{},L"万"), //10000
            kanji(std::vector<std::wstring>{L"ろく",L"ろっ"},std::vector<std::wstring>{L"むっ"},L"六"), //6
            kanji(std::vector<std::wstring>{L"しち",L"なな"},std::vector<std::wstring>{L"なな"},L"七"), //7
            kanji(std::vector<std::wstring>{L"はち",L"はっ"},std::vector<std::wstring>{L"やっ"},L"八"), //8
            kanji(std::vector<std::wstring>{L"じゅう",L"じゅっ"},std::vector<std::wstring>{L"とお"},L"十"), //10
            kanji(std::vector<std::wstring>{L"えん"},std::vector<std::wstring>{},L"円"), //dollars
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"なん",L"なに"},L"何"), //what
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"やす"},L"安"), //cheap
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"す"},L"好"), //like (adj)
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"ふる"},L"古"), //old
            kanji(std::vector<std::wstring>{},std::vector<std::wstring>{L"みせ"},L"店") //store
        };
};