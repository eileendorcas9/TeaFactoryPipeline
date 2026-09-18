**UNIT NAME: Programming Languages**

**GROUP NO.: 25**

**GROUP MEMBERS: NAME REG NO.**

**Dorcas Eileen C026-01-0988/2025**

**Stacy Njeri C026-01-0939/2025**

**Eleanor Wangeci C026-01-0944/2025**

**TEST RESULTS**

![](./media/image1.png){width="3.041823053368329in"
height="2.729306649168854in"}

![](./media/image2.png){width="3.0487674978127735in"
height="4.173825459317586in"}

![](./media/image3.png){width="3.7988068678915137in"
height="4.208549868766404in"}

  ----------------------------------------------------------------------------------
  **Variable Name**      **Type**   **Scope**                  **Lifetime**
  ---------------------- ---------- -------------------------- ---------------------
  **staffID**            int        Struct field               Lifetime of struct
                                                               object

  **grossPay**           double     Local in functions         Until function
                                                               returns

  **payslipsProduced**   static int Local in printPayslip      Entire program
                                                               execution

  **basicPay (global)**  double     Global                     Entire program
                                                               execution

  **basicPay (local)**   double     Local in                   Until block ends
                                    demonstrateShadowing       
  ----------------------------------------------------------------------------------

TAKEAWAYS

\- **Static type binding**: All declared variables (double, int,
char\[\]) are bound at compile time.

\-**Type inference (**auto**)**: Used in calculateGrossPay and
calculateNetPay for local variables.

\- **Parameter scope/lifetime**: Formal parameters in functions like
calculateTrainingDeduction exist only during function execution.

\- **Static locals**: payslipsProduced persists across multiple calls to
printPayslip.

\- **Shadowing**: Local basicPay inside demonstrateShadowing hides the
global basicPay.

**Q1. At what point is this variable bound to its type?**

Ex:

double gross;

The variable gross is explicitly bound to the type double at compile
time when the declaration is processed demonstrating **static type
binding**.

**\"When is it bound to its storage?\"**

For an ordinary variable such as double gross;:

Its storage is allocated when the function invocation creates its local
variables.

**\"When is it bound to its current value?\"**

For gross = calculateGross(staff);, the value is bound/assigned when
that statement executes at runtime.

Type → compile time

Storage → function execution

Value → assignment during execution

**Q2. Where is this name visible?**

Using void calculateTrainingDeduction(double grossPay)

{

\...

} as an example,

grossPay is visible inside calculateTrainingDeduction() but It isn\'t
visible in main() because it is a **parameter with local scope**.

The name grossPay has function scope and cannot be directly accessed
outside the function where it is declared.

Q3. When does this variable begin and end its lifetime?

For an ordinary local double gross;

Its lifetime begins when the function invocation creates the local
variable and ends when the function returns.

However, for static int payslipCount = 0;

Scope - printPayslip()

Lifetime - entire execution of the program

Q4. Which two names in your program are aliases?

We have:

double grossResult; double netResult; and void calculateResults(

const Staff \*staff,

double \*grossOutput,

double \*netOutput)

Inside the function

Relationship is:

grossOutput → grossResult netOutput → netResult

**Therefore,** grossOutput provides access to the same storage location
as grossResult, while netOutput provides access to the same storage
location as netResult. This allows the function to modify the caller\'s
variables.

Q5. Identify an I-value and r-value

If we have gross = calculateGross(staff); then:

L-value -- gross (It identifies a storage location that can receive a
value.

)

R-value - calculateGross(staff)(It produces the value that gets
assigned.)

Q6. If this local declaration were removed, which outer declaration
would be found next?

The code has: double basicPay = staff-\>basicPay;

{

double basicPay = 99999.00; printf(\"%.2f\", basicPay);

}

The compiler finds the inner declaration first, which shadows the outer
one.

If it is removed, the compiler will use the outer declaration

Name resolution searches the nearest enclosing lexical scope first known
as static scoping

Q7. What would change with dynamic scoping?

Under static scoping:

The meaning of a variable name is determined by the program\'s textual
structure.

Under dynamic scoping:

The meaning could depend on the chain of functions that called the
current function.

So, with dynamic scoping, determining which variable a name refers to
could depend on which function called which function at runtime, rather
than where the variable appears in the source code.

Q8. Why is a named constant better?

We write \'#define OTHER_DEDUCTION 500.0\' instead of writing 500.00
repeatedly

This is better because:

-   It gives the value a meaningful name.

-   It avoids inconsistent values.

-   It makes changes easier.

-   It makes the program easier to understand.

-   It clearly identifies the value as a fixed policy value.
