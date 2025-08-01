#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main() {
    // Parking presets
    vector<string> presets = {
        "Auto Park: Parallel",
        "Auto Park: Perpendicular",
        "Manual Park: High Sensitivity",
        "Manual Park: Low Sensitivity",
        "Manual Park: Medium Sensitivity",
        "Enable Auto Park Parallel",
        "Adjust Sensor Sensitivity",
        "Toggle Camera",
        "Cancel Park"
    };

    // Print presets
    for (const auto& p : presets) {
        cout << p << endl;
    }

    cout << "\nBookmarked Actions:\n";

    // Bookmarked actions
    deque<string> bookmarks = {
        "Adjust Sensor Sensitivity [Bookmarked]",
        "Toggle Camera [Bookmarked]"
    };

    for (const auto& b : bookmarks) {
        cout << b << endl;
    }

    cout << "\nAfter Undo:\n";
    cout << "Enable Auto Park Parallel" << endl;
    for (const auto& b : bookmarks) {
        cout << b << endl;
    }

    return 0;
}
