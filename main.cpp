#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x_start, x_end, step, sum1;
    int n;
    unsigned int attempt_number = 0;
    bool is_entered = false;
    bool data_ready = false;          // are all four values entered?
    double result = 0;
    string choice;

    // ---------- Screen 1: welcome (shown once at the start) ----------
    cout << "|=========================================|" << '\n'
         << "| Expression No. 7 Calculation Program    |" << '\n'
         << "| Welcome to the expression calculator    |" << '\n'
         << "|_________________________________________|" << '\n' << '\n';

    // ---------- Screen 2: main menu (full version, shown once) ----------
    cout << "|=========================================|" << '\n'
         << "| MAIN MENU                               |" << '\n'
         << "|=========================================|" << '\n'
         << "| 1 - Enter data                          |" << '\n'
         << "| 2 - Calculate                           |" << '\n'
         << "| 3 - Back to the start (clear data)      |" << '\n'
         << "| 4 - Exit                                |" << '\n'
         << "|_________________________________________|" << '\n' << '\n';

    do {
        // ---------- main menu (one-line reminder after every action) ----------
        cout << "| 1 - Enter | 2 - Calculate | 3 - Back | 4 - Exit |" << '\n'
             << "| Your choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');       // remove the rest of the line
        cout << '\n';

        // =====================================================
        // 1 - ENTER DATA (Screens 3, 4, 5, 6)
        // =====================================================
        if (choice == "1") {
            data_ready = false;

            // ----- start of the interval -----
            attempt_number = 0;       // reset the counter
            is_entered = false;       // reset the flag

            cout << "| Start of the interval (e.g. 3 or -1.5): ";
            while (attempt_number < 5) {
                if (cin >> x_start && cin.peek() == '\n') {   // a number and nothing after it
                    cin.ignore(1000, '\n');
                    is_entered = true;
                    break;
                }

                // we get here only on an input error
                cin.clear();
                cin.ignore(1000, '\n');
                attempt_number = attempt_number + 1;
                if (attempt_number < 5) cout << "|   Not a number, try again: ";
            }

            if (!is_entered) {
                x_start = 8;
                cout << "|   Auto-chosen: " << x_start << ". You can change it with option 1. |" << '\n';
            }

            cout << "| OK: start = " << x_start << " |" << '\n' << '\n';

            // ----- end of the interval -----
            attempt_number = 0;
            is_entered = false;

            cout << "| End of the interval (greater than start, e.g. 15): ";
            while (attempt_number < 5) {
                if (cin >> x_end && cin.peek() == '\n') {     // is it a number at all?
                    cin.ignore(1000, '\n');
                    if (x_end > x_start) {                    // and is it greater than the start?
                        is_entered = true;
                        break;
                    }
                    // the number is valid, but too small
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Must be greater than " << x_start << ", try again: ";
                }
                else {
                    // not a number was entered
                    cin.clear();
                    cin.ignore(1000, '\n');
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Not a number, try again: ";
                }
            }

            if (!is_entered) {
                x_end = x_start + 10;
                cout << "|   Auto-chosen: " << x_end << ". You can change it with option 1. |" << '\n';
            }

            cout << "| OK: end = " << x_end << " |" << '\n' << '\n';

            // ----- step -----
            attempt_number = 0;
            is_entered = false;

            cout << "| Step (greater than 0, e.g. 2): ";
            while (attempt_number < 5) {
                if (cin >> step && cin.peek() == '\n') {      // is it a number at all?
                    cin.ignore(1000, '\n');
                    if (step > 0) {                           // and is it greater than 0?
                        is_entered = true;
                        break;
                    }
                    // the number is valid, but too small
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Must be greater than 0, try again: ";
                }
                else {
                    // not a number was entered
                    cin.clear();
                    cin.ignore(1000, '\n');
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Not a number, try again: ";
                }
            }

            if (!is_entered) {
                step = 2;
                cout << "|   Auto-chosen: " << step << ". You can change it with option 1. |" << '\n';
            }

            cout << "| OK: step = " << step << " |" << '\n' << '\n';

            // ----- number of repetitions n -----
            attempt_number = 0;
            is_entered = false;

            cout << "| Repetitions n (whole number greater than 1, e.g. 4): ";
            while (attempt_number < 5) {
                if (cin >> n && cin.peek() == '\n') {         // is it a number at all?
                    cin.ignore(1000, '\n');
                    if (n > 1) {                              // and is it greater than 1?
                        is_entered = true;
                        break;
                    }
                    // the number is valid, but too small
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Must be greater than 1, try again: ";
                }
                else {
                    // not a number was entered
                    cin.clear();
                    cin.ignore(1000, '\n');
                    attempt_number = attempt_number + 1;
                    if (attempt_number < 5) cout << "|   Not a number, try again: ";
                }
            }

            if (!is_entered) {
                n = 4;
                cout << "|   Auto-chosen: " << n << ". You can change it with option 1. |" << '\n';
            }

            cout << "| OK: n = " << n << " |" << '\n' << '\n';

            // ----- Screen 6: summary -----
            cout << "|=========================================|" << '\n'
                 << "| Here is the data you entered:           |" << '\n'
                 << "| Start of the interval: " << x_start << " |" << '\n'
                 << "| End of the interval: " << x_end << " |" << '\n'
                 << "| Step: " << step << " |" << '\n'
                 << "| Number of repetitions: " << n << " |" << '\n'
                 << "| Next step: choose 2 to calculate.       |" << '\n'
                 << "|_________________________________________|" << '\n' << '\n';

            data_ready = true;
        }

        // =====================================================
        // 2 - CALCULATE (Screens 7 and 8)
        // =====================================================
        else if (choice == "2") {
            if (!data_ready) {
                cout << "| No data yet. Please choose 1 and enter the data first. |" << '\n' << '\n';
            }
            else {
                cout << "| Calculations in progress... |" << '\n' << '\n';

                double x = x_start;

                cout << fixed << setprecision(2);
                cout << "|=========================================|" << '\n'
                     << "| Calculation results                     |" << '\n'
                     << "|=========================================|" << '\n'
                     << "|        x        |           y           |" << '\n'
                     << "|_________________|_______________________|" << '\n';

                while (x <= x_end) {
                    result = 0;

                    if (x < -2) {
                        int i = 0;
                        while (i <= (n + 3)) {
                            int j = 0;
                            sum1 = 0;
                            while (j <= n) {
                                sum1 = sum1 + pow((i + x - j), 2);
                                j = j + 1;
                            }
                            result = result + sum1;
                            i = i + 1;
                        }
                    }
                    else {
                        double prod = 1;
                        double j = 1;
                        while (j <= n) {
                            prod = prod * (7 * x - j);
                            j = j + 1;
                        }
                        double sum3 = 0;
                        j = 1;
                        while (j <= n) {
                            sum3 = sum3 + ((j + 2) / (j * j));
                            j = j + 1;
                        }
                        result = prod - (6 * x * sum3);
                    }

                    cout << "| " << setw(15) << x << " | " << setw(21) << result << " |" << '\n';

                    x = x + step;
                }
                cout << "|_________________|_______________________|" << '\n' << '\n';
            }
        }

        // =====================================================
        // 3 - BACK TO THE START (Screen 8)
        // =====================================================
        else if (choice == "3") {
            data_ready = false;
            cout << "| The entered data was cleared. |" << '\n' << '\n';
        }

        // =====================================================
        // 4 - EXIT is handled by the loop condition below
        // =====================================================
        else if (choice != "4") {
            cout << "| Please type 1, 2, 3 or 4. |" << '\n' << '\n';
        }

    } while (choice != "4");

    cout << "| Goodbye! |" << '\n';
    return 0;
}