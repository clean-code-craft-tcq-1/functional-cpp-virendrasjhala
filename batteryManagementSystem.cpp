#include <assert.h>
#include <iostream>
#include <vector>
#include "batteryInterface.h"
using namespace std;


int main() {

	/*-------------------------------------------input parameters----------------------------------------*/
	float setTodaysTemperature    = 23;
	int   checkStatusofcharge     = 70;
	float checkBatteryTemperature = 21;
	float checkBatteryVoltage     = 4;
	float checkBatteryCurrent     = 1.0;
	/*-------------------------------------------input parameters----------------------------------------*/

	/* "-----------------------------------------weather status-----------------------------------------*/
	wheaterIndicator WeatherHandler;
	WeatherHandler.TodaysTemperature(setTodaysTemperature);

	/* "-----------------------------------------battery status------------------------------------------*/
	StatusOfCharge statusofcharge;
	assert(statusofcharge.StatusOfBatteryCharge(checkStatusofcharge) == true);

	/* "-------------------------------------battery Charging conditions check---------------------------*/
	BatteryIndicator Batteryindicator(checkBatteryTemperature, checkBatteryVoltage, checkBatteryCurrent);
	BatteryChargingCheck battery_charging_check;
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);

	//system("pause");
}
