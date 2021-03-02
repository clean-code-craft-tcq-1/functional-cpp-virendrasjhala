#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	cout << "--------------------------wheather status-------------------------------------------" << endl;
	wheaterIndicator WheatherHandler;
    WheatherHandler.TodaysTemperature(20);

	cout << "--------------------------battery status-------------------------------------------" << endl;
	StatusOfCharge statusofcharge;
	assert(statusofcharge.StatusOfBatteryCharge(70)==true);

	cout << "--------------------------battery Charging conditions check------------------------" << endl;
	BatteryIndicator batterychargingCheck(21, 4, 1.0);
	BatteryChargingCheck battery_charging_check;
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);

	//system("pause");
}
