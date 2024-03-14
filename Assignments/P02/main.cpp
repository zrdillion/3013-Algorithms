/*****************************************************************************
*                    
*  Author:           Zach Dillion
*  Email:            zrdillion0327@my.msutexas.edu
*  Label:            P02
*  Title:            Linear Search
*  Course:           CMPS 3013
*  Semester:         Spring 2024
* 
*  Description:
*        This program loads a json file into a json object, it then uses a getch
*        function to get a character from the console and adds it to a string
*        it then uses a linear search to find the string in the json object.
*        Once the user has input a full word and pressed enter it will output
*        the definition of the word.
* 
*  Usage:
*        - enter in letters to find a word in the json file
*        - press enter to find the definition of the word
* 
*  Files:           
*        - main.cpp  :driver program
*        - loadJsonEx.hpp :header file for loadJsonFile function
*        - json.hpp :header file for json class
*        - rang.hpp :header file for modifying text printed to the console
*        - console.hpp :header file to determine which libraries to use base on OS
*                       also contains the getch function
*        - dictionary.json :json file containing the words and definitions
*****************************************************************************/

#include "./headers/animals.hpp"
#include "./headers/console.hpp"
#include "./headers/json.hpp"
#include "./headers/rang.hpp"
#include "loadJsonEx.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace rang;
using json = nlohmann::json;

consoleSize console_size; // used to store the size of console (width=cols and
                          // height=rows)

/**
 * partialMatch
 *
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 *
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
vector<string> partialMatch(vector<string> array, string substring) {
  vector<string> matches; // to hold any matches
  size_t found;           // size_t is an integer position of
                          // found item. -1 if its not found.

  if (substring.size() == 0) {
    return matches;
  }

  for (int i = 0; i < array.size(); i++) { // loop through array
    found = array[i].find(substring);      // check for substr match
    if (found != string::npos) {           // if found >= 0 (its found then)
      matches.push_back(array[i]);         // add to matches
    }
  }

  return matches;
}

/**
* Prints a long background row of gray, with text centered.
* Not a good function since colors are hard coded, but using
* rang, I don't want to invest the time to figuere out how to
* interact with rang's enumerated class types and ostream.
* I guess you could add a switch statement to change background
* color:
* switch(color){
  "black" : cout<<bgB::black;
            break;
  "red" : cout<<bgB::red;
          break;
  ...
  ...
  ...
}
But still not a good solution.
*/
void titleBar(string title, int length = console_size.width) {
  string padding = string((length / 2) - (title.size() / 2), ' ');
  title = padding + title + padding;
  cout << bgB::black << fg::gray << title << fg::reset << bg::reset << endl;
}

/**
 * horizontalBar
 *
 * Description:
 *      Prints a horizontal bar of a given length
 * Params:
 *      int length - length of the bar
 * Returns:
 *      void
 */
void horizontalBar(int length = console_size.width) {
  string line = string(length, '_');
  cout << fg::gray << line << fg::reset << bg::reset << endl;
}

/**
 * printMatches
 *
 * Description:
 *      Prints the matches to the screen.
 * Params:
 *      vector<string> matches - vector of matches
 * Returns:
 *      void
 */
void printMenu(vector<string> options) {
  int i = 1;
  for (auto s : options) {
    cout << fg::black << style::bold << i << ". " << style::reset << fg::cyan
         << s << fg::reset << bg::reset << endl;
    i++;
  }
  cout << fg::reset << bg::reset;
}

/**
 * printHighlightedSubstr
 *
 * Description:
 *      Given a word, print the substr underlined and red vs blue for the rest
 * of the word.
 * Params:
 *      string word - word to print
 *      string substr - substring to highlight in red
 *      int loc - location of substr in word
 * Returns:
 *      void
 */
void printHighlightedSubstr(string word, string substr, int loc) {
  for (int j = 0; j < word.size(); j++) {
    // if we are printing the substring turn it red
    if (j >= loc && j <= loc + substr.size() - 1) {
      cout << fg::red << style::underline << word[j] << fg::blue
           << style::reset;
    } else {
      cout << fg::blue << word[j] << fg::reset << style::reset;
    }
  }
}

/**
 * printCurrent
 *
 * Description:
 *      Prints the current key pressed and the current substr to the screen.
 * Params:
 *      char k - last character pressed.
 *      string word - current substring being printed.
 * Returns:
 *      void
 */
