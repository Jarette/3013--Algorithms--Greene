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
/**
 * LoadWords
 * 
 * Description:
 *     This function will be used to fill a instance of the WordsLL
 *    linked list with all the words found in a file.
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *     WordsLL  :   the linked list filled with words from text document
*/
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
/**
 * FindWords
 * 
 * Description:
 *     This function finds all words in a list that contains
 *    a substring and saves it to a new list.
 * 
 * Params:
 *      WordsLL   WordList
 *      string    sub
 * 
 * Returns:
 *     WordsLL    :   the list containing all the words containing the substring  
*/
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
  char k;       // the character entered by the user
  string word = "";   //the substring being searched
  WordsLL Words;    // the list containing all the words 
  WordsLL Matches;  //list containing all the words containing the substrng 
  Timer T;          //timer object that allows you to track effieciency

  // loading the list up with all the words from the input file
  Words = LoadWords();

  //asking the user to start entering the word they would like to search for
  cout << "Type the word you would like to search (letter by letter). Type capital Z to quit." << endl;
  // while statement checking if the user enters a capital Z and if so ends program 
  while ((k = getch()) != 'Z') {
    T.Start();
    // collects the characters typed by the user and concatinates them into one string
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
    // places all words that contain the substring created by the user into a list
    Matches = FindWords(Words, word);
    if ((int)k != 32) {
      T.End();
    // displaying all required data;
      cout << endl;
      cout << termcolor::blue << word << termcolor::reset << endl;
      cout << endl;
      cout << termcolor::bright_yellow << Matches.Getsize() << " words " << termcolor::reset;
      cout << "found in " << termcolor::bright_yellow << T.Seconds() << " seconds." << termcolor::reset << endl << endl;
      Matches.Print_top_ten(word);
      cout << endl << endl;
    }
  }
}