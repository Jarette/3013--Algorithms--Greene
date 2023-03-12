/*****************************************************************************
*                    
*  Author:           Jarette Greene
*  Email:            jkgreene0406@my.msutexas.edu / jarettegreene09@gmail.com
*  Label:            P01
*  Title:            Database Indexes... What?!? (not really)
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This Hpp file contains a singly linked list that will contain data 
*        read from a JSON file and will be able to traverse the list to find 
*       data based on varous different keys and determine how much nodes needed
*       
* 
*  Usage:
*      - create instance of list 
*      - insert json data into the list
*      - find data based the key data you want 
*      - find out how many nodes had to be checked before finding the data
* 
*  Files:           
*        Database.hpp     :        database header file
*        SLList.hpp       :        the singly linked list  
*****************************************************************************/
//necessary Libraries
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Database.hpp"
using namespace std;

struct ListNode {
  jsondata data;
  ListNode *next;
  ListNode(jsondata d) {
    next = nullptr;
    data.id = d.id;
    data.fname = d.fname;
    data.lname = d.lname;
    data.email = d.email;
    data.phone = d.phone;
    data.address = d.address;
    data.longitude = d.longitude;
    data.latitude = d.latitude;
    data.carmodel = d.carmodel;
    data.car = d.carmodel;
    data.carcolor = d.carcolor;
    data.jobtitle = d.jobtitle;
    data.pet = d.pet;
    data.city = d.city;
    data.state = d.state;
    for (int i = 0; i < d.stocks.size(); i++) {
      data.stocks.push_back(d.stocks[i]);
    }
  }
};
class LList {
private:
  ListNode *head;
  ListNode *tail;
  int nodeschecked;
public:
  LList() {
    head = NULL;
    tail = NULL;
  }
  void Print() {
    ListNode *traverse = head;
    while (traverse) {
      traverse->data.display();
      traverse = traverse->next;
    }
  }
  void Insert(jsondata d) {
    ListNode *temp = new ListNode(d);
    if (head == NULL) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = temp;
      temp->next= NULL;
    }
  }
  
  bool FindallID(int key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.id!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallFN(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.fname!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallLN(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.lname!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallEM(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.email!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallPH(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.phone!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallAD(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.address!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallLONG(double key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.longitude!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallLAT(double key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.latitude!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  bool FindallCM(string key) {
    ListNode *traverse = head;
    nodeschecked = 1;
    while (traverse) {
      if(traverse->data.carmodel!=key){
      nodeschecked++;
      traverse = traverse->next;
      }else{
        return true;
      }
    }
    nodeschecked = -1;
    return false;
  }
  void RemoveID(int key) {
    if (head->data.id == key) {
      ListNode *temp = head;
      head = head->next;
      delete temp;
    } else if (tail->data.id == key) {
      ListNode *traverse = head;
      while (traverse->next->next != NULL) {
        traverse = traverse->next;
      }
      ListNode *temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    } else {
      ListNode *traverse = head;
      while (traverse->next->data.id != key && traverse->next != NULL) {
        traverse = traverse->next;
      }
      ListNode *temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
 void RemoveFN(string key){
    if(head->data.fname == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.fname == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.fname != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
void RemoveLN(string key){
    if(head->data.lname == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.lname == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.lname != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
 void RemoveEM(string key){
    if(head->data.email == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.email == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.email != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
void RemovePH(string key){
    if(head->data.phone == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.phone == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.phone != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
 void RemoveAD(string key){
    if(head->data.address == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.address == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.address == key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
void RemoveLONG(double key){
    if(head->data.longitude == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.longitude == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.longitude != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
 void RemoveLAT(double key){
    if(head->data.latitude == key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.latitude == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.longitude != key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
void RemoveCM(string key){
    size_t found;
    if(head->data.carmodel== key){
      ListNode*temp = head;
      head = head->next;
      delete temp;
    }
    else if(tail->data.carmodel == key){
      ListNode*traverse = head;
      while (traverse->next->next!=NULL){
        traverse = traverse->next;
      }
      ListNode*temp = tail;
      tail = traverse;
      tail->next = NULL;
      delete temp;
    }
    else{
      ListNode*traverse= head;
      while(traverse->next->data.carmodel == key && traverse->next != NULL){
        traverse=traverse->next;
      }
      ListNode* temp = traverse->next;
      traverse->next = traverse->next->next;
      delete temp;
    }
  }
  int GetNodesChecked(){
    return nodeschecked;
  }
};