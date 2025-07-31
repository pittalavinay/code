#give code for add two numbers in C++
#include <iostream>
using namespace std;        
int main() {
    int a, b, sum;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    sum = a + b;
    cout << "Sum: " << sum << endl;
    return 0;
}
{
    DisplayManager dm;
    shared_ptr<DisplayScreen> speedScreen = make_shared<SpeedometerScreen>();
    shared_ptr<DisplayScreen> navScreen = make_shared<NavigationScreen>();
    
    dm.addScreen(speedScreen);
    dm.addScreen(navScreen);
    
    speedScreen->updateData(60);
    navScreen->updateData(1);
    
    dm.renderAll();
    
    return 0;
}
    shared_ptr<DisplayScreen> dm5=make_shared<WarningAlertScreen>();
    dm5->updateData(1);
    ds.addScreen(dm5);
    
    // Render all screens
    ds.renderAll();
    
    return 0;
}