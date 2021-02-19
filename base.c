#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "structure.h"

//Notes
/*
**Symbols**
<	Less than
==	Equal to
>	Greater than
<=	Less than or equal to
>=	Greater than or equal to
!=	Not equal to

**Logical Operators**
&& (and)
|| (or)
! (no)

**Shorthand Operators**
+=  Addition assignment
-=  Subtraction assignment
*=  Multiplication assignment
/=  Division assignment
%=  Remainder assignment
++x Increment
--x Decrement

**Conversion Characters**
Remember to put an space before if doenst have nothing
 %s for strings
 %i for integers (auto detects the base of integer)
 %d for decimal integer (decimal base)
 %c for single character
 %.xf for decimal numbers, .x specify how much decimal numbers will be displayed
 %p for pointers

**Type of variables**
int for numbers
char for strings
float for decimal numbers
double for decimal number (same as float but with double of memory)

**Array*
char name[x] where x is the "place" number of caracters for this variable

**Header File**
#include <.h> to import libraries
#include "archiveName" to import an archive from the same directory
#define <"variable"> is used to absolute declare an variable value

**Type of Inputs**
scanf("type of input (%s(string)-%d(interger)-%f(float)-%c(character))", variable which will store the value)

**Math Operators order**
2. + addition or unary plus (++ add one)
2. - subtraction or unary minus (-- subtract one)
1. * multiplication
1. / division
% remainder after division (modulo division)

https://devdocs.io/c/
*/

