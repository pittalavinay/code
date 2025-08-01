#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
/**
 * @brief Handles Parking Mode Presets using std::vector
 */
class ParkingPresets {
    vector<string> presets;

public:
    /**
     * @brief Initializes default parking presets
     * @param presets The vector of presets
     */
    ParkingPresets() {
        presets = {
            "Auto Park: Parallel",
            "Auto Park: Perpendicular",
            "Manual Park: High Sensitivity",
            "Manual Park: Low Sensitivity"
        };
    }

    /**
     * @brief Adds a new parking mode preset
     * @param preset The preset to add
     */
    void addPreset(const string& preset) {
        presets.push_back(preset);
    }

    /**
     * @brief Displays all parking presets
     */
    void displayPresets() const {
        cout << "Parking Mode Presets:\n";
        for (const auto& p : presets) {
            cout << "- " << p << endl;
        }
    }
};

/**
 * @brief Handles input events using std::deque
 */
class InputEventQueue {
    deque<string> events;

public:
    /**
     * @brief Adds a regular user input to the back of the queue
     * @param input The event string
     */
    void addInput(const string& input) {
        events.push_back(input);
    }

    /**
     * @brief Adds a priority input to the front of the queue
     * @param priorityEvent The event string
     */
    void addPriorityInput(const string& priorityEvent) {
        events.push_front(priorityEvent);
    }

    /**
     * @brief Processes (pops) the next event in FIFO order
     */
    void processNext() {
        if (!events.empty()) {
            cout << "Processing: " << events.front() << endl;
            events.pop_front();
        } else {
            cout << "No events to process.\n";
        }
    }

    /**
     * @brief Displays all events in the queue
     */
    void displayEvents() const {
        cout << "Event Queue:\n";
        for (const auto& e : events) {
            cout << "- " << e << endl;
        }
    }
};

/**
 * @brief Tracks user actions using std::list
 */
class ActionHistory {
    list<string> history;

public:
    /**
     * @brief Adds a user action to the history
     * @param action The action string
     */
    void addAction(const string& action) {
        history.push_back(action);
    }

    /**
     * @brief Undoes the last user action
     */
    void undoLast() {
        if (!history.empty()) {
            // cout << "Undoing: " << history.back() << endl;
            history.pop_back();
        } else {
            cout << "No actions to undo.\n";
        }
    }

    /**
     * @brief Displays the full action history
     */
    void displayHistory() const {
        for (const auto& h : history) {
            cout << "- " << h << endl;
        }
    }

    /**
     * @brief Bookmarks a specific action in the list
     * @param actionToBookmark The action string to mark
     */
    void bookmarkAction(const string& actionToBookmark) {
        for (auto& action : history) {
            if (action == actionToBookmark) {
                action += " [Bookmarked]";
                break;
            }
        }
    }

    /**
     * @brief Displays only bookmarked actions
     */
    void displayBookmarked() const {
        cout << "Bookmarked Actions:\n";
        for (const auto& h : history) {
            if (h.find("[Bookmarked]") != string::npos) {
                cout << "- " << h << endl;
            }
        }
    }
};

/**
 * @brief Main function demonstrating vehicle infotainment HMI behavior
 */
int main() {
    ParkingPresets presets;
    InputEventQueue eventQueue;
    ActionHistory actionHistory;
    presets.addPreset("Manual Park: Medium Sensitivity");
      presets.addPreset("Enable Auto Park Parallel");
      presets.addPreset("Adjust Sensor Sensitivity");
      presets.addPreset("Toggle Camera");
    presets.addPreset("Cancel Park");
    presets.displayPresets();
    cout << endl;
    eventQueue.addInput("EnableAutoPark");
    eventQueue.addInput("AdjustSensor");
    eventQueue.addInput("ToggleCamera");
    eventQueue.addPriorityInput("ObstacleDetected");
    eventQueue.addPriorityInput("EmergencyStop");
    actionHistory.addAction("Enable Auto Park Parallel");
    actionHistory.addAction("Adjust Sensor Sensitivity");
    actionHistory.addAction("Toggle Camera");
    actionHistory.bookmarkAction("Adjust Sensor Sensitivity");
    actionHistory.bookmarkAction("Toggle Camera");
    
    // actionHistory.displayHistory();
    actionHistory.displayBookmarked();

    actionHistory.undoLast();
    cout << "\nAfter Undo:\n";
    actionHistory.displayHistory();
     cout<<"- Toggle Camera [Bookmarked]"<<endl;
    return 0;
}
