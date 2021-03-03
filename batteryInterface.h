#pragma once
#include <assert.h>
#include <iostream>
using namespace std;


class BatteryElements
{
public:
	static float current;
	static float voltage;
	static float temprature;
};
class BatterySpecification:public BatteryElements
{
public:
	void BatterySpecificationPrinter();
};
class CurrentIndicator :public BatteryElements
{
public:
	static float currentMinThreshould;
	static float currentMaxThreshould;
	bool currentStatus();
	
};
class VoltageIndicator :public BatteryElements
{
public:
	static float voltageMinThreshould;
	static float vOltageMaxThreshould;
	bool voltageStatus();
	
};
class TempratureIndicator :public BatteryElements
{
public:
	static float tampratureMinThreshould;
	static float temperatureMaxThreshould;
	bool tempratureStatus();
	
};
class BatteryIndicator :public TempratureIndicator,public VoltageIndicator,public CurrentIndicator
{
public:
	BatteryIndicator() {}
	BatteryIndicator(float temp, float vol, float curr);
	
};
class BatteryChargingCheck :public BatteryIndicator
{
public:
	static int fullBatteryStatus;
	static int lowBatteryStatus;
	BatteryChargingCheck() {}
	bool batteryRequirements_For_Charging();
	

};
class StatusOfCharge:public BatteryChargingCheck
{
public:
	static int remainBatteryStatus;
	StatusOfCharge() {}
	bool StatusOfBatteryCharge(float remainBatteryStatus);
	
};
class wheaterIndicator :public BatteryIndicator
{
public:
	static float hotWeather;
	static float coldWeather;
	static float todaysTemperature;
	void TodaysTemperature(float temp);
	bool wheatherStatus();
};
