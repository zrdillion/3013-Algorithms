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

### Example Output:

![Screenshot 2024-03-13 203352](https://github.com/zrdillion/3013-Algorithms/assets/157413038/d6628b24-37af-4a84-b7d9-22014ef89999)
Searching for the word absinthe.

&nbsp;

![Screenshot 2024-03-13 203618](https://github.com/zrdillion/3013-Algorithms/assets/157413038/57a359c3-107b-4860-aa2e-1cb916becf41)
Searching for the word debase, notice that despite there being multiple results, it only gives the definition of debase.

&nbsp;

![Screenshot 2024-03-13 203731](https://github.com/zrdillion/3013-Algorithms/assets/157413038/a9768920-19f0-48d7-bbaa-446aeb9b775d)
Searching for the word abject, similarly to the last, it only gives the desired word despite there being multiple suggestions.

&nbsp;

![Screenshot 2024-03-13 203845](https://github.com/zrdillion/3013-Algorithms/assets/157413038/d1560a5e-0999-4f5b-8966-f8c58249b637)
Finally searching for the word bronze and it again only gives the desired definition, and no other definitions.
