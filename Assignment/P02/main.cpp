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
*     This Program will perform a string look up on a dictionary containing 100,000 words.
*     This is done by using a singly linked list to store every string then with the use of 
*     mygetch to read the inputs in real time. Then after the first 3 characters are entered
*     the program searches every word in the list to locate all words that start with the string 
*     (Prefix) created by the user and displays the first ten words that begin with the prefix 
*     and the amount of matches found and the time it took the program to find these matches
* 
*  Usage:
*    - Hit run
*    - enter a character (ONLY LETTER CHARACTERS!!)
-    - enter 3 characters and wait for program to display result of searcg
* 
*  Files:           
*        WordList.hpp		:	 Singly Linked List header file
*		     termcolor.hpp	:	 termcolor header file
*        timer.hpp      :  timer header file
*        mygetch.hpp    :  Getch header file
*        main.cpp       :  main driver
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
 *    a substring and saves it to a new list and displays the first
 *    10 matches found
 * 
 * Params:
 *      WordsLL   WordList
 *      string    sub
 * 
 * Returns:
 *     WordsLL    :   the list containing all the words containing the substring  
*/
WordsLL FindWords(WordsLL WordList, string sub) {
  WordsLL match; //list containing all matches 
  size_t found;  //position of substring in the word
  int count = 0; //count to find the first ten matches
  for (int i = 0; i < WordList.Getsize(); i++) {
    found = WordList[i].find(sub); //loactes position of substring in word
    if (found == 0) {
      match.Backsert(WordList[i]); //adds to the matches list
      if (count < 10) {
        // displaying the first 10 matches and highlighting the substring within the matched word
        for (int j = 0; j < WordList[i].length(); j++) {
          if(WordList[i][j] == sub[j]&&j<sub.length()){
            cout << termcolor::bright_red << WordList[i][j] << termcolor::reset;
          }else{
            cout << termcolor::red << WordList[i][j] << termcolor::reset;
          }
        }
        cout << " ";
        count++;
      }
    }
  }
  return match;
}

int main() {
  char k;  // character entered by user 
  string word = ""; // the substring being searched for
  WordsLL Words;  // Linked list containing all the words
  WordsLL Matches; // linked list containing matches 
  Timer T; // Timer variable to check how long a function takes to drun 
  double Seconds; // the time
  Words = LoadWords();
  cout << "Type the word you would like to search (letter by letter) the search begins after the first three charcters are entered. Type capital Z to quit."
       << endl;
  while ((k = getch()) != 'Z') { // accepting user input
    T.Start();
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      if (!isalpha(k)) { // making sure the character entered is a letter
        cout << "Letter only!" << endl;
        continue;
      }
      if ((int)k < 97) {
        k += 32;
      }
      word += k; // putting all the user entered characters into a string
    }
    // displaying the user entered string 
    cout << termcolor::blue << word << termcolor::reset << endl << endl;
    if (word.length() >= 3) { //making sure the substring is atleast 3 characters long
      Matches = FindWords(Words, word); // finding and printing matches
      cout << endl << endl;
      T.End();
      // displaying total matches
      cout << termcolor::bright_yellow << Matches.Getsize() << termcolor::reset;
      cout << " Matches Found in ";
      // displaying the time it took to find all those matches 
      cout << termcolor::bright_yellow << T.Seconds() << termcolor::reset;
      cout << " Seconds";
      cout << endl << endl;
    }
  }
}