#include "Jsondeathkvpairs.h"
string stringtestinggod = "minecraft";
string filePath = "PutJsonHere/Death.json"; // RENAME IF FILE IS DIFFERENT NAME
ifstream f(filePath);
json datajson = json::parse(f);
vector<pair<string, json>> minecraft;

void Pairmaker(const json &jsonData, vector<pair<string, json>> &minecraftItems)
{
    for (auto &pair : jsonData.items())
    {
        const string &key = pair.key();
        auto &value = pair.value();
        string teststring = StringGetter(key, stringtestinggod);
        int result = stringtestinggod.compare(teststring);
        if (result == 0)
        {
            minecraftItems.push_back(make_pair(key, value));
        }
    }
    json newjsonfile;
    for (const auto& pair : minecraftItems)
    {
        newjsonfile[pair.first] = pair.second;
    }
    
    ofstream outputFile("JSONGOD.json");
    outputFile << newjsonfile.dump(4);
}

void RunPairMaker()
{
    cout << "PAIRMAKER" << endl;
    Pairmaker(datajson, minecraft);
}