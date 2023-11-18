#ifndef CPP_LAB_5_6_LANGUAGE_H
#define CPP_LAB_5_6_LANGUAGE_H


#include <string>
#include <vector>

class Language {
private:
    std::string name;

    // https://blog.rosettastone.com/which-language-has-the-most-words/
    unsigned int wordsAmount;

    // 1 - easy, 5 - hard
    short hardness;

    // https://www.visualcapitalist.com/100-most-spoken-languages/
    unsigned int nativeSpeakers;

public:
    // Constructors & destructors

    Language();

    Language(std::string name, unsigned int wordsAmount, short hardness, unsigned int nativeSpeakers);

    Language(Language const &language);

    ~Language();

    // Static

    static std::vector<Language> getDeadSortedByWords(std::vector<Language> &languages);

    static unsigned int getAverageNatives(std::vector<Language> &languages);

    static unsigned int getAverageWords(std::vector<Language> &languages, int hardness);

    // Getters

    const std::string &getName() const;

    unsigned int getWordsAmount() const;

    short getHardness() const;

    unsigned int getNativeSpeakers() const;

    // Setters

    void setName(const std::string &name);

    void setWordsAmount(unsigned int wordsAmount);

    void setHardness(short hardness);

    void setNativeSpeakers(unsigned int nativeSpeakers);

    // System

    friend std::ostream &operator<<(std::ostream &stream, const Language &language);
};


#endif //CPP_LAB_5_6_LANGUAGE_H
