#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//problem 1, 6, 8 & 11 functions
double avg_per_year (double LandAvgTemp[], int start, int end)
{
	//adds up the value between start and end indexes of array
    double sum = 0.0, average;
    for (int i = start; i <= end; i++)
    {
        sum += LandAvgTemp[i];
        average = sum/12.0; //only 12 months in a year
    }
    
    return average;
}

//problem 2 & 9 functions
double findAverageForCentury(double temps[], int start, int end){
	
	double avg = 0;
	
	//finding the index by seeing how far from 1750 to be start value by month
	//will end at how far the end value is from 1750 in months 
	for (int i = (start-1750)*12; i < ((end-1750)*12); i++){
	
		avg += temps[i];
	}
	
	//will find how many years were accounted for in that century by the 12 months per year
	return(avg/((end-start)*12));
}

//problem 3 & 10 functions
double findAverageForMonth(double temps[], int months[], int month,  int start, int end){
	
	double avg = 0;
	
	//starts at 1850, and goes until the very end (2015)
	for (int i = (start-1750)*12; i < 3192; i++){
		
		if (month == months[i]) {
			avg += temps[i];
		}
	}
	
	return(avg/(end-start+1));
}

//problem 4 functions
void avgLandTempMonthColdHot(double landAvgMonth[], double *coldTemp, double *hotTemp ,int *monthCold, int *yearCold, int *monthHot, int *yearHot, int year){
   
    //using pointers to find both highest and lowest at the same time, compares just one year of data, main function repeats for every year
    for(int i = 0; i < 12; i++){
        if(landAvgMonth[i] <= *coldTemp){
            *coldTemp = landAvgMonth[i];
            *monthCold = i;
            *yearCold = year;
        }
        if(landAvgMonth[i] >= *hotTemp){
            *hotTemp = landAvgMonth[i];
            *monthHot = i;
            *yearHot = year;
        }
    }
}

//problem 5 functions
double sorter_low(double AvgTempYear[])
{
    int i = 0;
    double low; // temporary value
    low = AvgTempYear[i];

	//out of the 256 years in this problems data set
    for (i = 1; i < 256; i++){
        if (low > AvgTempYear[i]){
            low = AvgTempYear[i];
        }
    }
    return(low);
}

double sorter_high(double AvgTempYear[]) // same as sorter_low but finds highest
{
    int i = 0;
    double high; // temporary value
    high = AvgTempYear[i];

    for (i = 1; i < 256; i++){
        if (high < AvgTempYear[i]){
            high = AvgTempYear[i];
        }
    }
    return(high);
}

//problem 7 functions
double avg_per_year_century(double LandAvgTemp[], int startValue){
    double yearlyAverage = 0;
    for(int i = 0; i<12 ; i++){
        yearlyAverage += LandAvgTemp[i+startValue];
    }
    yearlyAverage = yearlyAverage/12;
    return(yearlyAverage);
}

//-------------------------------------------------------------------------------------------//

