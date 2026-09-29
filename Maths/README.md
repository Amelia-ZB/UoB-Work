# Overview

- [unit webpage](https://cs-uob.github.io/COMS10014/materials.html)

- [course materials](https://uob.sharepoint.com/teams/MathematicsforComputerScien_a25ddc36-68d6-11f1-bf67-9d9551d49f9e/Class%20Materials/Forms/AllItems.aspx)

- multiple - choice exam somewhere between 14-18 December

## topics

- Logic & Proofs: wk1-4

- Sets, Functions, and Relations: wk5-8

- Probability: wk 9-?

# 00 - Intro

- maths makes problem solving easier through abstraction

- try to understand how problems are answered, not just what the answer is

# 01.1 - Booleans & Truth Tables

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

- for it to be false, condition met, but not the consequence

- Paren, Neg, conj, disj, impl 

### Vacuous Truths

|$x$|$y$|$x \Rightarrow y$|
|-|-|-|
|⊥|⊥|⊤|
|⊥|⊤|⊤|

valid but doesnt mean anything

_"if pigs can fly, its time to finish work"_

### Precedence

> [!IMPORTANT]
> Parentheses > Negation > Conjunction > Disjunction > Implication

$\neg p \land q \lor r$ is the same as $((\neg p) \land q) \lor r$

### Associativity

Conjunction & disjunction is associative

$(p \land q) \land r \equiv p \land (q \land r)$

$(p \lor q) \lor r \equiv p \lor (q \lor r)$

Implication is _not_ associative, but terms can be combined

$p \Rightarrow (q \Rightarrow r) \equiv (p \land q) \Rightarrow r$

## Terms as trees

expressions can be written as trees. Nodes are operators and Leaves are variables.

- Means that parenthases are not needed

## Functional Completeness

$\neg, \land, \lor$ together are together functionally complete

a functionaly complete set of operators can represent _any_ boolean expression

Use a sum of products to turn any truth table into an expression.
$(.. \land ..) \lor (.. \land ..) .. \lor ..$

just NAND $\overline\land$ is also functionaly complete

## Identities

$x \land \top \equiv x \\ x \land \bot \equiv \bot$

$x \lor \bot \equiv x \\ x \lor \top \equiv \top$

$x \Rightarrow \bot \equiv \top \\ x \Rightarrow \top \equiv x\\$
$\top \Rightarrow x \equiv \top \\ \bot \Rightarrow x \equiv \neg x$

# 01.2 - Boolean Algebra

- syntax is the representation
    - takes into account the operator precedence
- semantics is the meaning


- conjunction $\land$ & disjunction $\lor$ are both _asociative_ & _commutative_
    - they are _symetric_ functions


## propositional Equivalent

- propositions are equivalent if they are equal under assignments
    - greek letter represent propositions
    - latin characters represent variables

$\Phi \equiv \Psi$

if $\Phi$ and $\Psi$ equate to the same thing under all assignments

## Distribution

$\Phi \land (\Psi \lor \Rho) \equiv (\Phi \land \Psi) \lor (\Phi \land \Rho)$

$\Phi \lor (\Psi \land \Rho) \equiv (\Phi \lor \Psi) \land (\Phi \lor \Rho)$

## Idempotence

$\Phi \land \Phi \equiv \Phi \quad \Phi \lor \Phi \equiv \Phi$

## Laws

### Law of the excluded middle
> [!NOTE]
> All expressions are _either_ true or false. $\\ \Phi \lor \neg \Phi \equiv \top$ and $\Phi \land \neg \Phi \equiv \bot$ and $\neg \neg \Phi \equiv \Phi$

- **Tautology** (Valid)
    - A proposition that is always true i.e. $\Phi \equiv \top$
    - $x > 0 \Rightarrow x > -100$

- **Invalid**
    - not always true i.e. $\Phi \not\equiv \top$

- **Satisfiable**
    - can be true $x > 0$

- **Unsatisfiable**
    - always false $0 > 1$

> [!NOTE]
> valid $\Rightarrow$ satisfiable and unsatisfiable $\Rightarrow$ invalid

### De Morgan's Law

$\neg(\Phi \land \Psi) \equiv \neg\Phi \lor \neg\Psi\\$
$\neg(\Phi \lor \Psi) \equiv \neg\Phi \land \neg\Psi$


## Implication!?

$p \Rightarrow (q \Rightarrow r) \equiv (p \land q) \Rightarrow r$


# 02.1 - Natural Deduction

$P \Rightarrow P$ - tautology


$x>0 \Rightarrow x>-1$ - tautology.
But it has infinite cases

$\sqrt 2$ cannot be expressed as a fraction

**Proof ≈ a way of demonstrating truth**
- follow proof steps to move from what is know to what is proven

> [!IMPORTANT]
> dont start with the goal, work towards it

> [!IMPORTANT]
> conjunction in an assumption is like 2 assumptions

## Formal Proofs

- natural deduction
    - within a true formual there is some evidence
    - propositions as evidence for their own truth
    - proof ≈ providing evidence

1. introduction
    - constructs evidence
        - assume something, which then implies something else
2. elimination
    - uses / extracts evidence from an assumption or proven statement

### Example

with have meaning proven or assumed true

$\Phi \Rightarrow \Psi$

# Implication

Introcucion:
- to prove, assume $\Phi$ is true, then prove $\Psi$

Elimination:
- if we have $\Phi \Rightarrow \Psi\\$ and we have $\Phi\\$ then $\Psi$.

### Example

<!-- Goal: $((p \Rightarrow p) \Rightarrow q) \Rightarrow q$

1. assume $(p \Rightarrow p) \Rightarrow q\\$ goal: $q$

goal: $p \Rightarrow p\\$

3. assume: $p\\$ goal: p

4. conclusion: $p \Rightarrow p\\$

steps 1 + 4 = Implication Elimination -->

![](./images/proof%20example%201.png)

indentation shows the scope of each assumption

## Conjunction
Introduction rule:
- to prove $\Phi \land \Psi$ we must prove $\Phi$ and $\Psi$ independantly

Elimination rule
- if we have $\Phi \land \Psi$
    - we may conlude $\Phi$ and $\Psi$

### example

![](./images/proof%20example%202.png)
![](./images/proof%20example%203.png)

