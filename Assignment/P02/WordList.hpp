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
#pragma once
// neccessary Libraries
#include <iostream>
#include <string>
#include "termcolor.hpp"      //used to display colors
using namespace std;
/**
 * WordNode
 * 
 * Description:
 *      Node used to store the words from the dictionary into
 * 		the singly linked list
 * 
 * Public Methods:
 *            WordNode(string data)  // overloaded constructor
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     WordNode *temp = new Node(d) //creates and initilizes a new node 
 *      
 */
struct WordNode {
	string word;
	WordNode* next;
/**
 * Public: WordNode
 * 
 * Description:
 *     Constructor that recieves a string creates a new node 
 * 
 * Params:
 *      string	data
 * 
 * Returns:
 *      N/A
*/
	WordNode(string data) {
		next = nullptr;
		word = data;
	}
};
/**
 * WordsLL
 * 
 * Description:
 *      This is a Singly Linked List that will store a list of words that will be 
 * 		passed in from a file. This linked list will allow the user to print all the 
 * 		words stored in the list, remove words from the list, access data through
 * 		the use of indexes and display the first ten words in the list that begins with
 * 		a passed in substring.
 * 
 * Public Methods:   
 * 					WordsLL()
 * 		void		Print()
 * 		void		Backsert(string word)
 * 		void		Remove(string data)
 * 		int 		GetSize();
 * 		string&		operator[](int index)
 * 		void		Print_top_ten(string sub)
 * 
 * Private Methods:
 *      WordNode*	head;
 * 		WordNode*	tail;
 * 
 * Usage: 
 * 
 *      WordsLL	List1;		//create instance of list
 * 		List1.Backsert("Alleyway");		//Insert word into list
 * 		List1.Backsert("Ally");
 * 		List1.Remove("Alleyway");  // removes alleyway from the list
 * 		List1.Print();		//prints the entire list
 * 		cout << List1[0];	//displays the first item in the list
 * 		int size = List1.Getsize();	//gets the size if the list
 * 		List1.Print_top_ten("Al");  //displays the first 10 words in the list that begin with "Al"
 *      
 */
class WordsLL {
private:
	WordNode* head;		//the head of the list
	WordNode* tail;		//the tail of the list
public:
/**
 * Public: WordsLL
 * 
 * Description:
 *     Default constructor that sets head and tail nodes to NULL 
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
	WordsLL() {
		head = nullptr;
		tail = nullptr;
	}
/**
 * Public: Print
 * 
 * Description:
 *     Displays all words stored in the list
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
	void Print() {
		WordNode* traverse = head;   //setting traverse to the be the head of the list
		while (traverse) {
			cout << traverse->word << " ";
			traverse = traverse->next;
		}
	}
/**
 * Public: Backsert
 * 
 * Description:
 *     This method inserts word into the back of the linked list 
 * 
 * Params:
 *      string 		word
 * 
 * Returns:
 *      N/A
*/
	void Backsert(string word) {
		WordNode* temp = new WordNode(word); // creating new node with word
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
			temp->next = nullptr;
		}
	}
/**
 * Public: Remove
 * 
 * Description:
 *     This method will remove a passed word from the linked list
 * 
 * Params:
 *      string 		word
 * 
 * Returns:
 *      N/A
*/
	void Remove(string word) {
		if (head->word == word) {
			WordNode* temp = head;
			head = head->next;
			delete temp;
		}
		else if (tail->word == word) {
			WordNode* traverse = head;  //setting traverse node as the head of list
			while (traverse->next->next != nullptr) {
				traverse = traverse->next;
			}
			WordNode* temp = tail; // temperary node pointing to tail of list
			tail = traverse;
			tail->next = nullptr;
			delete temp;
		}
		else {
			WordNode* traverse = head;
			while (traverse->next->word != word && traverse->next != nullptr) {
				traverse = traverse->next;
			}
			WordNode* temp = traverse->next;
			traverse->next = traverse->next->next;
			delete temp;
		}
	}
/**
 * Public: Getsize
 * 
 * Description:
 *     This method will return the number of items stored in the list
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      int		: 	the number of items in the list 
*/
  int Getsize(){
    int count = 0;			// the number of words in the list
    WordNode* traverse = head; // traverse pointing to head of the list
    while(traverse){
      count++;
      traverse = traverse->next;
    }
    return count;
  }
/**
 * Public: operator[]
 * 
 * Description:
 *     overloaded operator that allows you to access data stored in the 
 * 		list using indexing similar to an array 
 * 
 * Params:
 *      int 	index
 * 
 * Returns:
 *      string&		: 	The address of where the string is stored  
*/
string& operator[](int index){
  WordNode* traverse = head; // pointer pointing to head of the list
  if(index > Getsize()){
    cout << "invalid index";
    return;
  }
  else{
    for(int i = 0; i!=index;i++){
      traverse = traverse->next;
    }
    return traverse->word;
  }
}
/**
 * Public: Print_top_ten
 * 
 * Description:
 *     This method will traverse the list looking for the first ten 
 * 		words that start with the substring passed into the function
 * 		and display those ten words with the substring section of the
 * 		word will be a different color
 * 
 * Params:
 *      string	 	sub
 * 
 * Returns:
 *     	N/A 
*/
void Print_top_ten(string sub){
  size_t found;		//holds the position of where the substring is found in the list
  int count =0;		// tracking the amount of words found
  WordNode* traverse = head;	// pointer pointing to head of list
  while (traverse && count < 10){
    found = traverse->word.find(sub);
    if(found!=string::npos){
      if(found == 0){
        for(int i = 0; i < traverse->word.length();i++){
          if(traverse->word[i]==sub[i]&& i < sub.length()){
            cout << termcolor::bright_red << traverse->word[i] << termcolor::reset;
          }else{
            cout << termcolor::red << traverse->word[i] << termcolor::reset;
          }
        }
        cout << " ";
        count++;
      }
    }
    traverse = traverse->next;
      }
}    
};