int main (void) {
	
//READING FILE PROCESS

	//opening the data file
	FILE *globalTemp;
	globalTemp = fopen("GlobalTemperatures.csv", "r");
	int i; //used for looping
	
	//initializing all the arrays that will store all data
	char buffer[1000];
	char *dates[3192];
	int years[3192];
	int months[3192];
	double LandAvgTemp[3192]; 
	double LandAvgTempUnc[3192];
	double LandMaxTemp[3192]; 
	double LandMaxTempUnc[3192];
	double LandMinTemp[3192]; 
	double LandMinTempUnc[3192];
	double LandOceanAvgTemp[3192]; 
	double LandOceanAvgTempUnc[3192];

	//initial line read of the titles
	fgets(buffer, sizeof(buffer), globalTemp);
	
	//reading the file
	for (i = 0; i < 3192; i++){
		
		//extracting all comma seperated values
		fgets(buffer, sizeof(buffer), globalTemp);
		dates[i] = strtok (buffer, ",");
		LandAvgTemp[i] = atof(strtok (NULL, ","));
		LandAvgTempUnc[i] = atof(strtok (NULL, ","));
		LandMaxTemp[i] = atof(strtok (NULL, ","));
		LandMaxTempUnc[i] = atof(strtok (NULL, ","));
		LandMinTemp[i] = atof(strtok (NULL, ","));
		LandMinTempUnc[i] = atof(strtok (NULL, ","));
		LandOceanAvgTemp[i] = atof(strtok (NULL, ","));
		LandOceanAvgTempUnc[i] = atof(strtok (NULL, ","));
		
		//extracting the date into year and months
		years[i] = atoi(strtok (dates[i], "-"));
		months[i] = atoi(strtok (NULL, "-"));

	}

	//after scanning all data, no need to access file anymore
	fclose(globalTemp);
	
//-------------------------------------------------------------------------------------------------//
	
	//problem 1
	printf("**Problem 1**\n\n");
    
	int frontPosition, endPosition, size, j;
    double AvgTempYear[256];

    size = 12; // 12 months in a year
    frontPosition = 120; // 1760 starts at LandAvgTemp[120]
    j = 0; // counter

    // loops while the "start position" is less than the size of the LandAvgTemp array
    while (frontPosition < 3192)
    {
        // calculating end position for the function (updates as the loop runs)
        endPosition = frontPosition + size - 1;

        AvgTempYear[j] = avg_per_year(LandAvgTemp, frontPosition, endPosition); // putting the calculations into an array
        frontPosition += size; // changes the starting position (updating as loop runs)
        j ++; // counter
    }
    
    //printing output for just 20 lines to demonstrate output... get from wallace soon
    printf("Temperature(c)   Years\n");
    for (int i = 0; i < 256; i++){
        printf("%lf         %d\n", AvgTempYear[i], (1760+i));
    }

//-------------------------------------------------------------------------------------------------//

    //problem 2
    printf("\n**Problem 2**\n\n");
    printf("The Average Land Temperatures for Each Century between the 18th to 21st century is as follows:\n");
    
    printf("18th Century: %lf Celsius\n", findAverageForCentury(LandAvgTemp, 1760, 1800));
	printf("19th Century: %lf Celsius\n", findAverageForCentury(LandAvgTemp, 1800, 1900));
	printf("20th Century: %lf Celsius\n", findAverageForCentury(LandAvgTemp, 1900, 2000));
	printf("21st Century: %lf Celsius\n", findAverageForCentury(LandAvgTemp, 2000, 2016));
    
//-------------------------------------------------------------------------------------------------//

    //problem 3
    printf("\n**Problem 3**\n\n");
    
    char monthNames[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    for (int k = 1; k <= 12; k++){
		printf( "%10s: %lf\n", monthNames[k-1], findAverageForMonth(LandAvgTemp, months, k, 1900, 2015));
	}
    
//-------------------------------------------------------------------------------------------------//

    //problem 4
    printf("\n**Problem 4**\n\n");
    
    double monthlyAvgTempsColdestHottest[266][12];
    double coldTemp, hotTemp;
    int monthCold = 0, monthHot = 0, yearCold = 0, yearHot = 0;

    // for all filling a 2d array where the data is set up of columns being the month, and rows being the year
    for(int i = 0; i<266; i++){ 
        for(int j = 0; j<12; j++){
            monthlyAvgTempsColdestHottest[i][j] = LandAvgTemp[i*12+j];
        }
    }
    
    //initializing the first compartive value for the first comparison
    coldTemp = monthlyAvgTempsColdestHottest[0][0];
    hotTemp = monthlyAvgTempsColdestHottest[0][0];
    
    //comparing the value of every single element of data to find the hottest and coldest
    for(int i = 0; i<266; i++){
        avgLandTempMonthColdHot(monthlyAvgTempsColdestHottest[i], &coldTemp, &hotTemp , &monthCold, &yearCold, &monthHot, &yearHot, i);
    }

	//final print statements
    printf("The Coldest monthly temperature recorded is %lf celsius in %s %d \n", coldTemp, monthNames[monthCold], yearCold+1750);
    printf("The Hottest monthly temperature recorded is %lf celsius in %s %d \n", hotTemp, monthNames[monthHot], yearHot+1750);
    
//-------------------------------------------------------------------------------------------------//

	//problem 5
	printf("\n**Problem 5**\n\n");
    
    double low, high; 
    low = sorter_low(AvgTempYear);
    high = sorter_high(AvgTempYear);

    // loop1 to determine the coldest year
    i = 0;
    while (low != AvgTempYear[i])
    {
        i += 1;
    }
    printf("The coldest year was: %d\n", (1750+i));

    // loop2 to determine the hottest year
    i = 0;
    while (high != AvgTempYear[i])
    {
        i += 1;
    }
    printf("The hottest year was: %d\n", (1750+i));
     
//-------------------------------------------------------------------------------------------------//
    
    //problem 6
    
    // initializing a file to write to 
    FILE* problem6data;
    problem6data = fopen("problem6.txt", "w");
    
    // writing to the file using a for loop, displaying the data in two columns: years and temperatures
    for (i = 0; i < 256; i++){
        fprintf(problem6data, "%d    %lf\n", (1760+i), AvgTempYear[i]);
        
    }

    fclose(problem6data);

//-------------------------------------------------------------------------------------------------//

	//Problem 7
    double yearlyAvgLandTemps19[100];
    double yearlyAvgLandTemps20[100];

	//loops while the "start position" is less than the size of the LandAvgTemp array
    for(int i = 0; i<100; i++){
        yearlyAvgLandTemps19[i] = avg_per_year_century(LandAvgTemp, 600+i*12);
        yearlyAvgLandTemps20[i] = avg_per_year_century(LandAvgTemp, 1800+i*12);
    }
    
    FILE *problem7data;
    problem7data = fopen("problem7.txt", "w");

    for (int i = 0; i < 100; i++){
        fprintf(problem7data, "%d     %lf     %lf \n", i+1, yearlyAvgLandTemps19[i], yearlyAvgLandTemps20[i]);
    }

    fclose(problem7data);
    printf("\n");

//-------------------------------------------------------------------------------------------------//

	//problem 8
	FILE *problem8data;
	
	problem8data = fopen("problem8.txt", "w");
	
	// AvgTempYear already does the first column, now with Max and Min Temps
	
	double MaxTempYear[256];
	frontPosition = 120; //keep all of them consistent index values even though starting at 1850
	j = 0;
	
	while (frontPosition < 3192)
    {
        // calculating end position for the function (updates as the loop runs)
        endPosition = frontPosition + size - 1;

        MaxTempYear[j] = avg_per_year(LandMaxTemp, frontPosition, endPosition); // putting the calculations into an array
        frontPosition += size; // changes the starting position (updating as loop runs)
        j += 1; // counter
    }
    
    double MinTempYear[256];
    frontPosition = 120;
    j = 0;
    
    while (frontPosition < 3192)
    {
        // calculating end position for the function (updates as the loop runs)
        endPosition = frontPosition + size - 1;

        MinTempYear[j] = avg_per_year(LandMinTemp, frontPosition, endPosition); // putting the calculations into an array
        frontPosition += size; // changes the starting position (updating as loop runs)
        j += 1; // counter
    }
	
	//writing all data from arrays into data file
	for (int l = 90; l < 256; l++){ //90 years from 1760 start to 1850 start
		
		fprintf(problem8data, "%d %lf %lf %lf\n", (1760+l), AvgTempYear[l], MaxTempYear[l], MinTempYear[l]);
	}
	
	fclose(problem8data);
	
//-------------------------------------------------------------------------------------------------//	
	
	//problem 9
	FILE *problem9data;
	
	problem9data = fopen("problem9.txt", "w");
	
	// Average Land Temp for Centuries is already calculated will just have to recalculate 19th century to be 1850-1899 only
	
	fprintf(problem9data, "%lf %lf %lf\n", findAverageForCentury(LandAvgTemp, 1850, 1900), findAverageForCentury(LandMaxTemp, 1850, 1900), findAverageForCentury(LandMinTemp, 1850, 1900));
	fprintf(problem9data, "%lf %lf %lf\n", findAverageForCentury(LandAvgTemp, 1900, 2000), findAverageForCentury(LandMaxTemp, 1900, 2000), findAverageForCentury(LandMinTemp, 1900, 2000));
	fprintf(problem9data, "%lf %lf %lf\n", findAverageForCentury(LandAvgTemp, 2000, 2016), findAverageForCentury(LandMaxTemp, 2000, 2016), findAverageForCentury(LandMinTemp, 2000, 2016));
	
	fclose(problem9data);
	
//-------------------------------------------------------------------------------------------------//
	
	//problem 10
	FILE *problem10data;
	
	problem10data = fopen("problem10.txt", "w");	
	
	for (int k = 1; k <= 12; k++){
		fprintf(problem10data, "%d %lf %lf\n", k, findAverageForMonth(LandAvgTemp, months, k, 2000, 2015), findAverageForMonth(LandAvgTempUnc, months, k, 2000, 2015));
	}
	
	fclose(problem10data);
	
//-------------------------------------------------------------------------------------------------//

	//problem 11
	
	double AvgTempYear2[166]; // for the averages from 1850 to 2015
    double AvgTempOcean[166];
    size = 12; // 12 months in a year
    frontPosition = 1200; // 1850 starts at LandAvgTemp[1200]
    i = 0; // counter
    // loops while the "start position" is less than the size of the LandAvgTemp array
    while (frontPosition < 3192)
    {
        // calculating end position for the function (updates as the loop runs)
        endPosition = frontPosition + size - 1;

        double avgTemp = avg_per_year(LandAvgTemp, frontPosition, endPosition);
        double avgTempOcean = avg_per_year(LandOceanAvgTemp, frontPosition, endPosition);
        
        AvgTempYear2[i] = avgTemp; // putting the calculations into an array
        AvgTempOcean[i] = avgTempOcean; 
        frontPosition += size; // changes the starting position (updating as loop runs)
        i += 1; // counter
    }
    
    // declaring a file to put data for the plot 
    FILE* problem11data;
    problem11data = fopen("problem11.txt", "w");
    
    for (i = 0; i < 166; i++){
		
		fprintf(problem11data, "%d    %lf   %lf\n", (1850+i) , AvgTempYear2[i], AvgTempOcean[i]);
		
	}
    
    fclose(problem11data);
	
	return (0);
}
