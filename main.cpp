#include <iostream>

#include <vector>
#include "Language.h"

void printLanguages(std::vector<Language> vector);

int main() {
    std::vector<Language> vector;

    vector.emplace_back();
    vector.emplace_back("Markedonski", 50000, 1, 123000);
    vector.emplace_back("Java", 100, 1, 2000000);
    vector.emplace_back("English", 100000, 2, 123000);
    vector.emplace_back("French", 565656, 3, 20000);
    vector.emplace_back("Spanish", 66666666, 4, 100500);
    vector.emplace_back("Test", 50444000, 4, 100500);
    vector.emplace_back("Ve krest krest", 5054000, 5, 2);
    vector.emplace_back("Python", 566640000, 1, 0);
    vector.emplace_back("Slavyanskaya gramota", 100000, 4, 0);
    vector.emplace_back("Ieroglifi peschernii", 256, 2, 0);
    vector.emplace_back("name", 1122211, 3, 0);

    // Display to screen
    std::cout << vector[0] << std::endl;

    // Modification
    vector[0].setName("Random");
    vector[0].setHardness(2);
    vector[0].setNativeSpeakers(150000);
    vector[0].setWordsAmount(150000);
    std::cout << vector[0] << std::endl;

    std::cout << std::endl << "Dead languages by words" << std::endl;
    printLanguages(Language::getDeadSortedByWords(vector));

    std::cout << "Average natives: " << Language::getAverageNatives(vector) << std::endl;

    std::cout << "Average words for easiest language: "
              << Language::getAverageWords(vector, 1) << std::endl;
}

void printLanguages(std::vector<Language> vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << (i == vector.size() - 1 ? "." : ",") << std::endl;
    }
}
