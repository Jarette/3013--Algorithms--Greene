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
*****************************************************************************/
// neccesary header file
#include "termcolor.hpp"
// neccesary Libraries
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * TrieNode
 * 
 * Description:
 *      Node that is used to store the data within the Trie tree and pointers 
 *      to all neccesary nodes
 * 
 * Public Methods:
 *            TrieNode()  // default constructor
 *            Trienode(char data)  // overloaded constructor
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     TrieNode *temp = new Node(d) //creates and initilizes a new node
 *     
 *      
 */
struct TrieNode {
  char data;   //character from the string that is being entered into the tree 
  bool end_of_word;  // boolean to mark if a character is the end of a word
  map<char, TrieNode *> children;  // map of node pointers 
/**
 * Public: TrieNode
 * 
 * Description:
 *     Default constructor
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
  TrieNode() {
    data = 0;
    end_of_word = false;
    // creating a node pointer for every letter in the alphabet 
    for (int i = 'a'; i <= 'z'; i++) {
      children[(char)i] = nullptr;
    }
  }
/**
 * Public: TrieNode
 * 
 * Description:
 *     Overloaded constructor
 * 
 * Params:
 *      char	data
 * 
 * Returns:
 *      N/A
*/
  TrieNode(char d) {
    data = d;
    end_of_word = false;
// creating a node pointer for every letter in the alphabet 
    for (int i = 'a'; i <= 'z'; i++) {
      children[(char)i] = nullptr;
    }
  }
};
/**
 * Trie
 * 
 * Description:
 *     This class contains the implementation for a Trie Tree. This Trie tree
 *     will accept will accept a string and insert each character into the string 
 *    into the tree by creating nodes based on the character. Then the Tree will allow the 
 *    the user to enter in a string and it will traverse the tree to find all words that 
 *    start with the string passed in and also displaying the first ten matches.
 * 
 * Public Methods:   
 * 		      Trie() 
 *    void  insert(string key) 
 *    int   Matches(string sub)
 * 
 * Private Methods:
 *          TrieNode *root
 *    void  Trav(TrieNode *root, string sub, int &count, int trav_count, string temp)
 * 
 * Usage: 
 * 
 *     Trie TrieTree;
 *      TrieTree.insert("steel"); //inserts the word "steel" into the tree
 *     int matches = TrieTree.Matches("ste");// will search the tree for all words that starts with "ste" 
 *                                          // and return the total number of matches and also the display the first 10 matches
 *      
 */
class Trie {
private:
  TrieNode *root; // the root of the trie tree
/**
 * Private: Trav
 * 
 * Description:
 *     This Method will traverse the entire tree under the root that 
 *     location that has been passed in
 * 
 * Params:
 *      TrieNode  *root
 *      string    sub
 *      int       &count
 *      int       trav_count
 *      string    temp
 * 
 * Returns:
 *      N/A
*/
  void Trav(TrieNode *root, string sub, int &count, int trav_count, string temp) {
    if (root == nullptr) { // base case
      return;
    }
    if (trav_count == 0) { // to check if this is the first recursive call
      trav_count++;
    } else {
      sub += root->data; // recreatingt he words 
    }
    if (root->end_of_word) { // checking if the position the traverse is at is the end of a word
      if (count < 10) { //checking if they have found ten matches
      // displaying the matching words
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
      // performing recursive call 
      Trav(root->children[(char)i], sub, count, trav_count,temp);
    }
  }
public:
/**
 * Public: Trie
 * 
 * Description:
 *     Default constructor 
 * 
 * Params:
 *     N/A
 * 
 * Returns:
 *      N/A
*/
  Trie() { root = new TrieNode(); }
/**
 * Public: insert
 * 
 * Description:
 *     This method inserts a past in string into the trie tree and marks where 
 *    the end of the word is located 
 * 
 * Params:
 *     string   key
 * 
 * Returns:
 *      N/A
*/
  void insert(string key) {
    TrieNode *traverse = root; //setting the traverse pointer to the rood 
    for (int i = 0; i < key.length(); i++) {
      // checking if the child node is empty if so fill the node
      if (traverse->children[key[i]] == nullptr) {
        traverse->children[key[i]] = new TrieNode(key[i]);
      }
      //moving to available node that matches the letter in the passed in string 
      traverse = traverse->children[key[i]];
    }
    // marking the end of a word 
    traverse->end_of_word = true;
  }
/**
 * Public: Matches 
 * 
 * Description:
 *    This method traverses the tree to find all words that start with a 
 *    passed in string (prefix) and displays the first ten matches and returns
 *    the total number of matches foudn within the tree
 * 
 * Params:
 *     string   sub
 * 
 * Returns:
 *      int   :  the total number of matches
*/
  int Matches(string sub) {
    int count = 0;  // the number of matches
    int trav_count = 0; // to check the number of traversals in the recursive function  
    string temp = sub;  // the prefix copied to a temp variable
   TrieNode *traverse = root; // traverse pointer
   
   // traverseing until the end of the prefix
    for (int i = 0; i < sub.length(); i++) {
      if (!traverse->children[sub[i]]) {
        return 0;
      }
      traverse = traverse->children[sub[i]];
    }
    // traverse function to find all matching words based on the preix
    Trav(traverse, sub, count, trav_count, temp);
    return count; // the total matching words count
  }
};