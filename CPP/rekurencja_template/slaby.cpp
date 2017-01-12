#include <iostream>
#include <sstream>
// DANIEL SŁABY
using namespace std;

int fincOccurences(string text, string toFind) {
    int occurrences = 0;
    string::size_type start = 0;
    string to_find_occurrences_of = "{}";
    while ((start = text.find(toFind, start)) != string::npos) {
        ++occurrences;
        start += to_find_occurrences_of.length(); // see the note
    }
    return occurrences;
}


template<typename T>
string convertToString(T arg) {
    ostringstream strs;
    strs << arg;
    return strs.str();
}

template<typename T>
string replace(string text, T arg) {
    string toBeReplaced("{}");
    return text.replace(text.find("{}"), toBeReplaced.length(), convertToString(arg));
}

template<typename T>
string adder(string text, T first) {
    return replace(text, first);
}


template<typename T, typename... Args>
string adder(string text, T first, Args... args) {
    text = replace(text, first);
    string x = adder(text, args...);
    return x;
}


template<typename ... Rest>
void WypiszLiczby(string text, Rest ... Args) {
    string result = adder(text, Args...);
    cout << result << endl;
    int numberOfParenthesis = fincOccurences(result, "{}");
    if (numberOfParenthesis != 0) {
        throw length_error("Insufficient number of arguments for string interpolation");
    }
}

template<typename T>
string replace2(string text, string textToFind, T arg) {
    int x = fincOccurences(text, textToFind);
    string toBeReplaced(textToFind);
    string result = "";
    for (int i = 0; i < x; i++) {
        result = text.replace(text.find(textToFind), toBeReplaced.length(), convertToString(arg));
    }

    return result;
}


template<typename T>
string wyp2(int counter, string text, T first) {
    string toFind = "{" + to_string(counter) + "}";
    text = replace2(text, toFind, first);
    return text;
}

template<typename T, typename ... Rest>
string wyp2(int counter, string text, T first, Rest ... args) {

    string toFind = "{" + to_string(counter) + "}";
    text = replace2(text, toFind, first);
    text = wyp2(++counter, text, args...);

    return text;
}

template<typename ... Rest>
void wypisz2(string text, Rest ... args) {
    cout << wyp2(1, text, args...) << endl;
}

long long operator "" _bin(unsigned long long args) {
    string toString = std::to_string(args);
    int lengthOfString = toString.length();
    int power = 1;
    long long result = 0;
    for (int i = lengthOfString - 1; i >= 0; i--) {
        int toInt = toString[i] - '0';
        result += toInt * power;
        power *= 2;
    }
    return result;
}


int main() {
    WypiszLiczby("Wynikiem {} {} do {} jest {}", "dodania", 2.0, 3, 2.0+3);
    wypisz2("{1} {3} + {2} = {4} {1}", "||", 2.5, 3, 5.5);

    cout << 1101_bin << " " << -1100_bin << endl;
    return 0;
}
