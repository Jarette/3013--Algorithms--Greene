/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jkgreene0406@my.msutexas.edu / jarettegreene09@gmail.com
*  Label:            P03
*  Title:            Processing in Trie Tree Time
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*     This Program performs a look up similar to the look up in P02 but instead of storing 
*     and  searching a linked list the data is stored in a Trie Tree to improve the time 
*     taken to find matches. So this program will accept a json file of words and their definition
*     and store all the key words character by character into a Trie tree. Then as the user enter characters 
*     , in real time, after inserting 3 characaters the program will search the trie tree for all words 
*     that begins with string entered by the user. Then displays the first 10 matches, the number of total
*     matches and the amount of time taken by the program to find the matches 
*    
*  Usage:
*    - Hit run
*    - enter a character (ONLY LETTER CHARACTERS!!)
*    - enter 3 characters and wait for program to display result of searc
* 
*  Files:           
*        TrieTree.hpp		:	 Singly Linked List header file
*		     termcolor.hpp	:	 termcolor header file
*        timer.hpp      :  timer header file
*        mygetch.hpp    :  Getch header file
*        json.hpp       :  Json header file
*        main.cpp       :  main driver
*****************************************************************************/
// all header files
#include "TrieTree.hpp"
#include "json.hpp"
#include "mygetch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
//all neccesary libraries 
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
// allows for the use of json 
using json = nlohmann::json;
/**
 * Convert_to_seconds
 * 
 * Description:
 *     This function converts nano seconds into seconds 
 * 
 * Params:
 *      int     seconds 
 * 
 * Returns:
 *     double  :   the result of the conversion 
*/
double Convert_to_seconds(int seconds) { return seconds * pow(10, -9); }
// Main Driver
int main() {

  Trie Words;         // intitializing Trie Tree 
  Timer T;            // declaring timer
  char k;             // the character enetered by the user
  string word = "";   // the srting created by the user
  int matches;        // the number of words that start with the user entered string
  int nano;           // the nano seconds it took to find the matches
  ifstream f("dict_w_defs.json"); // opening json file
  json data = json::parse(f);     // json variable to access all items in the json file

  // for loop to collect all words and store them into the Trie tree
  for (auto &word : data.items()) {
    Words.insert(word.key());
  }
  // prompting the user to enter a character
  cout << "Type the word you would like to search (letter by letter) the "
          "search begins after the first three charcters are entered. Type "
          "capital Z to quit."
       << endl;
  // getting the user endered character
  while ((k = getch()) != 'Z') {
    T.Start(); // starting timer
    if ((int)k == 127) {
      if (word.size() > 0) {
        word = word.substr(0, word.size() - 1);
      }
    } else {
      if (!isalpha(k)) {  // checking to make sure the user entered character is a letter
        cout << "Letter only!" << endl;
        continue;
      }
      if ((int)k < 97) {
        k += 32;
      }
      word += k; // joining the user entered character into a string
    }
    // displaying the user entered string 
    cout << termcolor::blue << word << termcolor::reset << endl << endl;
    if (word.length() >= 3) {
      // finding all the words that start with the word the user and displaying the first ten
      matches = Words.Matches(word); 
      T.End(); // ending timer
      nano = T.NanoSeconds(); // getting the timer results in nanoseconds
      cout << endl;
      // displaying the number of matches 
      cout << termcolor::yellow << matches << termcolor::reset;
      cout << " Matches Found in ";
      // displaying the time in seconds
      cout << termcolor::yellow << Convert_to_seconds(nano)
           << termcolor ::reset;
      cout << " Seconds." << endl << endl;
    }
  }
}