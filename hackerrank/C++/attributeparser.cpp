#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  cin.ignore();
  std::map<string, string> tags;
  string father_tag = "", input = "";
  for (int i = 0; i < n; i++){
    getline(cin, input);
    stringstream ss;
    ss.str(input);
    string word, attribute, value;
    size_t pos;
    while(getline(ss, word, ' ')){
      if(word[0] == '<'){
        string tag;
        if(word[1] == '/'){
          tag=word.substr(2);
          tag=tag.substr(0,tag.length()-1); // rid of ">"
          pos=father_tag.find("."+tag);
          if (pos==string::npos) father_tag="";
          else father_tag=father_tag.substr(0,pos);
        }
        else{
          tag = word.substr(1);
          if (tag.find(">")!=string::npos)
            tag=tag.substr(0,tag.length()-1);
          if(father_tag == ""){
            father_tag = tag;
          }
          else{
            father_tag = father_tag + "." + tag;
          }
        }
      }
      if(word[0] == '"'){
        pos=word.find_last_of('"');
        value=word.substr(1,pos-1);
        tags[attribute]=value; // insert into DB
      }
      // attribute name detected
      else if (word[0] != '=') {
        attribute=father_tag + "~" + word;
      }
    }
  }

  for (int i = 0; i < q; i++){
    getline(cin,input);
    if (tags.find(input)==tags.end())
      cout << "Not Found!" << endl;
    else
      cout << tags[input] << endl;
  }
}
