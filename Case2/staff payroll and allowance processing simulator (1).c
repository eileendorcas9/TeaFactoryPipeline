#include <stdio.h>
#include <string.h>


#define OTHER_DEDUCTION 500.0
#define TRAINING_LIMIT 5000.0
#define LOW_TRAINING_RATE 0.10
#define HIGH_TRAINING_LIMIT 0.15

double basicPay = 50000.0;//global variable

typedef struct
{
    int staffID;
    char name[50];

    double basicPay;
    double houseAllowance;
    double transportAllowance;

} Staff;


double calculateGrossPay(double basicPay,double houseAllowance,double transportAllowance)
{

    __auto_type gross = basicPay + houseAllowance + transportAllowance;

    return gross;
}


double calculateTrainingDeduction(double grossPay)//automatic local
{
    double trainingDeduction;

    if (grossPay <= TRAINING_LIMIT)
    {
        trainingDeduction = grossPay * LOW_TRAINING_RATE;
    }
    else
    {
        trainingDeduction = grossPay * HIGH_TRAINING_LIMIT;
    }

    return trainingDeduction;
}



double calculateNetPay(double grossPay,double trainingDeduction)
{

    __auto_type totalDeductions = trainingDeduction + OTHER_DEDUCTION;

    __auto_type netPay = grossPay - totalDeductions;

    return netPay;
}



void printPayslip(Staff staff)
{

    static int payslipsProduced = 0;//static local.....does not change during the entire program

    payslipsProduced++;

    double grossPay;
    double trainingDeduction;
    double totalDeductions;
    double netPay;


    grossPay = calculateGrossPay(staff.basicPay,staff.houseAllowance,staff.transportAllowance);

    trainingDeduction = calculateTrainingDeduction(grossPay);

    totalDeductions = trainingDeduction + OTHER_DEDUCTION;

    netPay = grossPay - totalDeductions;


    printf("\n");
    printf("STAFF PAYSLIP\n\n");

    printf("Staff ID           : %d\n", staff.staffID);
    printf("Staff Name         : %s\n", staff.name);

    printf("---------------------------------------------\n");

    printf("Basic Pay          : %.2f\n", staff.basicPay);
    printf("House Allowance    : %.2f\n", staff.houseAllowance);
    printf("Transport Allow.   : %.2f\n", staff.transportAllowance);

    printf("---------------------------------------------\n");

    printf("Gross Pay          : %.2f\n", grossPay);
    printf("Training Deduction : %.2f\n", trainingDeduction);
    printf("Other Deduction    : %.2f\n", OTHER_DEDUCTION);
    printf("Total Deductions   : %.2f\n", totalDeductions);

    printf("---------------------------------------------\n");

    printf("NET PAY            : %.2f\n", netPay);

    printf("---------------------------------------------\n");

    printf("Payslips Produced  : %d\n", payslipsProduced);

}



void calculatePayroll(double basicPay,double houseAllowance,double transportAllowance,double *grossPay,double *totalDeductions)//*grossPay and *totalDeductions are aliasing by referring to the caller functions
{
     *grossPay = basicPay + houseAllowance + transportAllowance;

    double trainingDeduction;

    if (*grossPay <= TRAINING_LIMIT)
    {
        trainingDeduction = *grossPay * LOW_TRAINING_RATE;
    }
    else
    {
        trainingDeduction = *grossPay * HIGH_TRAINING_LIMIT;
    }

    *totalDeductions = trainingDeduction + OTHER_DEDUCTION;
}

//SHADOWING ILLUSTRATION
void demonstrateShadowing(void)
{
   double basicPay = 30000.0;//local variable

    printf("\n");
    printf("========== SHADOWING DEMONSTRATION ==========\n");

    printf("Local basicPay  : %.2f\n", basicPay);

    printf("=============================================\n");
}


void payrollSummary(Staff staff[],int numberOfStaff)
{
    double totalGross = 0.0;
    double totalDeductions = 0.0;
    double totalNetPay = 0.0;

    double highestNetPay = 0.0;

    int i;

    for (i = 0; i < numberOfStaff; i++)
    {
        double gross;
        double training;
        double deductions;
        double net;

        gross =
            calculateGrossPay(
                staff[i].basicPay,
                staff[i].houseAllowance,
                staff[i].transportAllowance
            );

        training =
            calculateTrainingDeduction(gross);

        deductions =
            training + OTHER_DEDUCTION;

        net =
            gross - deductions;


        totalGross += gross;
        totalDeductions += deductions;
        totalNetPay += net;


        if (i == 0 || net > highestNetPay)
        {
            highestNetPay = net;
        }
    }


    printf("\n");
    printf("=============================================\n");
    printf("             PAYROLL SUMMARY\n");
    printf("=============================================\n");

    printf("Number of Staff    : %d\n", numberOfStaff);

    printf("Total Gross Pay    : %.2f\n",
           totalGross);

    printf("Total Deductions   : %.2f\n",
           totalDeductions);

    printf("Total Net Pay      : %.2f\n",
           totalNetPay);

    printf("Highest Net Pay    : %.2f\n",
           highestNetPay);

    printf("Payslips Produced  : %d\n",
           numberOfStaff);

    printf("=============================================\n");
}


// main function
int main(void)
{
    Staff staff[5] =
    {
        {1001,"Alice",45000.0,5000.0,3000.0},

        {1002,"Brian",55000.0,7000.0,4000.0},

        {1003,"Carol",30000.0,4000.0,2500.0},

        {1004,"David",70000.0,10000.0,5000.0},

        {1005,"Esther",48000.0,6000.0,3500.0}
    };

    int i;
    int numberOfStaff = 5;
    //individual payslips

    printf("\n");
    printf("*********************************************\n");
    printf("       STAFF PAYROLL PROCESSING SYSTEM\n");
    printf("*********************************************\n");

    for (i = 0; i < numberOfStaff; i++)
    {
        printPayslip(staff[i]);
    }


   //payroll summary

    payrollSummary(staff, numberOfStaff);


   //reference parameters

    printf("\n");
    printf("======= OUTPUT PARAMETER DEMONSTRATION =======\n");

    {
        double gross;
        double deductions;

        calculatePayroll(
            staff[0].basicPay,
            staff[0].houseAllowance,
            staff[0].transportAllowance,
            &gross,
            &deductions
        );

        printf("Gross Pay          : %.2f\n", gross);
        printf("Total Deductions   : %.2f\n", deductions);
    }


    //shadowing

    demonstrateShadowing();


    return 0;
}

