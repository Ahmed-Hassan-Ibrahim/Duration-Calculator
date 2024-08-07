#include <stdio.h>
#include <stdlib.h>

#define check_scan(x) \
    while(scanf("%d", &x) != 1 || (getchar() != '\n'))\
    {\
        while (getchar() != '\n');\
        printf("Invalid input. Please enter a number: ");\
    }\

// define global variables current date
int current_day = 0, current_month = 0, current_year = 0;

// Check if i/p year is valid
int check_year(int year)
{
    if(year > current_year || year < 1)
        return 1;
    return 0;
}

// Check if i/p month is valid
int check_month(int month, int year ,int current)
{
    if(month > 12 || month < 1)
        return 1;
    if(year == current_year && !current)
    {
        if(month > current_month)
            return 1;
    }
    return 0;
}

// Check if i/p day is valid
int check_day(int day, int month, int year, int current)
{
    if(day < 1)
        return 1;

    if(year == current_year && month == current_month && !current)
    {
        if(day > current_day)
            return 1;
    }

    switch(month)
    {
    case 1:
        if(day > 31)
            return 1;
        break;

    case 2:
        if(year % 4 == 0 )
        {
            if(day > 29)
                return 1;
        }
        else
        {
            if(day > 28)
                return 1;
        }
        break;

    case 3:
        if(day > 31)
            return 1;
        break;

    case 4:
        if(day > 30)
            return 1;
        break;

    case 5:
        if(day > 31)
            return 1;
        break;

    case 6:
        if(day > 30)
            return 1;
        break;
    case 7:
        if(day > 31)
            return 1;
        break;
    case 8:
        if(day > 31)
            return 1;
        break;
    case 9:
        if(day > 30)
            return 1;
        break;
    case 10:
        if(day > 31)
            return 1;
        break;
    case 11:
        if(day > 30)
            return 1;
        break;
    default:
        if(day > 31)
            return 1;
        break;
    }
    return 0;
}

// Return correct number of days for each month
int calculate_day(int month, int year)
{
    switch(month)
    {
    case 1:
        return 31; break;

    case 2:
        if(year % 4 == 0 )
            return 29;
        else
            return 28;
        break;

    case 3:
        return 31; break;

    case 4:
        return 30; break;

    case 5:
        return 31; break;

    case 6:
        return 30; break;

    case 7:
        return 31; break;

    case 8:
        return 31; break;

    case 9:
        return 30; break;

    case 10:
        return 31; break;

    case 11:
        return 30; break;

    default:
        return 31; break;
    }
}

int main()
{
    while(1)
    {
        // Define variables
        int year = 0, month = 0, day = 0, sum_year = 0, sum_day = 0, sum_month = 0, m = 0, n = 0, temp_month = 0, temp_year = 0;;

        // i/p end year and check
        printf("End date data=======================================================\n");
        printf("Enter year: ");
        check_scan(current_year);

        // i/p end month and check
        printf("Enter month: ");
        check_scan(current_month);
        while(check_month(current_month, current_year, 1))
        {
            printf("\nInvalid month input. Try again: ");
            check_scan(current_month);
        }

        // i/p end day and check
        printf("Enter day: ");
        check_scan(current_day);
        while(check_day(current_day, current_month, current_year, 1))
        {
            printf("\nInvalid day input. Try again: ");
            check_scan(current_day);
        }

        // i/p start year and check
        printf("\nStart date data=====================================================\n");
        printf("Enter year: ");
        check_scan(year);
        while(check_year(year))
        {
            printf("\nInvalid year input. Try again: ");
            check_scan(year);
        }

        // i/p start month and check
        printf("Enter month: ");
        check_scan(month);
        while(check_month(month, year, 0))
        {
            printf("\nInvalid month input. Try again: ");
            check_scan(month);
        }

        // i/p start day and check
        printf("Enter day: ");
        check_scan(day);
        while(check_day(day, month, year, 0))
        {
            printf("\nInvalid day input. Try again: ");
            check_scan(day);
        }

        if(year != current_year)
        {
            // Calculate total days until the i/p year completes except i/p month
            for(int i = month+1; i <= 12; i++)
            {
                m = calculate_day(i, year);
                for(int j = m; j >= 1; j--)
                    sum_day++;
            }
            sum_day--;

            // Calculate total days between i/p year and current year
            for(int i = current_year-1; i > year; i--)
            {
                for(int j = 12; j >= 1; j--)
                {
                    m = calculate_day(j, i);
                    for(int k = m; k >= 1; k--)
                        sum_day++;
                }
            }

            // Calculate total days for the current year except current month
            for(int i = current_month-1; i >= 1; i--)
            {
                m = calculate_day(i, current_year);
                for(int j = m; j >= 1; j--)
                    sum_day++;
            }

            // Calculate days for the i/p month
            m = calculate_day(month, year);
            for(int i = day; i <= m; i++)
                sum_day++;

            // Calculate days for current month
            for(int i = current_day; i >= 1; i--)
                sum_day++;


            temp_month = month, temp_year = year;
            for(int i = 1; i < sum_day; i++)
            {
                if(i == calculate_day(temp_month, temp_year))
                {
                    sum_month++;
                    temp_month++;
                    if(temp_month == 12)
                        temp_year++;
                    if(temp_month > 12)
                        temp_month = 1;
                    sum_day -= i;
                    i = 1;
                }
                if(sum_month == 12)
                {
                    sum_year++;
                    sum_month = 0;
                }
            }
        }

        else
        {
            if(month == current_month)
            {
                // Just calculate total days if i/p month is the current month
                for(int j = current_day; j >= day; j--)
                    sum_day++;
            }
            else
            {
                // Calculate total number of days
                for(int i = current_month; i >= month; i--)
                {
                    if(i == current_month)
                    {
                        m = current_day;
                        n = 1;
                    }
                    else if(i == month)
                    {
                        m = calculate_day(i, current_year);
                        n = day;
                    }
                    else
                    {
                        m = calculate_day(i, current_year);
                        n = 1;
                    }

                    for(int j = m; j >= n; j--)
                        sum_day++;
                }
                temp_month = month;
                for(int i = 1; i < sum_day; i++)
                {
                    if(i == calculate_day(temp_month, current_year))
                    {
                        sum_month++;
                        temp_month++;
                        if(temp_month > 12)
                            temp_month = 1;
                        sum_day -= i;
                        i = 1;
                    }
                }
            }
            sum_day--;
        }

        // Print output
        printf("\nNumber of years: %d", sum_year);
        printf("\nNumber of Months: %d", sum_month);
        printf("\nNumber of Days: %d\n", sum_day);
        printf("*************************************************************************************************\n\n\n");
    }

    return 0;
}
