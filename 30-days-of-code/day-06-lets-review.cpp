#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int wordCount = 0;
    vector<string> words;
    cin >> wordCount;
    cin.ignore();

    // Get the words
    for (int i = 0; i < wordCount; ++i) {
      string str;
      getline(cin, str);
      words.push_back(str);
    }
    
    for (const auto& word : words) {
      string even = "";
      string odd = "";
      for (int i = 0; i < word.length(); ++i) {
        if (i % 2 == 0) {
          even += word[i];
        } else {
          odd += word[i];
        }
      }
      
      cout << even << " " << odd << endl;
    }

    return 0;
}
