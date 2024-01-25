// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string &line,
                            string *category,
                            double *score);

int main() {
    using namespace std;

    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want

    double finalExamScore = 0;

    double examSum = 0;
    int examCount = 0;
    double hwSum = 0;
    int hwCount = 0;
    double readingSum = 0;
    int readingCount = 0;
    double engagementSum = 0;
    int engagementCount = 0;
    double lwSum = 0;
    int lwCount = 0;


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        cout << "category: " << category << " score: " << score << endl;

        // process the grade entry
        if (category == "exam") {
            examSum += score;
            examCount++;
        } else if (category == "final-exam") {
            finalExamScore = score;
            examSum += score;
            examCount++;
        } else if (category == "hw") {
            hwSum += score;
            hwCount++;
        } else if (category == "lw") {
            lwSum += score;
            lwCount++;
        } else if (category == "reading") {
            readingSum += score;
            readingCount++;
        } else if (category == "engagement") {
            engagementSum += score;
            engagementCount++;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    double examAverage = examSum / examCount;
    double hwAverage = hwSum / hwCount;
    double lwAverage = lwSum / lwCount * 100;
    double readingAverage = min(readingSum / readingCount + 15, 100.0);
    double engagementAverage = min(engagementSum / engagementCount + 15, 100.0);


    cout << "-----Average Computations-----" << endl;
    cout << "exam average: " << examAverage << endl;
    cout << "hw average: " << hwAverage << endl;
    cout << "lw average: " << lwAverage << endl;
    cout << "readingAverage: " << readingAverage << endl;
    cout << "engagementAverage: " << engagementAverage << endl;


    if (finalExamScore > examAverage) {
        examAverage = finalExamScore; // replaces the exam average if final is higher
    }


    double weighted_total = 0;

    weighted_total += 0.4 * hwAverage;
    weighted_total += 0.1 * lwAverage;
    weighted_total += 0.4 * examAverage;
    weighted_total += 0.05 * readingAverage;
    weighted_total += 0.05 * engagementAverage;


    char final_letter_grade;

    if (weighted_total >= 90) {
        final_letter_grade = 'A';
    } else if (weighted_total >= 80) {
        final_letter_grade = 'B';
    } else if (weighted_total >= 70) {
        final_letter_grade = 'C';
    } else if (weighted_total >= 60) {
        final_letter_grade = 'D';
    } else {
        final_letter_grade = 'F';
    }

    print_results(
            examAverage, hwAverage, lwAverage, readingAverage, engagementAverage,
            weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
        const string &line,
        string *category,
        double *score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
        double exam_average,
        double hw_average,
        double lw_average,
        double reading,
        double engagement,
        double weighted_total,
        char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