void printCurrent(char k, string word) {
  cout << fg::green << style::bold << "KeyPressed: \t\t" << style::reset
       << fgB::yellow;
  if (int(k) == 127) {
    cout << "del";
  } else {
    cout << k;
  }
  cout << " = " << (int)k << fg::reset << endl;
  cout << fg::green << style::bold << "Current Substr: \t" << fg::reset
       << fgB::blue << word << fg::reset << style::reset << endl;
  cout << endl;
}

/**
 * errorMessage
 *
 * Description:
 *      Prints an error message to the screen.
 * Params:
 *      string message - message to print
 * Returns:
 *      void
 */
void errorMessage(string message) {
  cout << bgB::red << fgB::gray << message << fg::reset << bg::reset << endl;
  sleep(1);
}


/**
* iterateJson
* Description:
*      Iterates through the json object, printing the first ten matches
*      to the screen and the total number of matches
* Params:
*      json myJson - json object to iterate through
*      string partialKey - key to search for
* Returns:
*      void
*/
void iterateJson(json myJson, string partialKey) {
  int i = 0, numMatches = 0;
  cout << fg::green << style::bold << "Partial String: " << style::reset 
       << fg::magenta << partialKey << endl << style::reset;

  cout << fg::green << style::bold << "Words: " << style::reset;
  
  for (auto &element : myJson.items()) {
      string key = element.key();
    
      // Check if the key contains the partialKey substring
      if (key.find(partialKey) != string::npos) {
          // Found a match, do something with it
        numMatches++;
        if (i < 10) {
          cout << fg::blue << key << " " << style::reset;
          i++;
        }
      }
  }
  cout << endl << fg::green << style::bold << "MATCHES: " 
    << fg::red << numMatches << endl << style::reset;
}

/**
* giveDefinition
*
* Description:
*      Iterates through the json object to find the word that matches
*      the users input and prints the definition to the screen
* Params:
*      string word - word to search for
*      json myJson - json object to iterate through
* Returns:
*      void
*/
void giveDefinition(string word, json myjson)
{
  string definition = "";
  for (auto& element : myjson.items()) {
    string key = element.key();

    if (key == word)
      definition = element.value();
    
  }

  cout << fg::green << style::bold << "Definition: " << endl 
       << fg::blue << definition << style::reset;
}

int main() {
  console_size = getConsoleSize(); // get width and height of console
  char k;                          // holder for character being typed
  string key;                      // string version of char for printing
  string substr = "";              // var to concatenate letters to
  vector<string> matches; // any matches found in vector of animals
  //int loc;                // location of substring to change its color
  bool deleting = false;
  vector<string> mainMenu;
  json j = loadJsonFile("./data/dictionary.json"); // loading the dictionary json file
                                                   // into a json object
  
  mainMenu.push_back("Type letters and watch the results change.");
  mainMenu.push_back(
      "Hit the DEL key to erase a letter from your search string.");
  mainMenu.push_back(
      "When a single word is found, hit enter.");

  clearConsole();
  titleBar("Getch Example", console_size.width);
  printMenu(mainMenu);

  //continues looping as long as the user doesn't input enter
  while ((k = getch()) != 10) {

    clearConsole();
    titleBar("Dictionary Lookup", console_size.width);
    printMenu(mainMenu);

    // Tests for a backspace and if pressed deletes
    // last letter from "substr".
    if ((int)k == 127) {
      if (substr.size() > 0) {
        substr = substr.substr(0, substr.size() - 1);
        deleting = true;
      }
    } else {
      deleting = false;
      // Make sure a letter was pressed and only letter
      if (!isalpha(k)) {
        errorMessage("Letters only!");
        continue;
      }

      // We know its a letter, lets make sure its lowercase.
      // Any letter with ascii value < 97 is capital so we
      // lower it.
      if ((int)k < 97) {
        k += 32;
      }
      substr += k; // append char to substr
    }
    horizontalBar();

    // Iterate through the json object, print the first 10 matches
    // that contain the substring, and the number of total matches
    iterateJson(j, substr);

  }

  // Print the defintion of the word the user enters when enter is pressed
  giveDefinition(substr, j);
  
  return 0;
}
