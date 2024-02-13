# include "functions.h"
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    string obfuscated;
    cout << "Please enter obfuscated sentence: ";
    cin >> obfuscated;

    if (obfuscated.length() < 10) {
        cout << "Sentence must be at least 10 characters long" << endl;
        return;
    }

    string deobfuscationDetails;
    cout << "Please enter deobfuscation details: ";
    cin >> deobfuscationDetails;

    string deobfuscated;
    for (int i = 0; i < deobfuscationDetails.length(); i++) {
        int length = deobfuscationDetails[i] - '0';
        deobfuscated += obfuscated.substr(0, length) + " ";
        obfuscated = obfuscated.substr(length);
    }

    cout << "Deobfuscated sentence: " << deobfuscated << endl;
}

void wordFilter() {
    string sentence;
    cout << "Please enter the sentence: ";
    getline(cin, sentence);  // get until a newline, presumably there are spaces here


    string filterWord;
    cout << "Please enter the filter word: ";
    cin >> filterWord;

    string filteredSentence = sentence;
    int index = 0;
    while (index != -1) {
        index = filteredSentence.find(filterWord);
        if (index != -1) {
            filteredSentence.replace(index, filterWord.length(), "####");
        }
    }
    cout << "Filtered sentence: " << filteredSentence << endl;
}

void passwordConverter() {
    string password;

    cout << "Please enter your text input: ";

    cin >> password;

    cout << "input: " << password << endl;

    string newPassword = "";

    for (int i = 0; i < password.length(); i++) {
        switch (password[i]) {
            case 'a':
                newPassword += '@';
                break;
            case 'e':
                newPassword += '3';
                break;
            case 'i':
                newPassword += '!';
                break;
            case 'o':
                newPassword += '0';
                break;
            case 'u':
                newPassword += '^';
                break;
            default:
                newPassword += password[i];
        }
    }

    string reversedNewPassword = newPassword;

    for (int i = 0; i < newPassword.length(); i++) {
        reversedNewPassword[i] = newPassword[newPassword.length() - i - 1];
    }

    cout << "output: " << newPassword + reversedNewPassword << endl;
}

void wordCalculator() {
// prompt user to enter a sequence of numbers and arithmetic symbols as words
// calculate result of eqn
// output words converted to numbers and symbols and the result
// valid number words: zero, one, two, three, four, five, six, seven, eight, nine
// valid symbols: plus, minus, times, divides
// order of op is left to right
// use the std::to_string function to convert int to string

    /*
     * Example:
Please enter word equation (type 'equals' at the end):
five times two plus four divides seven equals
5 * 2 + 4 / 7 = 2
     */
    cout << "Please enter word equations (type \'equals\' at the end): " << endl;

    string wordEquation;

    getline(cin, wordEquation);

    // evaluate using every previous word and every current word, then add to the result

    int result = 0;
    string currentWord = "";
    string previousWord = "";

    string wholeProcess = "";

    for (int i = 0; i < wordEquation.length(); i++) {
        if (wordEquation[i] == ' ') {
            if (currentWord == "equals") {
                break;
            }
            if (currentWord == "zero") {
                currentWord = "0";
                wholeProcess += "0";
            } else if (currentWord == "one") {
                currentWord = "1";
            } else if (currentWord == "two") {
                currentWord = "2";
            } else if (currentWord == "three") {
                currentWord = "3";
            } else if (currentWord == "four") {
                currentWord = "4";
            } else if (currentWord == "five") {
                currentWord = "5";
            } else if (currentWord == "six") {
                currentWord = "6";
            } else if (currentWord == "seven") {
                currentWord = "7";
            } else if (currentWord == "eight") {
                currentWord = "8";
            } else if (currentWord == "nine") {
                currentWord = "9";
            } else if (currentWord == "plus") {
                currentWord = "+";
            } else if (currentWord == "minus") {
                currentWord = "-";
            } else if (currentWord == "times") {
                currentWord = "*";
            } else if (currentWord == "divides") {
                currentWord = "/";
            }
            if (previousWord == "") {
                result = std::stoi(currentWord);
            } else {
                if (previousWord == "+") {
                    result += std::stoi(currentWord);
                } else if (previousWord == "-") {
                    result -= std::stoi(currentWord);
                } else if (previousWord == "*") {
                    result *= std::stoi(currentWord);
                } else if (previousWord == "/") {
                    result /= std::stoi(currentWord);
                }
            }
            previousWord = currentWord;
            currentWord = "";
        } else {
            currentWord += wordEquation[i];
        }
    }

    cout << result << endl;

}


void palindromeCounter() {
    // TODO
}