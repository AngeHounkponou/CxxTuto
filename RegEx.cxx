#include <iostream>
#include <map>
#include <regex>
#include <string>

using namespace std;

// Function that replaces a string based on a regular expression
string clean_input(const string &s_input, string s_replace, regex regx) {
    string s_resut{};

    // Cleans the string and stores the result in s_resut
    regex_replace(back_inserter(s_resut), s_input.begin(), s_input.end(), regx,
                  s_replace);

    return s_resut;
}

int main() {
    // Text with HTML tags to clean.
    string str_toClean{"<p><b>Luc 2 : 1</b><br>And it came to pass in those days, "
                       "that there went out a decree from <i>Caesar Augustus</i> that all the "
                       "world should be taxed.<br>"
                       "<font color='red'>King James Version</font><p>"};

    // Print Initial string
    cout << "Initialial string  : " << endl << str_toClean << endl;

    // Initialize str_clean with original string
    string str_clean{str_toClean};

    // Create a map that will store the final string and regex pair (to match // tags).
    map<string, regex> regx_map{};

    // Adding a group of HTML tags to be deleted.
    regx_map.insert({"", regex(R"(<.>|</.>|</font>)")});

    // Adding a group of HTML tags that must be replaced by a space.
    regx_map.insert({" ", regex(R"(<br>|<font.+'>)")});

    // Browse our map to clean the input (based on the regexes provided)
    for (const auto &i_map : regx_map) {
        str_clean = clean_input(str_clean, i_map.first, i_map.second);
    }

    cout <<endl<<"Cleaned text : " << endl << str_clean << endl;

    return 0;
}

// #c++ #regex #cleanInput
