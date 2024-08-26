//Calender management System

#include<stdio.h>
#include<unistd.h>
#include<malloc.h>
#include<stdlib.h>



int dayNumber( int day , int month , int year );
int print_calender( int year );
char *month_name(int);


int  t[] = { 0 , 3 , 2 , 5 , 0 , 3 , 5 , 1 , 4 , 6 , 2 , 4 };


void greet();

void greet() {

    //calender name

    puts("\t\t\t\t----------------------------------------------------");
    puts("\t\t\t\t|--------------------------------------------------|");
    puts("\t\t\t\t|------------  Calender Application ---------------|");
    puts("\t\t\t\t|--------------------------------------------------|");
    puts("\t\t\t\t----------------------------------------------------\n\n");
}

//Function returns the index of the
//day for date DD/MM/YYYY


int dayNumber( int day , int month , int year ) {

    year -= month < 3 ;

    return ( year + year / 4 - year / 100 + year / 400 + t[ month - 1 ] + day ) % 7 ;
}

int number_of_days_in_a_month( int month , int year ) {

    //its returns the how many days are present in a month such as jan has 31 days etc.

    if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {

        return 31;

    } else if ( month == 2 ) {

         if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            return 29;
         } else {
            return 28;
         }
    } else {

        return 30;
    }
}

char *month_name(int choice) {

    char *month;

    month = ( char* ) malloc(15 * sizeof(char));


    if ( choice == 1 ) {

        month = "January";

    } else if ( choice == 2 ) {

        month = "February";

    } else if ( choice == 3 ) {

        month = "March";

    } else if ( choice == 4 ) {

        month = "April";

    } else if ( choice == 5 ) {

        month = "May";

    } else if ( choice == 6 ) {

        month = "June";

    } else if ( choice == 7 ) {

        month = "July";

    } else if ( choice == 8 ) {

        month = "Auguest";

    } else if ( choice == 9 ) {

        month = "September";

    } else if ( choice == 10 ) {

        month = "October";

    } else if ( choice == 11 ) {

        month = "November";

    } else if ( choice == 12 ) {

        month = "December";

    }

    return month;
}

int main() {

    int year;

    greet();


    printf("\t\t\t\tEnter a Year: ");
    scanf("%d",&year);

    print_calender( year );

    return 0;
}

int print_calender( int year ) {

    int current = dayNumber(1,1,year);
    int k ;

    printf("\n\n\t\t\t\t\t\t    Year :  %d \n\n",year);


    for ( int i = 1 ; i <= 12 ; i++ )
    {
        puts("\n\n\t\t\t\t|--------------------------------------------------|");
          printf("\t\t\t\t\t\t     %s  ",month_name(i));
            puts("\n\t\t\t\t|--------------------------------------------------|\n\n");


            printf("\n\t\t\t\t SUN\tMON\tTUE\tWED\tTHUS\tFRI\tSAT\n");



            printf("\t\t\t\t ");


            for (  k = 0 ; k < current ; k++ )
            {
                printf("\t");
            }

            for ( int j = 1 ; j <=  number_of_days_in_a_month(i,year) ; j++ )
            {
                printf("%d\t",j);

                if ( ++k > 6 )
                {
                    k = 0;
                    printf("\n\t\t\t\t ");
                }
            }

            current = k;
    }
}
