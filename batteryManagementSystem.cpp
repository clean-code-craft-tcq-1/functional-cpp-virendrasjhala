#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;


class BatteryElements
{
public:
	 static float current;
	 static float voltage;
	 static float temprature;
};
class CurrentIndicator :public BatteryElements
{
public:
	static float currentMinThreshould;
	static float currentMaxThreshould;
	bool currentStatus()
	{
		if (currentMinThreshould >= current || currentMaxThreshould <= current)
		{
			cout << "Charge current Rate out of range!\n";
			return false;
		}
	}
};
class VoltageIndicator :public BatteryElements
{
public:
	static float voltageMinThreshould;
	static float vOltageMaxThreshould;
	bool voltageStatus()
	{
		if (voltageMinThreshould >= voltage || vOltageMaxThreshould <= voltage)
		{
			cout << "Charge voltage Rate out of range!\n";
			return false;
		}
	}
};
class TempratureIndicator :public BatteryElements
{
public:
	static float tampratureMinThreshould;
	static float temperatureMaxThreshould;
	bool tempratureStatus()
	{
		if (tampratureMinThreshould >= temprature || temperatureMaxThreshould <= temprature)
		{
			cout << "Charge tamperature Rate out of range!\n";
			return false;
		}
	}
};
class BatteryIndicator:public CurrentIndicator,public VoltageIndicator,public TempratureIndicator
{
public:
	BatteryIndicator() {}
	BatteryIndicator(float curr, float vol, float temp)
	{
		current = curr;
		voltage = vol;
		temprature = temp;
	}

};
class BatteryChargingCheck:public BatteryIndicator
{
public:
	BatteryChargingCheck() {}
	bool batteryRequirements_For_Charging()
	{
		if (currentStatus() && voltageStatus() && tempratureStatus())
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
};
class StatusOfCharge 
{
public:
	StatusOfCharge() {}
	bool StatusOfBatteryCharge(float remainBatteryStatus)
	{
		if (remainBatteryStatus >= 80 || remainBatteryStatus < 20)
		{
			cout << "Charge Rate out of range!\n" << endl;
			return false;
		}
		return true;
	}
};
float CurrentIndicator::currentMinThreshould=0.8;
float CurrentIndicator::currentMaxThreshould=1.2;
float VoltageIndicator::voltageMinThreshould=3;
float VoltageIndicator::vOltageMaxThreshould=6;
float TempratureIndicator::tampratureMinThreshould=-20;
float TempratureIndicator::temperatureMaxThreshould=50;
float BatteryElements::current=0;
float BatteryElements::voltage=0;
float BatteryElements::temprature=0;

int main() {

	StatusOfCharge statusofcharge;
	assert(statusofcharge.StatusOfBatteryCharge(70)==true);
	BatteryIndicator batterychargingCheck1(1.0, 4, 21);
	BatteryChargingCheck battery_charging_check;
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);
	BatteryIndicator batterychargingCheck2(1.0, 4, 21);
	assert(battery_charging_check.batteryRequirements_For_Charging() == true);

	system("pause");
}
