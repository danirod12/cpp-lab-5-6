#include <sstream>
#include <utility>
#include "Language.h"

// Constructors

Language::Language() {
    this->name = "Not declared";
    this->hardness = 1;
    this->nativeSpeakers = 0;
    this->wordsAmount = 0;
}

Language::Language(const Language &language) {
    this->name = language.name;
    this->hardness = language.hardness;
    this->nativeSpeakers = language.nativeSpeakers;
    this->wordsAmount = language.wordsAmount;
}

Language::Language(std::string name, unsigned int wordsAmount, short hardness, unsigned int nativeSpeakers) {
    this->name = std::move(name);
    this->wordsAmount = wordsAmount;
    this->hardness = hardness;
    this->nativeSpeakers = nativeSpeakers;
}

Language::~Language() = default;

// Getters

short Language::getHardness() const {
    return hardness;
}

unsigned int Language::getNativeSpeakers() const {
    return nativeSpeakers;
}

const std::string &Language::getName() const {
    return name;
}

unsigned int Language::getWordsAmount() const {
    return wordsAmount;
}

// Setters

void Language::setName(const std::string &name) {
    Language::name = name;
}

void Language::setWordsAmount(unsigned int wordsAmount) {
    Language::wordsAmount = wordsAmount;
}

void Language::setHardness(short hardness) {
    Language::hardness = hardness;
}

void Language::setNativeSpeakers(unsigned int nativeSpeakers) {
    Language::nativeSpeakers = nativeSpeakers;
}

std::vector<Language> Language::getDeadSortedByWords(std::vector<Language> &languages) {
    std::vector<Language> vector;
    // filter by predicate "language is dead"
    for (const Language &item: languages) {
        if (item.getNativeSpeakers() == 0) {
            vector.push_back(item);
        }
    }

    // sort by comparator "words amount"
    bool modified;
    do {
        modified = false;
        for (int i = 0; i < vector.size() - 1; ++i) {
            if (vector[i].wordsAmount < vector[i + 1].wordsAmount) {
                std::swap(vector[i], vector[i + 1]);
                modified = true;
            }
        }
    } while (modified);
    return vector;
}

unsigned int Language::getAverageNatives(std::vector<Language> &languages) {
    if (languages.empty()) {
        return 0;
    }

    int amount = 0;
    unsigned long natives = 0;
    for (const Language &item: languages) {
        natives += item.getNativeSpeakers();
        amount++;
    }
    return (int) (natives / amount);
}

unsigned int Language::getAverageWords(std::vector<Language> &languages, int hardness) {
    int amount = 0;
    unsigned long words = 0;
    for (const Language &item: languages) {
        if (item.getHardness() != hardness) {
            continue;
        }
        words += item.getWordsAmount();
        amount++;
    }
    return amount == 0 ? 0 : (int) (words / amount);
}

// System

std::ostream &operator<<(std::ostream &outStream, const Language &language) {
    outStream << "(name: " << language.name << ", words: " << language.wordsAmount
            << ", hardness: " << language.hardness << ", speakers: " << language.nativeSpeakers << ")";
    return outStream;
}
