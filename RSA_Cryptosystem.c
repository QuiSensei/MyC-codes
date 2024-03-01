#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//=======================================================//
#define N 100
#define NN (2 * N + 1)
//=======================================================//
typedef struct {
    unsigned char digit[NN];
} XP;
//=======================================================//
XP XPinitDecimal(const char*);
void XPshowDecimal(XP);
XP XPadd(XP, XP);
XP XPsub(XP, XP);
XP XPmul(XP, XP);
XP XPdiv(XP, XP);
XP XPrand();
XP XPisOdd(XP);
XP XPgreate(XP, XP);
XP XPless(XP , XP );
XP WPeq(XP , XP )

//=======================================================//
int main(void) {

    XP a, b, c;
 
    a = XPinitDecimal("123456789");
    b = XPinitDecimal("54545454");

    //addtion XP part
    c = XPadd(a, b);
    printf("Sum: \n");
    XPshowDecimal(c);
    
    //Subraction XP part
    c = XPsub(a, b);
    printf("\nDifference: \n");
    XPshowDecimal(c);

    c = XPgreate(a, b);
    printf("\nGreater than: \n");
    XPshowDecimal(c);

    c = XPless(a, b);
    printf("\nless than: \n");
    XPshowDecimal(c);

    c = XPeq(a, b);
    printf("\nProduct: \n");
    XPshowDecimal(c);

    c = XPmul(a, b);
    printf("\nQuotient: \n");
    XPshowDecimal(c);

    printf("\nGenerated Random number: \n");
    XPshowDecimal(XPrand());
    printf("\nPrinting odd number(from XPrand): \n");
    XPshowDecimal(XPisOdd(XPrand()));
    printf("Hello world");
    return 0;
}
//=======================================================//
// Initialize an XP struct into a decimal number
XP XPinitDecimal(const char* x) {
    XP xp;
    int indx = strlen(x);

    //set the digits to 0
    memset(xp.digit, 0, NN);

    // convert ASCII characters to integer digits
    for (int i = 0; i < indx; i++) {
        xp.digit[indx - i - 1] = x[i] - '0';
    }
    
    return xp;
}
//=======================================================//
//dispalys an XP
void XPshowDecimal(XP xp) {
    int i;

    //Finding the first non-zero digit
    for (i = NN - 1; i >= 0; i--) {
        if(xp.digit[i] != 0) {
            break;
        }
    }

    //Print the digit from the start of non-zero
    for(; i >= 0; i--) {
        printf("%d", xp.digit[i]);
    }

}
//=======================================================//
//add the two XP numbers
XP XPadd (XP a, XP b) {
    XP result;
    int carry = 0;

    for(int i = 0; i < NN; i++) {
        int sum = a.digit[i] + b.digit[i] + carry;
        result.digit[i] = sum % 10;
        carry = sum / 10;
    }

    return result;
}
//=======================================================//
//
XP XPsub(XP a, XP b) {
    XP result;
    int borrow = 0;

    for(int i = 0; i < NN; i++) {
        int diff = a.digit[i] - b.digit[i] - borrow;
        
        if (diff < 0) {
            result.digit[i] = diff + 10; 
            borrow = 1; 
        } else {
            result.digit[i] = diff;
            borrow = 0;
        }
    }

    return result;
}
//=======================================================//
//
XP XPmul(XP a, XP b) {
    XP result;
    memset(result.digit, 0, NN); // Initialize result to all zeros

    for (int i = 0; i < NN; i++) {
        int carry = 0;
        for (int j = 0; j < NN - i; j++) { // Adjust loop range
            int product = a.digit[i] * b.digit[j] + result.digit[i + j] + carry;
            carry = product / 10; // Calculate the carry
            result.digit[i + j] = product % 10; // Update current digit
            if (j == NN - i - 1 && carry > 0) {
                result.digit[i + j + 1] += carry; // Add remaining carry to next position
            }
        }
    }

    return result;
}
//=======================================================//
//
XP XPdiv(XP a, XP b) {
    XP quotient;
    XP remainder = a; // Initialize remainder to the dividend
    XP temp;

    memset(quotient.digit, 0, NN); // Initialize quotient to all zeros

    // Perform long division
    for (int i = NN - 1; i >= 0; i--) {
        while (strcmp(remainder, b) >= 0) { // While remainder is greater than or equal to divisor
            temp = shiftLeft(b, i); // Shift the divisor to the appropriate position
            if (strcmp(remainder, temp) >= 0) { // If shifted divisor fits into remainder
                remainder = subtract(remainder, temp); // Subtract shifted divisor from remainder
                quotient.digit[i]++; // Increment quotient at appropriate position
            } else {
                break; // Exit loop if subtraction leads to negative result
            }
        }
    }

    return quotient;
}

//=======================================================//
//Random number generetor
XP XPrand() {
    XP xp;

    srand(time(NULL));                  //use to generate numbers over the time 

    for(int i = 0; i < NN - 1; i++) {
        xp.digit[i] = rand() % 10;      //store random numbers to xp.digit
    }

    return xp;
}
//=======================================================//
//printing the odd numbers
XP XPisOdd(XP xp) {
    XP result;

    memset(result.digit, 0, NN);

    for(int i = 0; i < NN; i++) {
        if(xp.digit[i] % 2 != 0) {
            result.digit[i] = xp.digit[i];
        }
    }

    return result;
}
//=======================================================//
//To to check if it's greater than
XP XPgreate(XP a, XP b) {
    for (int i = NN - 1; i >= 0; i--) {
        if (a.digit[i] > b.digit[i]) {
            return a;
        } else if (a.digit[i] < b.digit[i]) {
            return b;
        }
    }
    
    return a;

}

XP XPless(XP a, XP b) {
    for (int i = NN - 1; i >= 0; i--) {
        if (a.digit[i] < b.digit[i]) {
            return 1;
        } else if (a.digit[i] > b.digit[i]) {
            return 0;
        }
        
    }
    return a;
}


XP WPeq(XP a, XP b) {

}