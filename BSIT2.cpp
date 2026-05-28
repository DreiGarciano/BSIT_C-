#include <iostream>
using namespace std;

int main() {

    int score = 0;
    int answer;

    cout << "\n  === PERSONALITY QUIZ ===\n";
    cout << "  Answer each question (1-3).\n\n";

    // Q1
    cout << "  1. Your weekend plan?\n";
    cout << "     1. Stay home\n";
    cout << "     2. Hang out with friends\n";
    cout << "     3. Try something new\n";
    cout << "  >> ";
    cin >> answer;

    if      (answer == 1) score += 1;
    else if (answer == 2) score += 2;
    else if (answer == 3) score += 3;

    // Q2
    cout << "\n  2. Pick a meal:\n";
    cout << "     1. Home cooked\n";
    cout << "     2. Fast food\n";
    cout << "     3. Something exotic\n";
    cout << "  >> ";
    cin >> answer;

    if      (answer == 1) score += 1;
    else if (answer == 2) score += 2;
    else if (answer == 3) score += 3;

    // Q3
    cout << "\n  3. A problem comes up. You:\n";
    cout << "     1. Think it through alone\n";
    cout << "     2. Ask a friend\n";
    cout << "     3. Wing it\n";
    cout << "  >> ";
    cin >> answer;

    if      (answer == 1) score += 1;
    else if (answer == 2) score += 2;
    else if (answer == 3) score += 3;

    // Q4
    cout << "\n  4. Your ideal pet:\n";
    cout << "     1. Cat\n";
    cout << "     2. Dog\n";
    cout << "     3. Something weird\n";
    cout << "  >> ";
    cin >> answer;

    if      (answer == 1) score += 1;
    else if (answer == 2) score += 2;
    else if (answer == 3) score += 3;

    // Q5
    cout << "\n  5. Pick a color:\n";
    cout << "     1. Blue\n";
    cout << "     2. Yellow\n";
    cout << "     3. Red\n";
    cout << "  >> ";
    cin >> answer;

    if      (answer == 1) score += 1;
    else if (answer == 2) score += 2;
    else if (answer == 3) score += 3;

    // Result
    cout << "\n  ========================\n";
    cout << "  Score: ";
    for (int i = 0; i < score; i++) cout << "*";
    cout << " (" << score << "/15)\n";
    cout << "  ========================\n\n";

    if (score <= 5) {
        cout << "  You are: THE HOMEBODY\n";
        cout << "  Calm, private, and content.\n";
        cout << "  You recharge alone and that's your power.\n";
    } else if (score <= 9) {
        cout << "  You are: THE SOCIAL ONE\n";
        cout << "  You thrive around people.\n";
        cout << "  Reliable, warm, easy to talk to.\n";
    } else if (score <= 12) {
        cout << "  You are: THE EXPLORER\n";
        cout << "  Always curious, always moving.\n";
        cout << "  You get bored easily but never boring.\n";
    } else {
        cout << "  You are: THE WILDCARD\n";
        cout << "  Unpredictable. Chaotic. Fun.\n";
        cout << "  Nobody knows what you'll do next. Not even you.\n";
    }

    cout << "\n  ========================\n";

    return 0;
}
