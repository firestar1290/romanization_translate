#include <string>
#include <map>
class kanji{ //FIXME: think of a different name
    public:
        void setStart(std::wstring); //string to translate, the input
        std::wstring getStart(); //return input string
        std::wstring getEnd(); //return output string
        void convert(); //signal input is finished and convert to kanji
    private:
        std::wstring end; //output
        std::wstring start; //input
        const std::multimap<std::wstring,std::wstring> hToOnMap{ //TODO: replace the value with kanji object instead of wstring | hiragana to On (next to other kanji) reading
            {L"だい",L"大"}, //big
            {L"がく",L"学"}, //study/learn
            {L"がっ",L"学"}, //study/learn
            {L"こう",L"校"}, //school
            {L"こう",L"高"}, //expensive
            {L"せん",L"先"}, //ahead
            {L"せん",L"千"}, //1000
            {L"せん",L"川"}, //river
            {L"せい",L"生"}, //life/to live
            {L"じん",L"人"}, //person
            {L"にん",L"人"},
            {L"ざん",L"山"}, //mountain
            {L"さん",L"山"}, //mountain
            {L"さん",L"三"}, //3
            {L"しょう",L"上"}, //above
            {L"しょう",L"小"}, //small
            {L"げ",L"下"}, //below
            {L"げつ",L"月"},
            {L"ちゅう",L"中"}, //middle/inside
            {L"にち",L"日"}, //sun/day, Sunday
            {L"に",L"日"},
            {L"に",L"二"}, //2
            {L"じつ",L"日"},
            {L"か",L"日"},
            {L"か",L"火"}, //fire, Tuesday
            {L"ほん",L"本"}, //root/book
            {L"ぽん",L"本"},
            {L"よう",L"曜"}, //Day of the week
            {L"がつ",L"月"}, //moon/month, Monday
            {L"すい",L"水"}, //water, Wednesday
            {L"もく",L"木"}, //tree, Thursday
            {L"きん",L"金"}, //gold/money/metal, Friday
            {L"ど",L"土"}, //earth/soil/ground, Saturday
            {L"きょ",L"今"}, //now
            {L"こん",L"今"},
            {L"しゅう",L"週"}, //week
            {L"まつ",L"末"},  //end
            {L"し",L"四"}, //4
            {L"し",L"私"}, //I/me
            {L"きゅう",L"休"}, //day off/holiday/to rest
            {L"きゅう",L"九"}, //9
            {L"ゆう",L"友"}, //friend
            {L"じ",L"時"}, //hour
            {L"かん",L"間"}, //interval
            {L"ふん",L"分"}, //minute
            {L"ぷん",L"分"},
            {L"はん",L"半"}, //half
            {L"まい",L"毎"}, //every
            {L"ねん",L"年"}, //year
            {L"ご",L"語"}, //language
            {L"ご",L"五"}, //5
            {L"いち",L"一"}, //1
            {L"いっ",L"一"},
            {L"ばん",L"番"}, //number (一番 = number one)
            {L"しん",L"新"}, //new
            {L"ほう",L"方"}, //direction?
            {L"ひゃく",L"百"}, //100
            {L"びゃく",L"百"},
            {L"ぴゃく",L"百"},
            {L"ぜん",L"千"},
            {L"まん",L"万"}, //10000
            {L"ろく",L"六"}, //6
            {L"ろっ",L"六"},
            {L"しち",L"七"}, //7
            {L"はち",L"八"}, //8
            {L"はっ",L"八"},
            {L"く",L"九"},
            {L"じゅう",L"十"}, //10
            {L"じゅっ",L"十"},
            {L"えん",L"円"} //yen (counter)
        };
        const std::multimap<std::wstring,std::wstring> hToKunMap{ //hiragana to Kun (by itself) reading
            {L"おお",L"大"}, //big
            {L"まな",L"学"}, //study/learn
            {L"さき",L"先"},
            {L"なま",L"生"},
            {L"ひと",L"人"}, //person
            {L"ひと",L"一"}, //one (usually used for counter)
            {L"やま",L"山"}, 
            {L"かわ",L"川"},
            {L"うえ",L"上"}, //above
            {L"した",L"下"}, //below
            {L"くだ",L"下"},
            {L"なか",L"中"}, //middle
            {L"た",L"田"},
            {L"ちい",L"小"},
            {L"ひ",L"日"}, //day/sun
            {L"ひ",L"火"}, //fire
            {L"び",L"日"},
            {L"もと",L"本"},
            {L"つき",L"月"},
            {L"みず",L"水"},
            {L"き",L"木"},
            {L"かね",L"金"},
            {L"つち",L"土"},
            {L"いま",L"今"},
            {L"すえ",L"末"},
            {L"わたし",L"私"},
            {L"やす",L"休"}, //day off
            {L"やす",L"安"}, //cheap
            {L"なん",L"何"}, //what
            {L"なに",L"何"},
            {L"す",L"好"}, //like
            {L"とも",L"友"},
            {L"とき",L"時"},
            {L"あいだ",L"間"},
            {L"とし",L"年"},
            {L"あたら",L"新"}, //new
            {L"ふる",L"古"},
            {L"たか",L"高"},
            {L"かた",L"方"},
            {L"ふた",L"二"},
            {L"みっ",L"三"},
            {L"よ",L"四"},
            {L"よん",L"四"},
            {L"よっ",L"四"},
            {L"いつ",L"五"},
            {L"むっ",L"六"},
            {L"なな",L"七"},
            {L"やっ",L"八"},
            {L"ここの",L"九"},
            {L"とお",L"十"},
            {L"みせ",L"店"} //store
        };
};