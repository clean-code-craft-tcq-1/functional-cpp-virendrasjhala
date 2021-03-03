#pragma once
#include <assert.h>
#include <iostream>
#include "batteryInterface.h"
#include <iomanip>
using namespace std;

void BatterySpecification::BatterySpecificationPrinter()
{
	cout << "-------------------------------------------------Battery Specification -------------------------------------------------------" << endl;
	cout << "    || Wheather status || " << "           ||Battery status || " << "                         ||Battery current/voltage||" << endl;
	cout << "Temp       "    <<"                        B_Tmptr| "<<"low| "<< "full| "<< "actual| "<<   "      C_Min| "<<"C_Max| "<<"Curr_actual| "<<"V_Min| "<<"V_Max| "<<"Volt_actual| "<<endl;
	cout << wheaterIndicator::todaysTemperature     <<"`C"   << setw(33)   << BatteryElements::temprature            <<"`C"<<"    "  << BatteryChargingCheck::lowBatteryStatus <<"%"<<"   "  
		 << BatteryChargingCheck::fullBatteryStatus <<"%"    <<"   "        << StatusOfCharge::remainBatteryStatus     <<"%" << setw(14) << CurrentIndicator::currentMinThreshould <<"E"
		 << "   "  << CurrentIndicator::currentMaxThreshould <<"E"<<"      "<< BatteryElements::current                <<"E"<< setw(9) 
		 << VoltageIndicator::voltageMinThreshould  <<"V"    << setw(7)     << VoltageIndicator::vOltageMaxThreshould <<"V" <<"      "<< BatteryElements::voltage               <<"V"<<endl;
}

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
	if (hotWeather < todaysTemperature)
	{
		cout << "Very High Temperature!! charge is not allowed !" << endl;
		return false;
	}
	if (coldWeather > todaysTemperature)
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
			BatterySpecification::BatterySpecificationPrinter();
			return true;

		}
	else
		{
			BatterySpecification::BatterySpecificationPrinter();
			return false;
		}
	
}

bool StatusOfCharge::StatusOfBatteryCharge(float remainBatteryStatus)
{
	StatusOfCharge::remainBatteryStatus = remainBatteryStatus;
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
	float BatteryElements::temprature ;
	float BatteryElements::voltage ;
	float BatteryElements::current ;
	int   BatteryChargingCheck::fullBatteryStatus = 100;
	int   BatteryChargingCheck::lowBatteryStatus = 20;
	int   StatusOfCharge::remainBatteryStatus;
	float wheaterIndicator::hotWeather = 70;
	float wheaterIndicator::coldWeather = -50;
	float wheaterIndicator::todaysTemperature ;