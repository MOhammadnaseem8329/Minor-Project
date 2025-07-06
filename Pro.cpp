#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct PrintJob {
    int id;
    string name;

    PrintJob(int id, string name) : id(id), name(name) {}
};

queue<PrintJob> printerQueue;
int jobCounter = 1;

void addJob(const string& name) {
    printerQueue.push(PrintJob(jobCounter++, name));
    cout << "? Job '" << name << "' added to the queue.\n";
    cout << "?? Current number of jobs in queue: " << printerQueue.size() << "\n";
}

void processJob() {
    if (printerQueue.empty()) {
        cout << "?? No jobs in the queue to process.\n";
        return;
    }

    PrintJob job = printerQueue.front();
    printerQueue.pop();
    cout << "??? Printing job ID " << job.id << ": " << job.name << endl;
    cout << "?? Jobs left in queue: " << printerQueue.size() << "\n";
}
void viewQueue() {
    if (printerQueue.empty()) {
        cout << "?? Queue is empty.\n";
        return;
    }

    queue<PrintJob> tempQueue = printerQueue;
    cout << "\n?? Current Printer Queue:\n";
    cout << "--------------------------\n";
    while (!tempQueue.empty()) {
        PrintJob job = tempQueue.front();
        cout << "?? ID " << job.id << ": " << job.name << endl;
        tempQueue.pop();
    }
    cout << "--------------------------\n";
    cout << "Total jobs in queue: " << printerQueue.size() << "\n";
}

int main() {
    int choice;
    string jobName;

    do {
        cout << "\n===== Printer Queue Simulator =====\n";
        cout << "1??  Add Print Job\n";
        cout << "2??  Process Job\n";
        cout << "3??  View Queue\n";
        cout << "0??  Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "? Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                getline(cin, jobName);
                addJob(jobName);
                break;
            case 2:
                processJob();
                break;
            case 3:
                viewQueue();
                break;
            case 0:
                cout << "?? Exiting Printer Queue Simulator. Goodbye!\n";
                break;
            default:
                cout << "? Invalid choice. Please select 0, 1, 2, or 3.\n";
        }
    } while (choice != 0);

    return 0;
}

