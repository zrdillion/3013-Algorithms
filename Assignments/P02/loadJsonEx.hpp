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
*        Implements functions to load a json object passed into it using the json header created by nlohmann 
* 
*  Usage:
*        - Include as a header in main
*        - Make a call to one of the functions using the correct signature
* 
*  Files:
*        - json.hpp :header file for the json class
*****************************************************************************/
#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
//#include "./headers/timer.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

using json = nlohmann::json;

void saveWords(json j) {
    ofstream fout;
    fout.open("./data/words.txt");

    for (auto &element : j.items()) {
        string key = element.key();
        fout << key << "\n";
    }
}

json loadJsonFile(string filePath) {

    // Load your JSON object as shown in previous examples
    ifstream fileStream(filePath);
    string partialKey = " ";
    json myJson;
    //int i = 0;
    if (fileStream.is_open()) {
        fileStream >> myJson;
        fileStream.close();
    } else {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }
    
    return myJson;
}
