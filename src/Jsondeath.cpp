#include "Jsondeath.h"

string testerString = "minecraft";

string StringGetter(const string &str, const string &test)
{
    string result;
    for (int i = 0; i < test.size(); i++)
    {
        result += str[i];//str = str + str[i] essentially 
    }
    return result;
}

json NewJsonArray(json &arrayInfo)
{
    for (int i = arrayInfo.size() - 1; i >= 0; i--)
    {
        string jsonString = arrayInfo[i];
        string readyString = StringGetter(jsonString, testerString);
        int result = testerString.compare(readyString);
        if (result != 0)
        {
            cout << "removing invalid json line" << endl;
            cout << "line name is | " << jsonString << " |" << endl;
            arrayInfo.erase(arrayInfo.begin() + i);
            cout << "ERASED" << endl;
        }
    }
        cout << "====================================================================" << endl;
        return arrayInfo;
}

void JsonDestroyer()
{
    string filePath = "PutJsonHere/Death.json";//RENAME IF FILE IS DIFFERENT NAME
    ifstream f(filePath);
    json jsonData = json::parse(f);
    //if you got a layer multiple layers deep for the auto it statement youll have to do this
    // auto it = jsonData["layerone"]["layertwo"].find("ArrayName")
    //if you do this REPLACE LINE 42 WITH THIS DONT FORGET TO CHANGE LINE 52 just dont add the .find()
    auto it = jsonData.find("MINECRAFT");
    json arrayName;
    json arrayInfo;

    if (it != jsonData.end())
    {
        arrayName = it.key();//Litteraly the arrays name in this case the json looks like {"MINECRAFT"[stuff, stuff2, stuff3]}
        arrayInfo = it.value();//the array info inside of MINECRAFT
    }
    arrayInfo = NewJsonArray(arrayInfo);
    //IF YOUR ARRAY IS DEEP CHANGE BELOW LIKE SO jsonData[layerone][layertwo]("ARRAYNAME")
    jsonData["MINECRAFT"] = arrayInfo;//wierd interaction cannot set a json obj like json minecraftarr = jsonData["MINECRAFT"]; not really sure why my only thought is it creates a copy of the array which i guess makes sense
    cout << arrayInfo << endl;
    ofstream outputFile(filePath);
    outputFile << jsonData.dump(4);
}
