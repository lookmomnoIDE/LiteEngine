#ifndef KINGDOM_H
#define KINGDOM_H


#include <string>
#include <vector>



class Kingdom
{
public:
	struct Job 
	{
		std::string name;
		unsigned int numWorkers;

	};
	double hiddenPop = 500.0;
	unsigned int population = hiddenPop;
	int gold = 500;
	int income = 5;
	unsigned int militaryPower = 0;
	float conscriptionRate = .15;
	std::vector<Job> jobsList;
	Kingdom()
	{

	}
	Kingdom(unsigned int population, int gold, int income, float conscriptionRate)
	:population(population), gold(gold), income(income), conscriptionRate(conscriptionRate)
	{

	}
	~Kingdom()
	{

	}

};



#endif