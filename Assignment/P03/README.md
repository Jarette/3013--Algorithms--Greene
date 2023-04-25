## P03 - Auto Complete in Linear Time 
### Jarette Greene
### Description:

This Program performs a look up similar to the look up in P02 but instead of storing 
and  searching a linked list the data is stored in a Trie Tree to improve the time 
taken to find matches. So this program will accept a json file of words and their definition
and store all the key words character by character into a Trie tree. Then as the user enter characters 
, in real time, after inserting 3 characaters the program will search the trie tree for all words 
that begins with string entered by the user. Then displays the first 10 matches, the number of total
matches and the amount of time taken by the program to find the matches 

### Files

|   #   | File             | Description                                        |
| :---: | ---------------  | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/main.cpp)| Main driver.|
|   2   | [dict_w_defs.json](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/dict_w_defs.json)|json file containing words and their definition|
|   3   | [mygetch.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/mygetch.hpp)|To obtain and display inputs from user in real time |
|   4   | [termcolor.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/termcolor.hpp)| allowing the console to display color|
|   5   | [Timer.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/timer.hpp)| Timer class used to track the time used to run functions|
|   6   | [TrieTree.hpp](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P02/TrieTree.hpp)|Trie Tree Implementation|
|   7   | [Trie Tree Output.pdf](https://github.com/Jarette/3013--Algorithms--Greene/blob/main/Assignment/P03/Trie%20Tree%20Output.pdf)|Output file containing screen dump.|

### Instructions
  
  - User enters one character at a time 
  - After entering 3 characters wait a brief moment for the program to search
  - the program displays all words that starts with the string entered by user
  - Use backspace to change the string entered by user

### Example Command:

        // getting the user entered character
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

