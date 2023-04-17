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
*     This Header file contains the implementation for a Trie Tree that is used
*     to create an auto complete search. This tree will take a word and store 
*     it into the tree character by charcater and marking where there is the end 
*     of a word. This Trie Tree will then allow for the user to enter a substring 
*     (Prefix) and then the tree would search for all words that begin with the prefix
*     and display the first ten matches and the total number of matches 
*    
*  Usage:
*     - Declare Trie Tree Object     
*     - pass a string into the insert method to fill the tree 
*     - pass substring into Matches method to search the tree for all strings that begin with the substring
* 
*  Files:           
*        TrieTree.hpp		:	 Singly Linked List header file
*		     termcolor.hpp	:	 termcolor header file
*        timer.hpp      :  timer header file
*        mygetch.hpp    :  Getch header file
*        json.hpp       :  Json header file
*        main.cpp       :  main driver
*****************************************************************************/
#include "termcolor.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct TrieNode {
  char data;
  bool end_of_word;
  map<char, TrieNode *> children;

  TrieNode() {
    data = 0;
    end_of_word = false;
    for (int i = 'a'; i <= 'z'; i++) {
      children[(char)i] = nullptr;
    }
  }
  TrieNode(char d) {
    data = d;
    end_of_word = false;
    for (int i = 'a'; i <= 'z'; i++) {
      children[(char)i] = nullptr;
    }
  }
};
class Trie {
private:
  TrieNode *root;
  void Trav(TrieNode *root, string sub, int &count, int trav_count, string temp) {
    if (root == nullptr) {
      return;
    }
    if (trav_count == 0) {
      trav_count++;
    } else {
      sub += root->data;
    }
    if (root->end_of_word) {
      if (count < 10) {
        for(int i = 0; i < sub.length();i++){
         if(sub[i] == temp[i] && i < temp.length()){
           cout << termcolor :: bright_red << sub[i] << termcolor :: reset;
         } else {
           cout << termcolor :: red << sub[i] << termcolor :: reset;
         }
        }
        cout << " ";
      }
      count++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
      Trav(root->children[(char)i], sub, count, trav_count,temp);
    }
  }
public:
  Trie() { root = new TrieNode(); }
  void insert(string key) {
    TrieNode *traverse = root;
    for (int i = 0; i < key.length(); i++) {
      if (traverse->children[key[i]] == nullptr) {
        traverse->children[key[i]] = new TrieNode(key[i]);
      }
      traverse = traverse->children[key[i]];
    }
    traverse->end_of_word = true;
  }

  int Matches(string sub) {
    int count = 0;
    int trav_count = 0;
    string temp = sub;
   TrieNode *traverse = root;
    for (int i = 0; i < sub.length(); i++) {
      if (!traverse->children[sub[i]]) {
        return 0;
      }
      traverse = traverse->children[sub[i]];
    }
    Trav(traverse, sub, count, trav_count, temp);
    return count;
  }
};