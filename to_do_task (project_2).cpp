#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 📝 Structure for Task
struct Task {
    string name;
    bool completed;
};

// 📋 Display Menu
void showMenu() {
    cout << "\n📌 TO-DO LIST MANAGER 📌\n";
    cout << "1️⃣  Add Task\n";
    cout << "2️⃣  View Tasks\n";
    cout << "3️⃣  Mark Task as Completed\n";
    cout << "4️⃣  Remove Task\n";
    cout << "5️⃣  Exit 🚪\n";
    cout << "👉 Enter your choice: ";
}

// ➕ Add Task
void addTask(vector<Task>& tasks) {
    cin.ignore();
    Task t;
    cout << "✍️ Enter task name: ";
    getline(cin, t.name);
    t.completed = false;
    tasks.push_back(t);
    cout << "✅ Task added successfully!\n";
}

// 👀 View Tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "📭 No tasks available.\n";
        return;
    }
    cout << "\n🗂 Your Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].completed ? "✅ Completed" : "⏳ Pending") << "]\n";
    }
}

// ✔ Mark Task as Completed
void completeTask(vector<Task>& tasks) {
    int num;
    viewTasks(tasks);
    cout << "🔢 Enter task number to mark completed: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "🎉 Task marked as completed!\n";
    } else {
        cout << "❌ Invalid task number!\n";
    }
}

// ❌ Remove Task
void removeTask(vector<Task>& tasks) {
    int num;
    viewTasks(tasks);
    cout << "🗑 Enter task number to remove: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "🧹 Task removed successfully!\n";
    } else {
        cout << "❌ Invalid task number!\n";
    }
}

// 🚀 Main Function
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: completeTask(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "👋 Exiting... Stay productive! 💪\n"; break;
            default: cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
