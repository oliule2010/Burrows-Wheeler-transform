#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
void print_vector(vector<string> input) {
    for (string word : input) {
        cout << word << " ";
    }
    cout << "\n";
}
vector<string> remove_repeat(vector<string>& input) {
    vector<string> output;

    for (string word : input) {
        auto it = find(output.begin(), output.end(), word);
        if (it == output.end()) {
            output.push_back(word);
        }
    }
    return output;
}
vector<string> delete_repeated_words(string input) {
    vector<string> words;
    string tmp = "";
    for (char ch : input) {
        
        if (ch == ' ') {
            if (tmp != "") {
                words.push_back(tmp);
                tmp.clear();
            }
        }
        else {

            tmp += ch;
        }
    }
    return remove_repeat(words);
}
unordered_map<char, int> char_int(string input) {
    unordered_map<char, int> output;
    for (char ch : input) {
        if (output.find(ch) == output.end()) {
            output[ch] = 1;
        }
        else {
            output[ch] = output[ch] + 1;
        }
    }return output;
 
}
unordered_map<string, int> count_how_many_words(string input) {
    unordered_map<string, int> output;
    vector<string> words;
    string tmp = "";
    for (char ch : input) {

        if (ch == ' ') {
            if (tmp != "") {
                words.push_back(tmp);
                tmp.clear();
            }
        }
        else {

            tmp += ch;
        }
    }
    for (string st : words) {
        if (output.find(st) == output.end()) {          
            output[st] = 1;
        }
        else {
            output[st] = output[st] + 1;
        }
    }return output;
}


int main()
{
    string input{ "best book award first place Harry Potter and the Philosipher Stone is the best book" };
    unordered_map<string, int> mymap = count_how_many_words(input);
 //   for (auto it = mymap.begin(); it != mymap.end(); ++it)
   //   cout << " " << it->first << ":" << it->second;
    //cout << endl;
    //print_vector(delete_repeated_words(input));
    
    for (auto it = mymap.begin(); it != mymap.end(); ++it)
        cout << " " << it->first << ":" << it->second;
    cout << endl;

}
































