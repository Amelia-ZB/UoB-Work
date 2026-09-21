# Overview

> [unit webpage](https://cs-uob.github.io/COMS10014/materials.html)

> [course materials](https://uob.sharepoint.com/teams/MathematicsforComputerScien_a25ddc36-68d6-11f1-bf67-9d9551d49f9e/Class%20Materials/Forms/AllItems.aspx)

> multiple - choice exam somewhere between 14-18 December

## topics

> Logic & Proofs: wk1-4

> Sets, Functions, and Relations: wk5-8

> Probability: wk 9-?

# 00 - Intro

> maths makes problem solving easier through abstraction

> try to understand how problems are answered, not just what the answer is

# 01 - Booleans & Truth Tables

**True (⊤)**

**False (⊥)**

## Truth tables

**Implication**

|$x$|$y$|$x \Rightarrow y$|
|-|-|-|
|⊥|⊥|⊤|
|⊥|⊤|⊤|
|⊤|⊥|⊥|
|⊤|⊤|⊤|

## Operators

Conjunction - AND $\land$

(Inclusive) Disjunction - OR $\lor$

(Exclusive) Disjunction - XOR $\oplus$

Negation - NOT $\neg$

Implication - IF .. THEN .. $\Rightarrow$

> for it to be false, condition met, but not the consequence

### Vacuous Truths

|$x$|$y$|$x \Rightarrow y$|
|-|-|-|
|⊥|⊥|⊤|
|⊥|⊤|⊤|

valid but doesnt mean anything

_"if pigs can fly, its time to finish work"_

### Precedence

Parentheses > Negation > Conjunction > Disjunction > Implication

$\neg p \land q \lor r$ is the same as $((\neg p) \land q) \lor r$

### Associativity

Conjunction & disjunction is associative

$(p \land q) \land r \equiv p \land (q \land r)$

$(p \lor q) \lor r \equiv p \lor (q \lor r)$

Implication is _not_ associative, but terms can be combined

$p \Rightarrow (q \Rightarrow r) \equiv (p \land q) \Rightarrow r$

## Terms as trees

expressions can be written as trees. Nodes are operators and Leaves are variables.

> Means that parenthases are not needed

## Functional Completeness

$\neg, \land, \lor$ are together functionally complete

a functionaly complete set of operators can represent _any_ boolean expression

Use a sum of products to turn any truth table into an expression.
$(.. \land ..) \lor (.. \land ..) .. \lor ..$

just NAND $\neg(\ \land\ )$ is also functionaly complete