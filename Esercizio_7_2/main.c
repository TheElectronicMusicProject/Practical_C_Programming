#include <stdio.h>

int day1 = 0;
int month1 = 0;
int year1 = 0;
int day2 = 0;
int month2 = 0;
int year2 = 0;
char line1[11];
char line2[11];
int leap = 0;

int ndays = 0;

int isleap(int year);
int daysinmonth(int month, int year);

int main(void){
	while(1){
		printf("Start day) d m yyyy: ");
		fgets(line1, sizeof(line1), stdin);
		sscanf(line1, "%d %d %d", &day1, &month1, &year1);
		printf("End day) d m yyyy: ");
		fgets(line2, sizeof(line2), stdin);
		sscanf(line2, "%d %d %d", &day2, &month2, &year2);
		if((year1 > year2) || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)){
			printf("Wrong immission");
			break;
		}
		int i, k;
		leap = 0;
		ndays = 0;
		
		if(year1 != year2){	// Anni diversi
			// Conto i giorni fino alla fine di month1
			i = day1;
			while(i <= daysinmonth(day1, year1)){
				++ndays;
				++i;
			}
			
			// Conto i giorni da month1+1 a fine anno
			i = month1 + 1;
			while(i <= 12){
				ndays += daysinmonth(i, year2 - 1);
				++i;
			}
			
			// Conto i giorni che intercorrono tra year1 e year2-1
			i = year1 + 1;
			while(i <= year2 - 1){
				leap = isleap(i);
				leap == 0 ? (ndays += 365) : (ndays += 366);
				++i;
			}
			
			// Conto i giorni nei mesi in year2 per arrivare a month2-1
			k = 1;
			while(k <= month2 - 1){
				ndays += daysinmonth(k, year2);
				++k;
			}
			
			// Arrivato a month2, conto i giorni per arrivare a day2
			i = 1;
			while(i <= day2){
				ndays += 1;
				++i;
			}
		}
		else if(year1 == year2 && month1 != month2){	// Stesso anno ma mese diverso
			// Conto i giorni fino alla fine di month1
			i = day1;
			while(i <= daysinmonth(day1, year1)){
				++ndays;
				++i;
			}
			
			// Conto i giorni nei mesi in year2 per arrivare a month2-1
			k = month1 + 1;
			while(k <= month2 - 1){
				ndays += daysinmonth(k, year2);
				++k;
			}
			
			// Arrivato a month2, conto i giorni per arrivare a day2
			i = 1;
			while(i <= day2){
				ndays += 1;
				++i;
			}
		}
		else if(year1 == year2 && month1 == month2 && day2 != day1){	// Stesso anno, mese ma giorni diversi
			// Arrivato a month2, conto i giorni per arrivare a day2
			i = day1;
			while(i <= day2){
				ndays += 1;
				++i;
			}
		}
		else	// Stesso giorno
			ndays = 1;
		--ndays;	// Tolgo un giorno per non contare il giorno di partenza
		printf("The difference has %d days\n", ndays);
	}
	return 0;
}

int daysinmonth(int month, int year){
	if(month == 11 || month == 4 || month == 6 || month == 9)
		return 30;
	else if(month == 2 && isleap(year))
		return 29;
	else if(month == 2 && !isleap(year))
		return 28;
	else
		return 31;
}

int isleap(int year){
	char flag = 0;
	if(year % 4 == 0){
		if(year % 100 == 0)
			if(year % 100 == 0)
				flag = 1;
			else
				flag = 0;
		else
			flag = 1;
	}else
		flag = 0;
	return flag;
}