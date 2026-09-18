# TeaFactoryPipeline Project

UNIT NAME: Programming Languages  
GROUP NO.: 25  

##  GROUP MEMBERS
NAME                 REG NO.
Dorcas Eileen        C026-01-0988/2025  
Stacy Njeri          C026-01-0939/2025  
Eleanor Wangeci      C026-01-0944/2025  
## TeaFactoryPipeline.lua Overview
This section of the project demonstrates how Lua coroutines can be used to simulate a tea factory’s production pipeline. Each tea batch flows through stages:

Receiving

Weighing

Withering

Drying (with quality check)

Grading

Packaging

Failed batches at the Drying stage are automatically reprocessed until they pass inspection.

## Key Features
Coroutine design for handling individual tea batches.

Yielding batch ID and stage after each operation.

Built-in quality check with reprocessing logic.

Scheduler for interleaving multiple batches in parallel.

Demonstration of coroutine state persistence (resuming from the last stage instead of restarting).


## Why Coroutines Simplify the Pipeline
State persistence: Coroutines remember their own progress internally.

Natural scheduling: The scheduler resumes a coroutine exactly where it left off.

Efficient reprocessing: Failed batches restart cleanly without reconstructing pipeline state.

Simpler code: No need for external variables or conditional logic to track progress.
## CASE2:STAFF PAYROLL OVERVIEW
This part of the project focuses on names, bindings, and scope in programming languages, demonstrated through a payroll system context. It includes test results, variable analysis, and explanations of scoping rules.

 Variable Analysis
staffID → int, struct field, lifetime tied to struct object.

grossPay → double, local in functions, exists until function returns.

payslipsProduced → static int, local in printPayslip, persists for entire program execution.

basicPay (global) → double, global scope, lifetime is entire program.

basicPay (local) → double, local scope inside demonstrateShadowing, lifetime ends when block ends.

# Key Takeaways
Static type binding: Variables are bound to types at compile time.

Type inference (auto): Used in functions like calculateGrossPay.

Parameter scope/lifetime: Function parameters exist only during execution.

Static locals: Persist across multiple calls.

Shadowing: Local variables can hide global ones.

# Questions & Answers
When is a variable bound to type, storage, and value?

Type → at compile time.

Storage → when function executes.

Value → when assignment executes.

Where is a name visible?

Example: grossPay is visible only inside its function (local scope).

Lifetime of variables?

Local → begins at function call, ends at return.

Static → persists for entire program.

Aliases: Function parameters like grossOutput and netOutput act as aliases for caller variables grossResult and netResult.

L-value vs R-value:

L-value → gross (storage location).

R-value → calculateGross(staff) (produced value).

Shadowing: Inner basicPay hides outer/global basicPay. Removing it reveals the outer declaration.

Dynamic vs Static Scoping:

Static → meaning determined by textual structure.

Dynamic → meaning depends on call chain at runtime.

Named constants: Using #define OTHER_DEDUCTION 500.0 is better than repeating literal values — improves clarity, consistency, and maintainability Case2 (Staff Payroll) demonstrates how variable types, scope, lifetime, shadowing, and binding rules work in programming languages, using payroll-related examples. It highlights static vs dynamic scoping, the importance of named constants, and how aliases and shadowing affect program behavior.


