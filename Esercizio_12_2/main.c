#include <stdio.h>

struct date{
	unsigned int hour;
	unsigned int minute;
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

unsigned int hour_temp = 0;
unsigned int minute_temp = 0;
unsigned int day_temp = 0;
unsigned int month_temp = 0;
unsigned int year_temp = 0;
char line[100];
unsigned long int result = 0;

int isleap(unsigned int year);
unsigned int daysinmonth(unsigned int month, unsigned int year);
unsigned long int convert_in_days(unsigned int hour1, unsigned int minute1, unsigned int day1, unsigned int month1, unsigned int year1,
	unsigned int hour2, unsigned int minute2, unsigned int day2, unsigned int month2, unsigned int year2);

int main(void){
	while(1){
		printf("Start day) h m d m yyyy: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%u %u %u %u %u", &hour_temp, &minute_temp, &day_temp, &month_temp, &year_temp);
		struct date start_date = {
			hour_temp,
			minute_temp,
			day_temp,
			month_temp,
			year_temp,
		};
		printf("End day) h m d m yyyy: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%u %u %u %u %u", &hour_temp, &minute_temp, &day_temp, &month_temp, &year_temp);
		struct date end_date = {
			hour_temp,
			minute_temp,
			day_temp,
			month_temp,
			year_temp,
		};
		if((start_date.year > end_date.year) ||
		(start_date.year == end_date.year && start_date.month > end_date.month) ||
		(start_date.year == end_date.year && start_date.month == end_date.month && start_date.day > end_date.day) ||
		(start_date.year == end_date.year && start_date.month == end_date.month && start_date.day == end_date.day && start_date.hour > end_date.hour) ||
		(start_date.year == end_date.year && start_date.month == end_date.month && start_date.day == end_date.day && start_date.hour == end_date.hour && start_date.minute > end_date.minute)){
			printf("Wrong immission");
			break;
		}
		result = convert_in_days(start_date.hour, start_date.minute, start_date.day, start_date.month, start_date.year,
			end_date.hour, end_date.minute, end_date.day, end_date.month, end_date.year);
		printf("Minutes: %lu\n", result);
	}
	return 0;
}

unsigned int daysinmonth(unsigned int month, unsigned int year){
	if(month == 11 || month == 4 || month == 6 || month == 9)
		return 30;
	else if(month == 2 && isleap(year))
		return 29;
	else if(month == 2 && !isleap(year))
		return 28;
	else
		return 31;
}

int isleap(unsigned int year){
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

unsigned long int convert_in_days(unsigned int hour1, unsigned int minute1, unsigned int day1, unsigned int month1, unsigned int year1,
	unsigned int hour2, unsigned int minute2, unsigned int day2, unsigned int month2, unsigned int year2){
	unsigned int i;
	int leap = 0;
	unsigned int ndays = 0;
	unsigned long int nminutes = 0;
	
	if(year1 != year2){	// Anni diversi
		i = minute1 + 1;
		while(i <= 60){
			++nminutes;
			++i;
		}
		
		i = hour1 + 1;
		while(i <= 24){
			nminutes += 60;
			++i;
		}

		// Conto i giorni fino alla fine di month1
		i = day1 + 1;
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
		i = 1;
		while(i <= month2 - 1){
			ndays += daysinmonth(i, year2);
			++i;
		}
		
		// Arrivato a month2, conto i giorni per arrivare a day2-1
		i = 1;
		while(i <= day2 - 1){
			ndays += 1;
			++i;
		}
		
		// Arrivato a day2-1, conto i minuti per arrivare a hour2-1
		i = 1;
		while(i <= hour2 - 1){
			nminutes += 60;
			++i;
		}
		
		// Arrivato a hour2-1, conto i minuti per arrivare a minute2
		i = 1;
		while(i <= minute2){
			++nminutes;
			++i;
		}
		nminutes += (ndays - 1) * 24 * 60;
	}
	else if(year1 == year2 && month1 != month2){	// Stesso anno ma mese diverso
		i = minute1 + 1;
		while(i <= 60){
			++nminutes;
			++i;
		}
		
		i = hour1 + 1;
		while(i <= 24){
			nminutes += 60;
			++i;
		}
		
		// Conto i giorni fino alla fine di month1
		i = day1 + 1;
		while(i <= daysinmonth(day1, year1)){
			++ndays;
			++i;
		}
		
		// Conto i giorni nei mesi in year2 per arrivare a month2-1
		i = month1 + 1;
		while(i <= month2 - 1){
			ndays += daysinmonth(i, year2);
			++i;
		}
		
		// Arrivato a month2, conto i giorni per arrivare a day2
		i = 1;
		while(i <= day2 - 1){
			ndays += 1;
			++i;
		}
		
		// Arrivato a day2-1, conto i minuti per arrivare a hour2-1
		i = 1;
		while(i <= hour2 - 1){
			nminutes += 60;
			++i;
		}
		
		// Arrivato a hour2-1, conto i minuti per arrivare a minute2
		i = 1;
		while(i <= minute2){
			++nminutes;
			++i;
		}
		nminutes += (ndays - 1) * 24 * 60;
	}
	else if(year1 == year2 && month1 == month2 && day2 != day1){	// Stesso anno, mese ma giorni diversi
		i = minute1 + 1;
		while(i <= 60){
			++nminutes;
			++i;
		}
		
		i = hour1 + 1;
		while(i <= 24){
			nminutes += 60;
			++i;
		}
		
		
		i = day1 + 1;
		while(i <= day2 - 1){
			ndays += 1;
			++i;
		}
		
		// Arrivato a day2-1, conto i minuti per arrivare a hour2-1
		i = 1;
		while(i <= hour2 - 1){
			nminutes += 60;
			++i;
		}
		
		// Arrivato a hour2-1, conto i minuti per arrivare a minute2
		i = 1;
		while(i <= minute2){
			++nminutes;
			++i;
		}
	}
	else if(year1 == year2 && month1 == month2 && day2 == day1 && hour1 != hour2){	// Stesso giorno
		i = minute1 + 1;
		while(i <= 60){
			++nminutes;
			++i;
		}
		i = hour1 + 1;
		while(i <= hour2 - 1){
			nminutes += 60;
			++i;
		}
		i =  1;
		while(i <= minute2){
			++nminutes;
			++i;
		}
	}
	else if(year1 == year2 && month1 == month2 && day2 == day1 && hour1 == hour2 && minute1 != minute2){	// Stesso giorno
		i = minute1 + 1;
		while(i <= minute2){
			++nminutes;
			++i;
		}
	}
	else
		nminutes = 0;
	//--ndays;	// Tolgo un giorno per non contare il giorno di partenza
	//--nminutes;	// Tolgo un minuto per non contare il minuto di partenza
	return nminutes;
}