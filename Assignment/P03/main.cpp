/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jkgreene0406@my.msutexas.edu / jarettegreene09@gmail.com
*  Label:            P02
*  Title:            AutoComplete in Linear Time
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This header file contains a Singly Linked List that will contain strings 
*		this list will hold all the words found in a dictionary text file containing
*		over 100,000+ words and will be able traverse the list to display the first
*		ten words that starts with the a passed in sub string into a function
* 
*  Usage:
*       - create instance of list 
*		- fill the list with words from file
*		- use Print_top_ten function to display matches
* 
*  Files:           
*        WordList.hpp		:	 Singly Linked List header file
*		 termcolor.hpp		:	 termcolor header file
*****************************************************************************/
#include "TrieTree.hpp"
#include "json.hpp"
#include "mygetch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
using json = nlohmann::json;
double Convert_to_seconds(int seconds) { return seconds * pow(10, -9); }
int main() {
  Trie Words;
  Timer T;
  char k;
  string word = "";
  int matches;
  int nano;
  ifstream f("dict_w_defs.json");
  json data = json::parse(f);
  for (auto &word : data.items()) {
    Words.insert(word.key());
  }
  cout << "Type the word you would like to search (letter by letter) the "
          "search begins after the first three charcters are entered. Type "
          "capital Z to quit."
       << endl;
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
    cout << termcolor::blue << word << termcolor::reset << endl << endl;
    if (word.length() >= 3) {
      matches = Words.Matches(word);
      T.End();
      nano = T.NanoSeconds();
      cout << endl;
      Words.Print_matches(word);
      cout << termcolor::yellow << matches << termcolor::reset;
      cout << " Matches Found in ";
      cout << termcolor::yellow << Convert_to_seconds(nano)
           << termcolor ::reset;
      cout << " Seconds." << endl << endl;
    }
  }
}