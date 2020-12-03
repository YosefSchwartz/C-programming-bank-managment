#include "bankFunction.h"

#include <stdio.h>

#define TOTAL_ACC 50
#define ACC_AMOUNT 0
#define ACC_STATUS 1
#define OPEN_ACC 1
#define CLOSE_ACC 0
#define CONS 901

int counter = 0;
double bank [2][50]={0};
int next = 0;

int getNext(int next)
{
    while(bank[ACC_STATUS][next]==OPEN_ACC && next<TOTAL_ACC)
        next++;
    return next;
}

void openNewAcc() {
    if(counter<TOTAL_ACC){
        double amount;
        printf("Please enter amount for deposit: ");
        if((scanf(" %lf", &amount)==1)){
            if(amount>=0){
                bank[ACC_AMOUNT][next]= amount;
                bank[ACC_STATUS][next]=OPEN_ACC;
                counter++;
                printf("New account number is: %d\n",(next+CONS));
                next = getNext(next);
            } else {
                printf("Invalid Amount\n");
            } 
        } else {
            printf("Failed to read the amount\n");
        }
    }else{
            printf("Bank is full\n");
    }    
}

void checkBalance() {
    int accNum;
    printf("Please enter account number: ");    
    if((scanf(" %d", &accNum)==1)){
        if (accNum <= 950 && accNum > 900){
            if(bank[ACC_STATUS][accNum-CONS]==OPEN_ACC){
                printf("The balance of account %d is: %0.2lf\n",accNum,bank[ACC_AMOUNT][accNum-CONS]);
            }else{
            printf("This account is closed\n");
            } 
        }else{
            printf("Invalid account number\n");
        }
    }else{
        printf("Failed to read the account number\n");
    }
    return;
}      

void deposit(){
    int accNum;
    printf("Please enter account number: ");
    if(scanf(" %d", &accNum)==1){
        if (accNum <= 950 && accNum > 900){
            if(bank[ACC_STATUS][accNum-CONS]==OPEN_ACC){
                double amount;
                if(scanf(" %lf", &amount)==1){
                    if(amount>=0){
                        bank[ACC_AMOUNT][accNum-CONS]+=amount;
                        printf("The new balance is: %lf\n",bank[ACC_AMOUNT][accNum-CONS]);
                    }else{
                        printf("Cannot deposit a negative amount\n");
                    }
                }else{
                    printf("Failed to read the amount\n");
                }
            }else{
                printf("This account is closed\n");
            }
        }else{
            printf("Invalid account number\n");
        }
    }else{
        printf("Failed to read the account number\n");
    }
    return;
}

void withdrawel()
{
    int accNum;
    printf("Please enter account number: ");
    if(scanf(" %d", &accNum)==1){
         if (accNum <= 950 && accNum > 900){
             if(bank[ACC_STATUS][accNum-CONS]==OPEN_ACC){
                double amount;
                if(scanf(" %lf", &amount)==1){
                    if(amount>=0){
                        if(amount<=bank[ACC_AMOUNT][accNum-CONS])
                        {
                            bank[ACC_AMOUNT][accNum-CONS]-=amount;    
                        }else{
                            printf("Cannot withdraw more than the balance\n");
                        }
                    }else{
                        printf("Cannot withdraw a negative amount\n");
                    }
                }else{
                    printf("Failed to read the amount\n");
                }
             }else{
                 printf("This account is closed\n");
             }
         }else{
           printf("Invalid account number\n");  
         }
    }else{
        printf("Failed to read the account number\n");
    }
    return;
}

void closeAcc()
{
    int accNum;
    printf("Please enter account number: ");
    if(scanf(" %d", &accNum)==1){
        if(accNum <= 950 && accNum > 900){
            if(bank[ACC_STATUS][accNum-CONS]==OPEN_ACC){
                bank[ACC_STATUS][accNum-CONS]=CLOSE_ACC;
                next=getNext(next);
                counter--;
                printf("Closed account number %d\n",accNum);
            }else{
                printf("This account is already closed\n");
            }
        }else{
            printf("Invalid account number\n");    
        }
    }else{
        printf("Failed to read the account number\n");    
    }
    return;
}

void plusInterest() {
    int interestRate;
    printf("Please enter interest rate: ");
    if(scanf(" %d", &interestRate)==1){
        if(interestRate>=0){
            for(int i =0;i<next;i++){
                if(bank[ACC_STATUS][i]==OPEN_ACC)
                    bank[ACC_AMOUNT][i]+=bank[ACC_AMOUNT][i]*(interestRate/100.0);
            }
        }else{
            printf("Invalid interest rate\n");
        }
    }else{
        printf("Failed to read the interest rate\n");
    }
    return;
}

void printAll(){
    for(int i=0;i<TOTAL_ACC;i++){
        if(bank[ACC_STATUS][i]==OPEN_ACC)
            printf("The balance of account %d is: %0.2lf\n",i+CONS,bank[ACC_AMOUNT][i]);
    }
    return;
}

void Exit(){
    for(int i=0;i<TOTAL_ACC;i++){
            bank[ACC_STATUS][i] = CLOSE_ACC;       
    }
    return;
}
