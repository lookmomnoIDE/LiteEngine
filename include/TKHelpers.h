#ifndef TKHELPERS_H
#define TKHELPERS_H


#include <string>
#include <vector>


class TKHelpers
{
public:

	static constexpr unsigned int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	static std::string getDay(unsigned int dayCounter)
	{
		unsigned int day = dayCounter % 7;
		std::string sDay = "";
		switch(day)
		{
			case 0:
				return sDay = "Sunday";
			case 1:
				return sDay = "Monday";
			case 2:
				return sDay = "Tuesday";
			case 3:
				return sDay = "Wednesday";
			case 4:
				return sDay = "Thursday";
			case 5:
				return sDay = "Friday";
			case 6:
				return sDay = "Saturday";
		}
	}

	static std::string getMonth(unsigned int dayCounter)
	{
		unsigned int month = 0;
		unsigned int day = dayCounter % 365;
		for(unsigned int i = 0; i < 12; i++)
		{
			if(day == 0)
			{
				i = 12;
				day = 31;
				month = 11;
			}
			if(day <= daysInMonth[i])
			{
				i = 12;
			}
			else if(day > daysInMonth[i])
			{
				day -= daysInMonth[i];
				month++;
			}
		}

		std::string sDay = "";
		std::string sDayCounter = std::to_string(day);
		switch(month % 12)
		{
			case 0:
				return sDay = " January " + sDayCounter + ", ";
			case 1:
				return sDay = " February " + sDayCounter + ", ";
			case 2:
				return sDay = " March " + sDayCounter + ", ";
			case 3:
				return sDay = " April " + sDayCounter + ", ";
			case 4:
				return sDay = " May " + sDayCounter + ", ";
			case 5:
				return sDay = " June " + sDayCounter + ", ";
			case 6:
				return sDay = " July " + sDayCounter + ", ";
			case 7:
				return sDay = " August " + sDayCounter + ", ";
			case 8:
				return sDay = " September " + sDayCounter + ", ";
			case 9:
				return sDay = " October " + sDayCounter + ", ";
			case 10:
				return sDay = " November " + sDayCounter + ", ";
			case 11:
				return sDay = " December " + sDayCounter + ", ";
		}

	}


	static std::string getYear(unsigned int dayCounter, unsigned int startingYear)
	{
		unsigned int year = startingYear;
		while(dayCounter > 365)
		{
			year += 1;
			dayCounter -= 365;
		}
		std::string text = std::to_string(year);
		return text;
	}


	static std::string calculateDate(unsigned int dayCounter)
	{
		std::string date = "";
		date += getDay(dayCounter);
		date += getMonth(dayCounter);
		date += getYear(dayCounter, 1000);

		return date;
	}
};



#endif