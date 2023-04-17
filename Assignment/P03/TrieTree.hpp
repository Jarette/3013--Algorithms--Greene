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
  vector<string> matches;
  void Trav(TrieNode *root, string sub, int &count, int trav_count) {
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
        matches.push_back(sub);
      }
      count++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
      Trav(root->children[(char)i], sub, count, trav_count);
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
    matches.clear();
   TrieNode *traverse = root;
    for (int i = 0; i < sub.length(); i++) {
      if (!traverse->children[sub[i]]) {
        return 0;
      }
      traverse = traverse->children[sub[i]];
    }
    Trav(traverse, sub, count, trav_count);
    return count;
  }
  void Print_matches(string sub) {
    for (int i = 0; i < matches.size(); i++) {
      for(int j = 0; j < matches[i].length(); j++){
        if(matches[i][j] == sub[j]&&j<sub.length()){
          cout << termcolor::bright_red << matches[i][j] << termcolor::reset;
        }else{
          cout << termcolor::red << matches[i][j] << termcolor::reset;
        }
      }
      cout << " ";
    }
    cout << endl;
  }
};