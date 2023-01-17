#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
void power();
void square();
void cube();
void squareroot();
long long convert(int oct);
void decToBinary(int n);

int main()
{
    int num, binary_num, decimal_num = 0, base = 1, rem;
    long int binarynum, octalnum = 0, j = 1, remainder;
    long int binaryval, hexadecimalval = 0, i = 1;
    int dectobin;
    long k = 0;
    int l = 0;
    int oct;
    char conti;
    int category;
    int tempChoice;
    int currencyChoice;
    int massChoice;
    int userinputF;          // User inputted Fahreinheit;
    int userinputC;          // User inputted Celsius;
    int userinputUSDtoEuro;  // User inputted for USD to EURO;
    int userinputUSDtoJPY;   // User inputted for USD to JPY;
    int userinputUSDtoRMB;   // User inputted for USD to RMB;
    int userinputOunce;      // User inputted for Ounce;
    int userinputGram;       // User inputted for Gram;
    int fahrenheitToCelcius; // variable that stores the converted F->C;
    int celciusToFahrenheit; // variable that stores the converted C->F;
    float USDtoEURO;         // varaible that stores the converted USD->EURO;
    float USDtoJPY;          // stores the converted USD->JPY;
    float USDtoRMB;          // stores the converted USD->RMB;
    float ounceToPounds;     // stores the converted Ounce->Pounds;
    float gramsToPounds;     // stores the conerted Grams->Pounds;
    int ch;
    long int octal, decimal = 0;
    printf("\t\tCALCULATOR AND CONVERTER\n\n\n");
    printf("\tENTER YOUR CHOICE : \n");
    printf("\t1. CALCULATOR\n");
    printf("\t2. CONVERTER\n");
    printf("\t0. TO EXIT\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("\t\tWelcome to the scientific calculator!!\n\n");
        int choice;
        printf("\n******* Press 0 to quit the program ********\n");
        printf("Enter 1 for Addition \n");
        printf("Enter 2 for Subtraction \n");
        printf("Enter 3 for Multiplication \n");
        printf("Enter 4 for Division \n");
        printf("Enter 5 for Modulus\n");
        printf("Enter 6 for Power \n");
        printf("Enter 7 for Factorial \n");
        printf("Enter 8  for square \n");
        printf("Enter 9  for cube \n");
        printf("Enter 10 for squareroot\n\n");

        while (1)
        {
            printf("\n\nEnter the operation you want to do: ");

            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                modulus();
                break;
            case 6:
                power();
                break;
            case 7:
                factorial();
                break;
            case 8:
                square();
                break;
            case 9:
                cube();
                break;
            case 10:
                squareroot();
                break;
            case 0:
                exit(0);
            default:
                printf("\n********** ENTER THE CORRECT CHOICE ***********\n");
            }
        }
        break;

    case 2:
        printf("\t\t*************Welcome to Converter!*********** \n");
        printf("\tHere is a list of conversation to choose from: \n");
        printf("\t1. Temperature\n2. Currency\n3. Mass \n4. binary to decimal\n5. binary to octal\n6. binary to hexadecimal\n7. octal to binary\n8. octal to decimal\n9. decimal to binary\n");
        printf("\tPlease enter the option.\n");
        scanf("%d", &category);
        switch (category)
        {
        case 1:
            printf("Welcome to Temperature Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for Fahrenheit to Celsius. \n");
            printf("Enter 2 for Celsius to Fahrenheit. \n");
            scanf("%d", &tempChoice);
            if (tempChoice == 1)
            {
                printf("Please enter the Fahrenheit degree: \n");
                scanf("%d", &userinputF);
                fahrenheitToCelcius = ((userinputF - 32) * (5.0 / 9.0));
                printf("Celcius: %d", fahrenheitToCelcius);
            }
            else if (tempChoice == 2)
            {
                printf("Please enter the Celcius degree: \n");
                scanf("%d", &userinputC);
                celciusToFahrenheit = ((9.0 / 5.0) * userinputC + 32);
                printf("Fahrenheit: %d", celciusToFahrenheit);
            }
            else
                printf("Please enter the correct choice. \n");
            break;
        case 2:

            printf("Welcome to Currency Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for USD to Euro. \n");
            printf("Enter 2 for USD to JPY. \n");
            printf("Enter 3 for USD to RMB. \n");
            scanf("%d", &currencyChoice);
            if (currencyChoice == 1)
            {
                printf("Please enter the USD amount: \n");
                scanf("%d", &userinputUSDtoEuro);
                USDtoEURO = userinputUSDtoEuro * 0.87;
                printf("Euro: %.2f", USDtoEURO);
            }
            else if (currencyChoice == 2)
            {
                printf("Please enter the USD amount: \n");
                scanf("%d", &userinputUSDtoJPY);
                USDtoJPY = userinputUSDtoJPY * 111.09;
                printf("JPY: %.2f", USDtoJPY);
            }
            else if (currencyChoice == 3)
            {
                printf("Please enter the USD amount: \n");
                scanf("%d", &userinputUSDtoRMB);
                USDtoRMB = userinputUSDtoRMB * 6.82;
                printf("RMB: %.2f", USDtoRMB);
            }
            else
                printf("Please enter correct choice. \n");
            break;
        case 3:

            printf("Welcome to Mass Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for ounces to pounds. \n");
            printf("Enter 2 for gram to pounds. \n");
            scanf("%d", &massChoice);
            if (massChoice == 1)
            {
                printf("Please enter the ounce amount: \n");
                scanf("%d", &userinputOunce);
                ounceToPounds = userinputOunce * 0.0625;
                printf("Pounds: %.2f", ounceToPounds);
            }
            else if (massChoice == 2)
            {
                printf("Please enter the gram amount: \n");
                scanf("%d", &userinputGram);
                gramsToPounds = userinputGram * 0.00220462;
                printf("Pounds: %.2f", gramsToPounds);
            }
            else
                printf("Please enter the correct choice. \n");
            break;

        case 4:
            printf(" Enter a binary number with the combination of 0s and 1s \n");
            scanf(" %d", &num);

            binary_num = num;
            while (num > 0)
            {
                rem = num % 10;
                decimal_num = decimal_num + rem * base;
                num = num / 10;
                base = base * 2;
            }
            printf(" The binary number is %d \t", binary_num);
            printf(" \n The decimal number is %d \t", decimal_num);
            break;
        case 5:
            printf("Enter the value for  binary number: ");
            scanf("%ld", &binarynum);
            while (binarynum != 0)
            {
                remainder = binarynum % 10;
                octalnum = octalnum + remainder * j;
                j = j * 2;
                binarynum = binarynum / 10;
            }
            printf("Equivalent octal value: %lo", octalnum);
            break;

        case 6:
            printf("Enter the binary number: ");
            scanf("%ld", &binaryval);
            while (binaryval != 0)
            {
                remainder = binaryval % 10;
                hexadecimalval = hexadecimalval + remainder * i;
                i = i * 2;
                binaryval = binaryval / 10;
            }
            printf("Equivalent hexadecimal value: %lX", hexadecimalval);
            break;
        case 7:
            printf("Enter an octal number: ");
            scanf("%d", &oct);
            printf("%d in octal = %lld in binary", oct, convert(oct));
            return 0;
            break;

        case 8:

            printf("Enter any octal number: ");
            scanf("%ld", &octal);
            while (octal != 0)
            {
                decimal = decimal + (octal % 10) * pow(8, l++);
                octal = octal / 10;
            }
            printf("Equivalent decimal value: %ld", decimal);
            break;
        case 9:
            printf("ENTER DECIMAL NUMBER");
            scanf("%d", &dectobin);
            decToBinary(dectobin);
            return 0;
            break;
        }
    }
}
void addition()
{
    printf("Enter the numbers you want to add: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The sum of a and b is %d\n", a + b);
}
void subtraction()
{
    printf("Enter the numbers you want to subtract: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("The subtraction of a and b is %d\n", a - b);
}
void multiplication()
{
    printf("Enter the numbers you want to multiply: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("The multiplication of a and b is %d\n", a * b);
}
void division()
{
    printf("Enter the numbers you want to divide: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("The division of a and b is %f\n", (float)a / (float)b);
}
void modulus()
{
    printf("Enter the numbers you want to find modulus of: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("The modulus of a and b is %d\n", a % b);
}
void factorial()
{
    int n, factorial;
    printf("Enter the number you want the factorial of: ");
    scanf("%d", &n);
    factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i; // factorial*=i;
    }
    printf("\nFactorial of %d is %d", n, factorial);
}
void power()
{
    double b;
    double p;
    printf("Enter the base and the power: ");
    scanf("%lf%lf", &b, &p);
    double e = pow(b, p);
    printf("The power is %lf", e);
}
void square()
{
    double b;
    printf("Enter the number you want the square of: ");
    scanf("%lf", &b);
    double p = pow(b, 2);
    printf("The square of %lf is %lf", b, p);
}
void cube()
{
    double b;
    printf("Enter the number you want the cube of: ");
    scanf("%lf", &b);
    double p = pow(b, 3);
    printf("The cube of %lf is %lf", b, p);
}
void squareroot()
{
    double b;
    printf("Enter the number you want the square root of : ");
    scanf("%lf", &b);
    double s = sqrt(b);
    printf("The square root of %lf is %lf", b, s);
}
long long convert(int oct)
{
    int dec = 0, i = 0;
    long long bin = 0;

    // converting octal to decimal
    while (oct != 0)
    {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    i = 1;

    // converting decimal to binary
    while (dec != 0)
    {
        bin += (dec % 2) * i;
        dec /= 2;
        i *= 10;
    }
    return bin;
}
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    printf("THE BINARY NUMBER : ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}