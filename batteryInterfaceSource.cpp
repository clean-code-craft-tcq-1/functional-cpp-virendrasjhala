#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"

using namespace std;

bool CurrentIndicator::currentStatus()
{
	if(currentMinThreshould >= current || currentMaxThreshould <=current)
		{
			cout << "Charge current Rate out of range!\n";
			return false;
		}
	else
		{
			return true;
		}
}

bool VoltageIndicator::voltageStatus()
{
	if (voltageMinThreshould >= voltage || vOltageMaxThreshould <= voltage)
		{
			cout << "Charge voltage Rate out of range!\n";
			return false;
		}
	else
		{
			return currentStatus();
		}
}

bool TempratureIndicator::tempratureStatus()
{
	if (tampratureMinThreshould >= temprature || temperatureMaxThreshould <= temprature)
		{
			cout << "Charge tamperature of battery out of range!\n";
			return false;
		}
	else
		{
			return voltageStatus();
		}
}

BatteryIndicator::BatteryIndicator(float temp, float vol, float curr)
{
	current = curr;
	voltage = vol;
	temprature = temp;
}
bool wheaterIndicator::wheatherStatus()
{
	if (hotWheater < todaysTemperature)
	{
		cout << "Very High Temperature!! charge is not allowed !" << endl;
		return false;
	}
	if (coldWheater > todaysTemperature)
	{
		cout << "Very Low Temperature!! charge is not allowed !" << endl;
		return false;
	}
	return tempratureStatus();
}
void wheaterIndicator::TodaysTemperature(float temp)
{
	todaysTemperature = temp;
}
bool BatteryChargingCheck::batteryRequirements_For_Charging()
{
	wheaterIndicator wheaterHandler;
	if (wheaterHandler.wheatherStatus())
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool StatusOfCharge::StatusOfBatteryCharge(float remainBatteryStatus)
{
	if (remainBatteryStatus < lowBatteryStatus)
		{
			cout << "Battery is critical !" << endl;
			return false;
		}
	else if (remainBatteryStatus == fullBatteryStatus)
	{
		cout << "Battery is completely charged!! please disconnect charger !" << endl;
	}
	return true;
}
	float CurrentIndicator::currentMinThreshould = 0.8;
	float CurrentIndicator::currentMaxThreshould = 1.2;
	float VoltageIndicator::voltageMinThreshould = 3;
	float VoltageIndicator::vOltageMaxThreshould = 6;
	float TempratureIndicator::tampratureMinThreshould = -20;
	float TempratureIndicator::temperatureMaxThreshould = 50;
	float BatteryElements::temprature = 0;
	float BatteryElements::voltage = 0;
	float BatteryElements::current = 0;
	int   BatteryChargingCheck::fullBatteryStatus = 100;
	int   BatteryChargingCheck::lowBatteryStatus = 20;
	float wheaterIndicator::hotWheater = 70;
	float wheaterIndicator::coldWheater = -50;
	float wheaterIndicator::todaysTemperature = 0;