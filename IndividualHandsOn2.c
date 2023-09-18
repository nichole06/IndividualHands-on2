#include <stdio.h>
#define sizeOfRows 4
#define sizeOfCols 6


void pressAnyKey()
{
    printf ("\n\n\n\nPress any key to continue. . .");
    getche();
}

void displayAllElements(int randNumbers[sizeOfRows][sizeOfCols])
{
    int rows, cols;

    for (rows = 0; rows < sizeOfRows; rows++)
    {
        printf ("Row #%d - ", rows + 1);

        for (cols = 0; cols < sizeOfCols; cols++)
        {
            printf ("%d ", randNumbers[rows][cols]);
        }
        printf ("\n");
    }
}

int countEven(int randNumbers[sizeOfRows][sizeOfCols])
{
    int rows, cols, even = 0;

    for (rows = 0; rows < sizeOfRows; rows++)
    {
        for (cols = 0; cols < sizeOfCols; cols++)
        {
            if (randNumbers[rows][cols] % 2 == 0)
            {
                even++;
            }
        }
    }

    return even;
}

int countOdd(int randNumbers[sizeOfRows][sizeOfCols])
{
    int rows, cols, odd = 0;

    for (rows = 0; rows < sizeOfRows; rows++)
    {
        for (cols = 0; cols < sizeOfCols; cols++)
        {
            if (randNumbers[rows][cols] % 2 != 0)
            {
                odd++;
            }
        }
    }

    return odd;
}

int largestNumberRow(int randNumbers[sizeOfRows][sizeOfCols], int getRows)
{
    int cols, largest;
    

    largest = randNumbers[getRows - 1][0];

    for (cols = 0; cols < sizeOfCols; cols++)
    {
        if (randNumbers[getRows - 1][cols] > largest)
        {
            largest = randNumbers[getRows - 1][cols];
        }
    }

    return largest;
}

int lowestNumberCol(int randNumbers[sizeOfRows][sizeOfCols], int getCols)
{
    int rows, lowest;

    

    lowest = randNumbers[0][getCols - 1];

    for (rows = 0; rows < sizeOfRows; rows++)
    {
        if (randNumbers[rows][getCols - 1] < lowest)
        {
            lowest = randNumbers[rows][getCols - 1];
        }
    }

    return lowest;
}

int main()
{
    int randNumbers[sizeOfRows][sizeOfCols] = { {1, 2, 3, 4, 5, 6},           // even = 12 odd = 12
                                                {7, 8, 9, 10, 11, 12},        // largest in row 1 = 6      lowest in col 1 = 1
                                                {13, 14, 15, 16, 17, 18},     //            row 2 = 12               col 2 = 2
                                                {19, 20, 21, 22, 23, 24} };   //            row 3 = 18               col 3 = 3
                                                                              //            row 4 = 24               col 4 = 4
    int odd = 0, even = 0, largestInRow, lowestInCol, choice = 1;                         //                                     col 5 = 5
    int getRows, getCols;                                                                          //                                     col 6 = 6
    while(choice != 0)
    {
        do
        {
            printf ("[1] - display all elements\n");
            printf ("[2] - count even numbers\n");
            printf ("[3] - count odd numbers\n");
            printf ("[4] - largest number in a row\n");
            printf ("[5] - lowest number in a column\n");
            printf ("[0] - exit\n");
            printf ("\nEnter your choice: ");
            scanf ("%d", &choice);
            
            if (choice < 0 || choice > 5)
            {
                printf ("Invalid input, please try again!");
                sleep(1);
                system("cls");
                fflush(stdin);
            }
        }while(choice < 0 || choice > 5);

        system("cls");   
        switch (choice)
        {
            case 1:
                    displayAllElements(randNumbers);
            break;

            case 2: 
                    even = countEven(randNumbers);
                    printf ("The number of odds in array: %d", even);
            break;

            case 3:
                    odd = countOdd(randNumbers);
                    printf ("The number of evens in array: %d", odd);
            break;

            case 4:
                    do
                    {
                        printf ("Enter a row number: ");
                        scanf ("%d", &getRows);

                        if (getRows > sizeOfRows || getRows <= 0)
                        {
                            printf ("Invalid input, please try again!");
                            sleep(1);
                            system("cls");
                        }
                    }while (getRows > sizeOfRows || getRows <= 0);
                    
                    largestInRow = largestNumberRow(randNumbers, getRows);
                    printf ("The largest number in the specific row: %d", largestInRow);
            break;

            case 5:
                    do
                    {
                        printf ("Enter a column number: ");
                        scanf ("%d", &getCols);
                        if (getCols > sizeOfCols || getCols <= 0)
                        {
                            printf ("Invalid input, please try again!");
                            sleep(1);
                            system("cls");
                        }
                    } while (getCols > sizeOfCols || getCols <= 0);
                    
                    lowestInCol = lowestNumberCol(randNumbers, getCols);
                    printf ("Lowest number in the specific column: %d", lowestInCol);
            break;

            case 0: 
                    return 0;
            break;
        } 

        pressAnyKey();
        system("cls");  

    }                            
}