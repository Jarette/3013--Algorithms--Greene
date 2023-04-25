## P02 - Auto Complete in Linear Time 
### Jarette Greene
### Description:

   This Program will Perform a Look up similar to how the CTRL + F shortcut works on a file containing 100,000+
   words and displays the first 10 words in the list that uses the prefix entered by the user and all the other 
   matches found along with the time it took to find these words. This is a Brute Force look up algorithm that uses 
   a Linked List to store all the words and matches along. This program will be used to compare effciency of a Brute 
   force algorithm then later on build an alternative that will do the same thing more effciently 

### Files

|   #   | File             | Description                                        |
| :---: | ---------------  | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/main.cpp)| Main driver.|
|   2   | [WordList.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/WordList.hpp)|Linked List to store all words passed in from input file.|
|   3   | [mygetch.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/mygetch.hpp)|To obtain and display inputs from user in real time |
|   4   | [termcolor.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/termcolor.hpp)| allowing the console to display color|
|   5   | [Timer.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/timer.hpp)| Timer class used to track the time used to run functions|
|   6   | [dictionary.txt](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/dictionary.txt)|text file containing 100,000+ words|
|   7   | [Output.pdf](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/Output.pdf)|Output screen dump|


### Instructions
  
  - User enters one character at a time 
  - After entering 3 characters wait a brief moment for the program to search
  - the program displays all words that starts with the string entered by user
  - Use backspace to change the string entered by user

### Example Command:

      // accepting the user input and concatinating into a larger string 
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
      
       Matches = FindWords(Words, word); // finding and printing matches

