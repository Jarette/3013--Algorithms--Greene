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
/**
 * ListNode
 * 
 * Description:
 *      This is a node that contains a next pointer and all the data taken from a
 *      json file.
 * 
 * Public Methods:
 *            ListNode(jsondata d)   //overloaded constructor for node
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     ListNode(jsondata d)  //passes jsondata into a node
 *     
 *      
 */
struct ListNode {
  jsondata data;    //the data that is being stored in the node 
  ListNode *next;   // the location of the next node in the list 
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
/**
 * LList
 * 
 * Description:
 *      A singly list that containing data collected from a json file 
 * 
 * Public Methods:
 *      void      Print()
 *      void      Insert(jsondata d)
 *      bool      FindallID(int key)
 *      bool      FindallFN(string key)
 *      bool      FindallLN(string key)
 *      bool      FindallEM(string key)
 *      bool      FindallPH(string key)
 *      bool      FindallAD(string key)
 *      bool      FindallLONG(double key)
 *      bool      FindallLAT(double key)
 *      bool      FindallCM(string key)
 *      void      RemoveID(int key)
 *      void      RemoveFN(string key)
 *      void      RemoveLN(string key)
 *      void      RemoveEM(string key)
 *      void      RemovePH(string key)
 *      void      RemoveAD(string key)
 *      void      RemoveLONG(double key)
 *      void      RemoveLAT(double key)
 *      void      RemoveCM(string key)
 *      int       GetNodesChecked()
 * 
 * Private Methods:
 *    
 *       N/A
 * 
 * Usage: 
 * 
 *     LList Test;  //creating intance of list
 *     Test.Insert(data) //adds data to the list
 *     Test.FindallID(1) // returns 1 or 0 if the ID# 1 is found in the list
 *     Test.GetNodesChecked() //returns the amount of nodeds checked to find ID#1
 *     Test.Print() //displays all the data stored in the list 
 *     
 *      
 */
class LList {
private:
  ListNode *head;     //the beginning of the list
  ListNode *tail;     // the end of the list
  int nodeschecked;   // stores the amount of nodes checeked to find a piece of data
public:
/**
 * Public: LList
 * 
 * Description:
 *     Default Constructor
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
  LList() {
    head = NULL;
    tail = NULL;
  }
/**
 * Public: Print
 * 
 * Description:
 *     displays all the data in the list
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
  void Print() {
    ListNode *traverse = head;
    while (traverse) {
      traverse->data.display();
      traverse = traverse->next;
    }
  }
/**
 * Public: Insert
 * 
 * Description:
 *     Inserts data into the back of the list
 * 
 * Params:
 *      jsondata    d // the data being stored into the list 
 * 
 * Returns:
 *      N/A
*/
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
/**
 * Public: FindallID
 * 
 * Description:
 *     Produces a true or false based on if the ID passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      int    key  // the id to be searched 
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallFN
 * 
 * Description:
 *     Produces a true or false based on if the first name passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallLN
 * 
 * Description:
 *     Produces a true or false based on if the last name passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallEM
 * 
 * Description:
 *     Produces a true or false based on if the email passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallPH
 * 
 * Description:
 *     Produces a true or false based on if the phone number passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallAD
 * 
 * Description:
 *     Produces a true or false based on if the address passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallLONG
 * 
 * Description:
 *     Produces a true or false based on if the Longitude passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      double    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallLAT
 * 
 * Description:
 *     Produces a true or false based on if the Latitude passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      double    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
/**
 * Public: FindallCM
 * 
 * Description:
 *     Produces a true or false based on if the Car model passed
 *     is located in the list and also count all the nodes 
 *     that had to be checked to find the node
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      bool   : true or false (1 or 0)
*/
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
  /**
 * Public: RemoveID
 * 
 * Description:
 *     Searches the list for the passed ID and removes the item from the list
 * 
 * Params:
 *      int    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveFN
 * 
 * Description:
 *     Searches the list for the passed first name and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveLN
 * 
 * Description:
 *     Searches the list for the passed last name and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveEM
 * 
 * Description:
 *     Searches the list for the passed email and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemovePH
 * 
 * Description:
 *     Searches the list for the passed Phone number and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveAD
 * 
 * Description:
 *     Searches the list for the passed Address and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveLONG
 * 
 * Description:
 *     Searches the list for the passed longitude and removes the item from the list
 * 
 * Params:
 *      double    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveLAT
 * 
 * Description:
 *     Searches the list for the passed latitude and removes the item from the list
 * 
 * Params:
 *      double    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: RemoveCM
 * 
 * Description:
 *     Searches the list for the passed car model and removes the item from the list
 * 
 * Params:
 *      string    key  
 * 
 * Returns:
 *      N/A
*/
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
  /**
 * Public: GetNodesChecked
 * 
 * Description:
 *     returns the amount of nodes checked when searching for 
 *     the last data being searched for.
 * 
 * Params:
 *      double    key  
 * 
 * Returns:
 *      N/A
*/
  int GetNodesChecked(){
    return nodeschecked;
  }
};