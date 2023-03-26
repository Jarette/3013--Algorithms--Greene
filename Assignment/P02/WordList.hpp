#pragma once
#include <iostream>
#include <string>
#include "termcolor.hpp"
using namespace std;
struct WordNode {
	string word;
	WordNode* next;
	WordNode(string data) {
		next = nullptr;
		word = data;
	}
};
class WordsLL {
private:
	WordNode* head;
	WordNode* tail;
public:
	WordsLL() {
		head = nullptr;
		tail = nullptr;
	}
	void Print() {
		WordNode* traverse = head;
		while (traverse) {
			cout << traverse->word << " ";
			traverse = traverse->next;
		}
	}
	void Backsert(string word) {
		WordNode* temp = new WordNode(word);
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
	void Remove(string word) {
		if (head->word == word) {
			WordNode* temp = head;
			head = head->next;
			delete temp;
		}
		else if (tail->word == word) {
			WordNode* traverse = head;
			while (traverse->next->next != nullptr) {
				traverse = traverse->next;
			}
			WordNode* temp = tail;
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
  int Getsize(){
    int count = 0;
    WordNode* traverse = head;
    while(traverse){
      count++;
      traverse = traverse->next;
    }
    return count;
  }
string& operator[](int index){
  WordNode* traverse = head;
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
void Print_top_ten(string sub){
  size_t found;
  int count =0;
  WordNode* traverse = head;
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
