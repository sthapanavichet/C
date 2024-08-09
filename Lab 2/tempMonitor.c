#include <stdio.h>
#define numDays 4

int main() 
{
	// Declaration and initialization 
	float LowTemp[numDays], HighTemp[numDays], TotalTemp = 0, TotalHighTemp = 0, TotalLowTemp = 0;
	float LowestPossibleTemp = -40, HighestPossibleTemp = 40;
	float LowestTemp = HighestPossibleTemp, HighestTemp = LowestPossibleTemp;
	float AverageLowTemp, AverageHighTemp, AverageTemp;
	int HighestTempIndex, LowestTempIndex;
	int Done = 0;
	int lengthLowTemp = sizeof(LowTemp) / sizeof(LowTemp[0]), lengthHighTemp = sizeof(HighTemp) / sizeof(HighTemp[0]);
	
	// Accepting and Validating User's Input 
	for (int i = 0; i < numDays; i++)
	{
		do 
		{
			printf("Enter Lowest Temperature for Day %d: ", i+1);
			scanf("%f", &LowTemp[i]);
			printf("Enter Highest Temperature for Day %d: ", i+1);
			scanf("%f", &HighTemp[i]);
			if (LowTemp[i] < LowestPossibleTemp || HighTemp[i] > HighestPossibleTemp || LowTemp[i] > HighTemp[i])
			{
				printf("Enter a valid input\n");
				Done = 0;
			}
			else
			{
				Done = 1;
			}			
		} while (Done == 0);
		
		// Storing all-time highest and lowest temperature
		if (LowTemp[i] < LowestTemp)
		{
			LowestTemp = LowTemp[i];
			LowestTempIndex = i+1;
		}
		if (HighTemp[i] > HighestTemp)
		{
			HighestTemp = HighTemp[i];
			HighestTempIndex = i+1;
		}
		// Total value of highest temperature, lowest temperature and overall temperature.
		TotalTemp += LowTemp[i] + HighTemp[i];
		TotalHighTemp += HighTemp[i];
		TotalLowTemp += LowTemp[i];
	}
	// calculaation of average of total temperature, total highest temperature, and total lowest temperature
	AverageTemp = TotalTemp / (lengthHighTemp + lengthLowTemp);
	AverageHighTemp = TotalHighTemp / lengthHighTemp;
	AverageLowTemp = TotalLowTemp / lengthLowTemp;

	// Output
	printf("The average for lowest temperature is %.1f\n", AverageLowTemp);
	printf("The average for highest temperature is %.1f\n", AverageHighTemp);
	printf("The highest temperature was %.1f in day %d\n", HighestTemp, HighestTempIndex);
	printf("The lowest temperature was %.1f in day %d\n", LowestTemp, LowestTempIndex);
	printf("The average temperature is %.1f\n", AverageTemp);

	return 0;
}
