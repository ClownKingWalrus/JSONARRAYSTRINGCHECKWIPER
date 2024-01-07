This only works if your json file is in a array like so
MINECRAFT : 
{
    example,
    example,
}
IMPORTENT========================================================================================
if you decide to use a differnt file name be sure in Jsondeath.cpp to change lines 36
string filePath = "anynameinquotes";
IMPORTENT========================================================================================
if you want to change the condidtions of deletion to be a differnt word or somthing
change on line 3 string
string testerString = "anystanderdhere"; must be a string unless u know how to code
THIS COMPARES YOUR WORD TO THE START OF THE JSON ARRAY WORDS and gives back the whole json arr if it passes the check example here
testerString = "bean"
json arr[0] = "FORTNITEGOD"
json arr[1] = "bean12GOD"

RUNS CODE ===================
OUTPUT
json arr[0] = bean12GOD"
this is because it remakes the array and reuploads it back to the array name that was designated
IMPORTENT========================================================================================
IF YOUR ARRAY IS DEEP IN LAYERS IN YOUR JSON FILE THE SWITCH IS SIMPLE
on lines 52 and 42 go ahead and just add the layers like so 
auto it = jsonData["LAYERONE"]["LAYERTWO"].find("ARRAYNAME");
jsonData["LAYERONE"]["LAYERTWO"]["ARRAYNAME"] = arrayInfo;
IMPORTENT========================================================================================

this code removes anything in the json file array that does not begin with minecraft
if you wish to change these parameters feel free to 