//Examples
/*
*******Example 1*******
-Manipulating variables in the declarion
    int age1, age2;
    age1 = age2 = 10;

    printf("Our ages sums is %d", age1 + age2);

*******Example 2*******
-Alternating math operator orders with symbols
    int a = (4 + 2) * 6;

    printf("Result: %d\n", a);

*******Example 3*******
-Progressive increment
    float balance = 1000.00;

    printf("Balance %f\n", balance);
    balance *= 1.1;
    printf("Balance %f\n", balance);
    balance *= 1.1;
    printf("Balance %f\n", balance);

*******Example 4*******
-Typecasting - Converting one datatype to another (always use the same datatype for math operations)
    float avgProfit;
    int priceOfPumpkins = 10;
    int sales = 59;
    int daysWorked = 7;

    avgProfit = (float)priceOfPumpkins * (float)sales / (float)daysWorked;
    printf("Average profit is %f", avgProfit);

*******Example 5*******
-If statement, nesting
    int age;
    char gender;

    printf("How old are you\n");
    scanf(" %d", &age);
    if(age >= 18){
        printf("You can enter this site\n");
        printf("What your gender\n");
        scanf(" %c", &gender);
        if (gender == 'm'){
            printf("Entering Man Section\n");
        }
        if (gender == 'f'){
            printf("Entering Woman Section\n");
        }
    }
    if(age < 18){
        printf("You can't enter this site\n");
    }

*******Example 6*******
-Else statement, nesting
    float grade1, grade2, grade3, avg;

    printf("Enter your 3 test grades: \n");
    scanf(" %f", &grade1);
    scanf(" %f", &grade2);
    scanf(" %f", &grade3);
    avg = (grade1 + grade2 + grade3) / 3;
    printf("Your final grade is: %.2f\n", avg);
    if(avg >= 80){
            printf("Your grade is A");
    }else if(avg >= 60){
            printf("Your grade is B");
    }else if(avg >= 40){
            printf("Your grade is C");
    }else if(avg >= 20){
            printf("Your grade is D");
    }else{
        printf("Your grade is E");
    }

*******Example 7*******
-If Else shorthand statement
    char lastName[20];
    int friends = 1;

    printf("What is your last name?\n");
    scanf(" %s", lastName);
    (lastName[0] <= 'M') ? printf("Blue team\n") : printf("Red team\n");
    printf("I have %d friend%s", friends, (friends!=1) ? "s" : "" );

*******Example 8*******
-Logical operator example
    char answer[1];

    printf("You can type y or n?\n");
    scanf(" %c", &answer);
    if((answer=='y') || (answer=='n')){
        printf("Very nice");
    }else{
        printf("Not stonks at all");
    }

*******Example 9*******
-While Loops
    int day = 1;
    float amount = .01;

    while (day <=31){
        printf("Day:%d \t Amount:$%.2f \n", day, amount);
        amount *= 2;
        day++;
    }

*******Example 10*******
-do While Loop
    float grade, scoreEntered, numberOfTests, average;
    grade = scoreEntered = numberOfTests = average = 0;

    printf("Insert 0 in test note to exit the program\n\n");

    do{
        printf("Tests:%.0f     Average%.2f\n", numberOfTests, average);
        printf("\nEnter the test score: ");
        scanf("%f", &scoreEntered);
        grade += scoreEntered;
        numberOfTests++;
        average = grade / numberOfTests;
    }while(scoreEntered != 0);

*******Example 11*******
-for loop
    int happiness;

    for (happiness = 0; happiness < 10; happiness++){
        printf("You level of happiness is %d\n", happiness);
    }

*******Example 12*******
-Table/matrix
     int rows, columns;

    for(rows = 0; rows < 4; rows++){
        for(columns = 1; columns < 4; columns++){
            printf("%d", columns);
        }
        printf("\n");
    }

*******Example 13*******
-break statement
    int a, howMany, maxAmount;
    maxAmount = 10;

    printf("How many times you want this loop to loop?");
    scanf(" %d", &howMany);

    for(a=1; a<=maxAmount; a++){
        printf("%d\n", a);
        if(a==howMany){
            break;
        }
    }

*******Example 14*******
-continue statement
   int num = 1;

   do{
       if(num == 6 || num == 8){
           num++;
           continue;
       }
       printf("Number %d is avaliable\n", num);
       num++;
   }while(num <= 10);

*******Example 15*******  
-switch 
    char grade = 'B';

    switch(grade){
        case 'A' : printf("Good Job");
        break;
        case 'B' : printf("Well Done");
        break;
        case 'C' : printf("Average");
        break;
        case 'D' : printf("Could be better");
        break;
        case 'E' : printf("Put more effort");
        break;
        default : printf("Invalid grade\n");
    }

*******Example 16*******
-Verifying the character in a int variable as a character
    int a = '&';

    if(isalpha(a)){
        if(isupper(a)){
            printf("%c is an letter and is an Upper Case letter", a);
        }else{
            printf("%c is an letter and is an Lower Case letter", a);
        }     
        }else{
            if(isdigit(a)){
                printf("%c is a number", a);
            }else{
                printf("%c is an symbol", a);
            }
        } 

*******Example 17*******
-Converting an lower case to upper case
    int a = 'c';

    printf("%c \n", toupper(a));
    return 0;

*******Example 18*******
-strcat and strcpy
    char welcome[100] = "Hey ";

    strcat(welcome, "you. ");
    strcat(welcome, "You're ");
    strcat(welcome, "finally ");
    strcat(welcome, "awake.");
    printf(" %s", welcome);

    strcpy(welcome, "\nBrave Soldier");
    printf(" %s", welcome);

*******Example 19*******
-puts and gets (the blinking bar go to next line)
    char firstName[30];
    char middleName[30];
    char lastName[30];
    char fullName[150] = "";

    puts("Whats is your first name?");
    gets(firstName);

    puts("Whats is your middle name?");
    gets(middleName);

    puts("Whats is your last name?");
    gets(lastName);

    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, middleName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
    puts(fullName);

*******Example 20*******
-Rounding numbers (floor and ceil)
    float a = 9.32;
    float b = 3.78;

    printf("%.2f \n", floor(a));
    printf("%.2f \n", floor(b));

    printf("%.2f \n", ceil(a));
    printf("%.2f \n", ceil(b));

*******Example 21*******
-Absolute value (abs for int and fabs for floats)
    int year1, year2, age;

    printf("Calculate your age at any year!\n");
    printf("Insert the birth year\n");
    scanf("%d", &year1);

    printf("Insert the other year\n");
    scanf("%d", &year2);

    age = year1 - year2;
    age = abs(age);
    printf("%d", age);

*******Example 22*******
-Square root of an number and power of an number
    printf("%f\n", pow(5,5));
    printf("%f", sqrt(30));

*******Example 23*******
-Random number generator
    int i;
    int diceRoll;

    for(i = 0; i < 20; i++){
        printf("%d\n", rand());
        diceRoll = (rand()%6) + 1;
        printf("%d\n", diceRoll);
        }

*******Example 24*******
-int and float arrays
    int i;
    int littersOfWater[5];
    int totalWater = 0;
    int avg;

    for(i = 0; i < 5; i++){
        printf("How many litters you drank day %d?", i + 1);
        scanf(" %d", &littersOfWater[i]);
    }

    for(i = 0; i < 5; i++){
        totalWater += littersOfWater[i];
    }
    
    avg = totalWater / 5;
    printf("Your drank %d per day, an average of %d per day!", totalWater, avg);

*******Example 25*******
-Manipulating Parallel Arrays data
    int i;
    int players[5] = {01, 02, 03, 04, 05};
    int goals[5] = {13, 27, 32, 17, 18};
    int gamesPlayed[5] = {10, 10, 12, 7, 15};
    float pointsPerGame[5];
    float bestPointsPerGame = 0.0;
    int bestPlayer;

    for(i = 0; i < 5; i++){
        pointsPerGame[i] = (float)goals[i] / (float)gamesPlayed[i];
        printf("%d \t %d \t %d \t %.2f \t \n", players[i], goals[i], gamesPlayed[i], pointsPerGame[i]);

        if(pointsPerGame[i] > bestPointsPerGame){
            bestPointsPerGame = pointsPerGame[i];
            bestPlayer = players[i];
        }
    }
    printf("\n The best player is the %d", bestPlayer);

*******Example 26*******
-Sorting arrays and infinite loop
    int i, temp, sorted;
    int howMany = 10;
    int numbers[howMany];

    for(i = 0; i < howMany; i++){
        numbers[i] = (rand()%25) + 1;
    }
    printf("Unsorted list\n");
    for(i = 0; i < howMany; i++){
        printf("%d\n", numbers[i]);
    }
    while(1){
        sorted = 0;
        for(i = 0; i < howMany-1; i++){
            if(numbers[i] < numbers[i + 1]){
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                sorted = 1;
            }
        }
        if(sorted == 0){
            break;
        }
    }
    printf("Sorted list\n");
    for(i = 0; i < howMany; i++){
        printf(" %d\n", numbers[i]);
    }

*******Example 27*******
-Introduction to Pointers
    int pointer = 19;
    int * pPointer = &pointer;

    printf("Address \t Name \t         Value \n");
    printf("%p \t %s \t %d \n", pPointer, "pointer", pointer);
    printf("%p \t %s \t %p \n", &pPointer, "pPointer", pPointer);

*******Example 28*******
-Dereference Pointer
    int pointer = 19;
    int * pPointer = &pointer;

    printf("Address \t Name \t Value \n");
    printf("%p \t %s \t %d \n", pPointer, "pointer", pointer);
    printf("%p \t %s \t %d \n", &pPointer, "pPointer", *pPointer);

    * pPointer = 72;
    
    printf("pointer value %d \n", pointer);
    printf("*pPointer value %d \n", *pPointer);

*******Example 29*******
-Arrays and Pointers
    int i;
    int snowBalls[5] = {7, 9, 43, 21, 3};

    printf("Element \t Address \t Value \n");

    for(i = 0; i < 5; i++){
        printf("snowBalls[%d] \t %p \t %d \n", i, &snowBalls[i], snowBalls[i]);
    }

    //Array names are pointers (or constants).
    printf("\nsnowBalls \t \t %p \n", snowBalls);
    printf("\nsnowBalls \t \t %d \n", *snowBalls);
    printf("\nsnowBalls \t \t %d \n", *(snowBalls + 2));

*******Example 30*******
-Strings and Pointers
    //In char variables have an constant, which is different than pointer
    //char movie1[] = "The Lord of The Rings: The Fellowship of The Ring";
    char *movie2 = "The Lord of The Rings: The Two Towers";

    puts(movie2);

    movie2 = "The Lord of The Rings: The Return of The King";

    puts(movie2);

*******Example 31*******
-The Heap (is leftover memory that you can borrow if needed and give it back when the program needs)
    int i;
    int *pointer;

    printf("%d", sizeof( i ));

    pointer = (int *) malloc(sizeof(int)); /allocate memory

    free(pointer); //give back memory

*******Example 32*******
-Creating an Expandable Program
    int i, howMany;
    int total = 0;
    float average = 0.0;
    int *pointsArray;

    printf("How many numbers you want to store?\n");
    scanf(" %d", &howMany);

    pointsArray = (int *) malloc(howMany * sizeof(int));

    printf("Insert the %d number(s).\n", howMany);

    for(i = 0; i < howMany; i++){
        scanf(" %d", &pointsArray[i]);
        total += pointsArray [i];
    }
    average = (float)total / (float)howMany;
    printf("The average is %.2f", average);

*******Example 33*******
-Structures (have to #include the file with the struct)
    struct user kawan;
    struct user whatever;

    kawan.userID = 1;
    whatever.userID = 2;

    puts("Enter the first name of user 1");
    gets(kawan.firstName);
    puts("Enter the first name of user 2");
    gets(whatever.firstName);

    printf("The name of the first user is %s\n", kawan.firstName);
    printf("The name of the second user is %s\n", whatever.firstName);

*******Example 34*******
-Writing Files in C
    FILE *fPointer;
    fPointer = fopen ("c.txt", "w"); //w is used to create a file, if have an file if same name its overwrite the old one.
    
    fprintf(fPointer, "Learning programming languages is hard\n");

    fclose(fPointer);

*******Example 35*******
-Reading Files in C
    char singleLine [150];
    FILE *fPointer;

    fPointer = fopen ("c.txt", "r"); //r is used to read a file
    while(!feof(fPointer)){
        fgets(singleLine, 150, fPointer);
        puts(singleLine);
    }
    fclose(fPointer);

*******Example 36*******
-Append to Files in C
    FILE *fPointer;

    fPointer = fopen ("c.txt", "a"); //a is used to append data to a file
    
    fprintf(fPointer, "\n-Especially the C Language");

    fclose(fPointer);

*******Example 37*******
-Random Files Aceess in C
    FILE *fPointer;

    fPointer = fopen ("c.txt", "w+"); //a is used to append data to a file
    fputs("I'm going crazy with C programming language", fPointer);

    fseek(fPointer, 21, SEEK_SET); //SEEK_SET put the pointer on the first line and space of the file
    fputs("with any programming language", fPointer);
    
    fseek(fPointer, -8, SEEK_END); //SEEK_END put the pointer on the last line and last space of the file
    fputs("at all", fPointer);

    fclose(fPointer);

*******Example 38*******
-Functions
void functionTest(); //Declare the sub-function's above the main function

int main()
{
    functionTest();

    return 0;
}
void functionTest(){
    printf("I'm an function");
    return;
}

*******Example 39*******
-Global and Local Variables
void functionTest();

int randomNumber = 1; //This is a global variable and can be used for every function

int main()
{
    int randomNumber = 1; //This is a local variable, only this function can use it
    printf("I have %d mouses\n", randomNumber);
    functionTest();

    return 0;
}

void functionTest(){
    printf("I have %d mouses\n", randomNumber);

    return;
}

*******Example 40*******
-Passing Arguments to Functions
void convertCurrency(float euro);

int main()
{
    float euroAmount1 = 1.00;
    float euroAmount2 = 2.77;

    convertCurrency(euroAmount1);
    convertCurrency(euroAmount2);
    convertCurrency(27.55);

    return 0;
}

void convertCurrency(float euro){ //inside the () you out the variable that can be replaced
    float usDolars = euro * 1.37;
    printf("%.2f Euros - %.2f USD\n", euro, usDolars);

    return;
}

*******Example 41*******
-Return values
int calculateBonus(int yearsWorked);

int main()
{
    printf("Kawan bonus is $%d\n", calculateBonus(14));
    printf("Whatever bonus is $%d\n", calculateBonus(3));

    return 0;
}

int calculateBonus(int yearsWorked){
    int bonus = yearsWorked * 250;

    if(yearsWorked > 9){
        bonus += 1000;

        return bonus; //Here you declare de value you gonna return from the function (processed inside the function)
    }
}

*******Example 42*******
-
void passByValue(int i);
void passByAddress(int *i);

int main()
{
    int number = 20;

    passByValue(number);
    printf("Passing by Value, the value is %d\n", number);

    passByAddress(&number);
    printf("Passing by Address, the value is %d\n", number);

    return 0;
}

void passByValue(int i){
    i = 90;
    return;
}

void passByAddress(int *i){
    *i = 60;
    return;
}
*/