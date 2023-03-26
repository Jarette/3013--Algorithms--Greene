#include "WordList.hpp"
#include "mygetch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define RED termcolor::red

WordsLL LoadWords() {
  ifstream infile;
  WordsLL words;
  string word;
  infile.open("dictionary.txt");
  infile >> word; 
  while (!infile.eof()) {
    for (auto &c : word) {
      c = tolower(c);
    }
    words.Backsert(word);
    infile >> word;
  }
  for (auto &c : word) {
    c = tolower(c);
  }
  words.Backsert(word);
  return words;
}
WordsLL FindWords(WordsLL WordList, string sub) {
  WordsLL match;
  size_t found;
  for (int i = 0; i < WordList.Getsize(); i++) {
    found = WordList[i].find(sub);
    if (found != string::npos) {
        match.Backsert(WordList[i]);
    }
  }
  return match;
}

int main() {
  char k;
  string word = "";
  WordsLL Words;
  WordsLL Matches;
  string WordTemp;
  Timer T;
  Words = LoadWords();
  cout << "Type the word you would like to search (letter by letter). Type capital Z to quit." << endl;
  while ((k = getch()) != 'Z') {
    T.Start();
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      if (!isalpha(k)) {
        cout << "Letter only!" << endl;
        continue;
      }
      if ((int)k < 97) {
        k += 32;
      }
      word += k;
    }
    Matches = FindWords(Words, word);
    if ((int)k != 32) {
      T.End();
      cout << endl;
      cout << termcolor::blue << word << termcolor::reset << endl;
      cout << endl;
      cout << termcolor::bright_yellow << Matches.Getsize() << " words " << termcolor::reset;
      cout << "found in " << termcolor::bright_yellow << T.Seconds() << " seconds." << termcolor::reset << endl << endl;
      Matches.Print_top_ten(word);
      cout << endl;
    }
  }
}