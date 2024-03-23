## P02 - Linear Search & Json
### Zach Dillion
### Description:

This program prompts the user for input from the keyboard, it will then iterate through a json file that contains many words and the definitions of those words.
The program will continuously iterate through the json file as the user enters more input from the keyboard with the goal of finding a singular word.
Once this singular word has been found, and the user has pressed the "Enter" key, the definition of the word will be output.

### Files

|   #   | File                                                                                                    | Description                                                         |
| :---: | ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- |
|   1   | [main.cpp](https://github.com/zrdillion/3013-Algorithms/blob/main/Assignments/P02/main.cpp)             | Main driver program                                                 |
|   2   | [loadJsonEx.hpp](https://github.com/zrdillion/3013-Algorithms/blob/main/Assignments/P02/loadJsonEx.hpp) | Header used to load the json file in main                           |
|   3   | [console.hpp](https://github.com/zrdillion/3013-Algorithms/blob/main/Assignments/P02/console.hpp)       | Header used for determining which functions to use based on the OS  |
|   4   | [rang.hpp](https://github.com/zrdillion/3013-Algorithms/blob/main/Assignments/P02/rang.hpp)             | Header used to modify text output to the console                    |
|   5   | [json.hpp](https://github.com/zrdillion/3013-Algorithms/blob/main/Assignments/P02/json.hpp)             | Header used to allow operations on and the creation of json objects |

### Instructions:
- Make sure to install json.hpp, this is a highly critical element
- When the program is started, begin entering letters
- Once you have found a word press the "Enter" key to be given the definition

(Note: This was developed on Replit, so it is best to also run it on Replit, as other programs may have unforseen errors.)

