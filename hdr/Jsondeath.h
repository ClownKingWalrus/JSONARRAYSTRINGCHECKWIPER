#ifndef JSONDEATH_H
#define JSONDEATH_H

#include "json.hpp"
#include <json.hpp>
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;
using json = nlohmann::json;

void JsonDestroyer();
string StringGetter(const string &str, const string &test);
json NewJsonArray(json &arrayInfo);

#endif