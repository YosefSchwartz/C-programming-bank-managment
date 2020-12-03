#include <stdio.h>
#include "bankFunction.h"

int main(){         
char ch;
do 
{
    printf("\nPlease choose a transaction type:\n"
            " O-Open Account\n"
            " B-Balance Inquiry\n"
            " D-Deposit\n"
            " W-Withdrawal\n"
            " C-Close Account\n"
            " I-Interest\n"
            " P-Print\n"
            " E-Exit\n");
    scanf(" %c",&ch);
       
        switch(ch)
        {
            case 'O':
                openNewAcc();
                break;
            case 'B':
                checkBalance();
                break;
            case 'D': 
                deposit();    
                break;
            case 'W': 
                withdrawel();
                break;
            case 'C':
                closeAcc();
                break;
            case 'I': 
                plusInterest();
                break;
            case 'P':
                printAll();
                break;
            case 'E':
                Exit();
                break;
            default: 
                printf("Invalid transaction type\n");
                break;
        }
}
while (ch != 'E');

return 0;  
}