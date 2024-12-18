#include <iostream>
#include <cstdlib>
#include <string>
#include <regex> // For input validation

using namespace std;

// Function to display running processes
void displayProcessList() {
    cout << "\nRetrieving list of active processes...\n" << endl;
    int executionStatus = system("tasklist");
    if (executionStatus != 0) {
        cout << "Unable to fetch the process list. Please check your system permissions.\n";
    }
}

// Function to terminate a process using PID
void endProcess() {
    string processID;
    cout << "Enter the PID of the process to terminate: ";
    cin >> processID;

    // Validate that the input is a numeric PID
    if (!regex_match(processID, regex("^[0-9]+$"))) {
        cout << "Error: The PID must be a numeric value.\n";
        return;
    }

    // Construct and execute the termination command
    string terminationCommand = "taskkill /F /PID " + processID;
    int terminationStatus = system(terminationCommand.c_str());
    if (terminationStatus == 0) {
        cout << "Successfully terminated the process with PID: " << processID << "\n";
    } else {
        cout << "Failed to terminate the process. Ensure the PID is correct and you have necessary permissions.\n";
    }
}

// Main menu and program loop
int main() {
    int userChoice;
    do {
        cout << "\n==== Process Manager ====\n";
        cout << "1. View Active Processes\n";
        cout << "2. Terminate a Process\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                displayProcessList();
                break;
            case 2:
                endProcess();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please select a valid choice.\n";
        }
    } while (userChoice != 0);

    return 0;
}
