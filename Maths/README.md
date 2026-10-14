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

- Parentheses, Negation, conjunction, disjunction, implication

### Vacuous Truths

|$x$|$y$|$x \Rightarrow y$|
|-|-|-|
|⊥|⊥|⊤|
|⊥|⊤|⊤|

valid but doesn't mean anything

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

- Means that parentheses are not needed

## Functional Completeness

$\neg, \land, \lor$ together are together functionally complete

a functionally complete set of operators can represent _any_ boolean expression

Use a sum of products to turn any truth table into an expression.
$(.. \land ..) \lor (.. \land ..) .. \lor ..$

just NAND $\overline\land$ is also functionally complete

## Identities

$x \land \top \equiv x \\ x \land \bot \equiv \bot$

$x \lor \bot \equiv x \\ x \lor \top \equiv \top$

$x \Rightarrow \bot \equiv \top \\ x \Rightarrow \top \equiv x\\$
$\top \Rightarrow x \equiv \top \\ \bot \Rightarrow x \equiv \neg x$

# 01.2 - Boolean Algebra

- syntax is the representation
    - takes into account the operator precedence
- semantics is the meaning


- conjunction $\land$ & disjunction $\lor$ are both _associative_ & _commutative_
    - they are _symmetric_ functions


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


# 02 - Natural Deduction

$P \Rightarrow P$ - tautology


$x>0 \Rightarrow x>-1$ - tautology.
But it has infinite cases

$\sqrt 2$ cannot be expressed as a fraction

**Proof ≈ a way of demonstrating truth**
- follow proof steps to move from what is know to what is proven

> [!IMPORTANT]
> don't start with the goal, work towards it

> [!IMPORTANT]
> conjunction in an assumption is like 2 assumptions

## Formal Proofs

- natural deduction
    - within a true formula there is some evidence
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

## Implication

Introduction:
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
- to prove $\Phi \land \Psi$
    - we must prove $\Phi$ _and_ $\Psi$ independently

Elimination rule
- if we have $\Phi \land \Psi$
    - we may conclude $\Phi$ and $\Psi$ separately

### Example

![](./images/proof%20example%202.png)
![](./images/proof%20example%203.png)

## Disjunction

Introduction rule:
- to prove $\Phi \lor \Psi$
    - we must prove $\Phi$ or $\Psi$

Elimination rule
- if we have $\Phi \lor \Psi$
    - we must assume $\Phi$ and show $\Rho$ follows
    - **and** must assume $\Psi$ and show $\Rho$ follows

- effectively proof by case analysis

### Example

![](./images/proof%20example%204.png)

## Negation

$\neg \Phi \equiv \Phi \Rightarrow \bot$
$\\\qquad\;\;↳\;\; \neg \Phi \lor \bot$
$\\\qquad\;\;↳\;\; \neg \Phi$

Introduction rule:
- assume $\Phi$ and show $\bot$

Elimination rule:
- if we have $\Phi$ and $\bot \Phi$ we can conclude false

> the only way to get $\bot$ is from a contradictory assumptions ($\neg$ elimination)

$\bot$ Elimination rule: if we have $\bot$ then you can have anything, as the assumptions make everything vacuous truths

### Examples

![](./images/proof%20example%205.png)

Claim $p \land ¬p \Rightarrow q$
1. assume $p \land ¬p$
2. $\qquad p$
3. $\qquad \neg p$
4. $\qquad \bot$
5. $\qquad q$
6. $p \land ¬p \Rightarrow q$

## Law of the Excluded Middle - $\Phi \lor \Phi \equiv \top$

- at any point we may use it in a proof, ... by LEM

Claim $\neg\neg p \Rightarrow p$

![](./images/proof%20example%206.png)

- use LEM as a last resort


# 03 - Predicates and Quantifiers

- atomic propositions: statements that are true or false

- propositions connected with $\land, \lor, \neg, \Rightarrow$


properties that hold for all objects of a given type

statements that assert there exists an object with a particular property

relationships between objects

## Predicates

- "The temperature is greater than 18 degrees"

- "the temperature" is the subject
- "is greater than 18 degrees" is the property about the subject - the _predicate_

- define $P$ to mean "is greater than 18"

- define $P(t)$ to mean "t is greater than 18", where t is a variable representing the temperature

- $P(t)$ represents a propositional function
    - e.g. $P(10)$ is false


by assigning values to the variables in a propositional function, we can determine the truth of it

**Quantification** can also create a proposition from a propositional function, they allow us to express the extent to which

## Quantifiers

- universal quantifier "for all" elements in the domain $\forall x\ P(x)$

- existential qualifier "there exists" one or more elements in the domain $\exists x\ P(x)$

- the domain is the set of all values a variable can take
    - let P(x) be x^2 over $\Z$ $\forall x\ P(x)$ is true but not $\R$


$\forall x\ P(x)$ is true when P(x) is true for _every_ value of x in the domain

$\forall x\ P(x)$ is false when P(x) is false for _at least one_ value of x in the domain


$\exists x\ P(x)$ is true when P(x) is true for _at least one_ value of x in the domain

$\exists x\ P(x)$ is false when P(x) si false for _every_ value of x in the domain

in general: $\forall x\ P(x) \Rightarrow \exists x\ P(x)$
only true when domain is not empty

## Domains

### Finite
**you can list every element**

- the universal qualification ($\forall$) is a conjunction of all $P(x_i)$
    - to check: assume true and search for a counterexample

- the existential qualification ($\exists$) is a disjunction of all $P(x_i)$
    - to check: assume false and find a case where it is true

### empty

- $\forall$ is true because there are no counterexamples

- $\exists$ is false because there are no true cases


## notation

$\forall x.\ P(x)$ and $\exists x.\ P(x)$, the domain is the universe

$\forall x:D.\ P(x)$ and $\exists x:D.\ P(x)$ for a given domain $D$

## how to use them

> they have the highest precedence of all operators from propositional logic

variables are **bound** when a quantifier is used on them, otherwise they are **Free**

so all variables must either be bound or assigned a value to be able to evaluate

bound variables are scoped to the qualifier they are bound in

this means that you can rename bound variables to anything you want

## negation

**negation is the de Morgan's law**

$\neg \forall x.\ P(x) \equiv \exists x.\ \neg P(x)\\$
$\neg \exists x.\ P(x) \equiv \forall x.\ \neg P(x)$

## Nesting
- Let Mother(x, y) denote x is the mother of y
- "Every person has a mother": $\forall y\ \exists x\ Mother(x, y)$
- but $\exists x\ \forall y\ Mother(x, y)$ means that there is someone who is everyone's mother


## translating from NL

be careful with existential qualifier and vacuous truths

there exists - should combine things with conjunction

for all - should combine things with implication

## formula

- atomic formula, formed by applying predicates to terms
- all atomic formulas are well-formed

## e.g.
- variables: VL = {x,y}
- objects: CL = {Gromit, Wallace}
- functions: FNL = {owner, mother, father}
- predicates: PNL = {Rich, Happy}

## Informal proofs

- what we've seen so far
![](./images/proofs%20old.jpeg)

- new for Predicates
![](./images/proofs%20new.png)

## proving universal statements

1. **let** $x$ **be an arbitrary element of** $D$, make _no_ extra assumptions about $x$ beyond $x \in D$

2. show that $P(x)$ holds (with any proof strategy)

3. conclude "since $x$ was arbitrary, $\forall x : D.P(x)$."

To use a hypothesis

1. write "since $\forall x : D.P(x)$, in particular $P(t)$", for any specific term $t \in D$.

2. work with $P(t)$

3. you may instantiate the same universal statement multiple times, with different choices of t

To disprove $\forall x : D.P(x)$

- , find a single counterexample $x_0 \in D$ such that $\neg P(X_0)$ holds true

## Proving Existential Statements

1. find (or construct) a specific term $t \in D$
2. show $P(t)$ holds
3. conclude: "therefore $\exists x : D.P(x)$" taking $x = t$

to use

1. say "let $x_0$ be a witness i.e. $P(x_0)$ holds"
2. work with $x_0$ bout all you know is that $P(x_0)$ holds
3. any conclusion must not depend on the specific identity of $x_0$

to disprove $\exists x : D.P(x)$

- show $\forall x : \neg D.P(x)$

## Informal(!) Proof eg
S = student, W = works hard, Pass = passes

$\forall x : S(x) \Rightarrow W(x)$ and $\forall x : W(x) \Rightarrow Pass(x)$

1. let x be an arbitrary person
2. assume they are a student
3. since $\forall x : S(x) \Rightarrow W(x)$, by modes ponens with $S(x)$: so we get W(x)
4. since $\forall x : W(x) \Rightarrow Pass(x)$, by modes ponens with $W(x)$: so we get Pass(x)
4. therefore $S(x) \Rightarrow Pass(x)$


## Uniqueness

$\exists! x .P(x)\; \equiv \; \exists. x\ (P(x) \land \forall y.(P(y) \Rightarrow y = x))$

effectively: x is true, and if y is true, it is the same as x

# 04 - Set theory

sets are _unordered_ collections of _distinct_ objects called _elements_

- empty set: $\empty$
    - $\empty \neq \{0\}$
- universal set: $\mathcal{U}$
    - $\mathcal{U} \notin \mathcal{U}$
- is in: $0 \in \N$
- is not in: $3.14 \notin \Z$
- union: $\N\ \cup\ -\N = \Z$
- intersection: $\N\ \cap\ -\N = \{0\}$
- difference: $\Z \setminus \N = \{-1, -2, -3, ...\}$
- subset: $\N \subseteq \Z $
    - $A \subseteq B \equiv \forall x. (x \in A \Rightarrow x \in B)$
    - for every set, $A$, $\empty \subseteq A \subseteq \mathcal{U}$
- compliment: $\overline X \equiv \{x \in \mathcal{U}\mid x \notin X\}$
- double compliment: $\overline{\overline X} = X$
- restriction (even numbers): $\{y \mid y = 2x \land x \in \N\}$

## links to predicate logic

given that:
- $A = \{x \mid P(x)\}$
- $B = \{x \mid Q(x)\}$

then:
- $A \cap B \equiv \{x \mid P(x) \land Q(x) \}$
- $A \cup B \equiv \{x \mid P(x) \lor Q(x) \}$
- $A \subseteq B \equiv \forall x. (P(x) \Rightarrow Q(x))$

the laws work the exact same as in propositional logic

## next lecture

- operations on multiple sets
- Sets of Sets - subset vs membership
- Cardinality
- Power Set
- Cartesian Product

## operations on multiple sets

$\forall e (e \in \displaystyle\bigcup^n_{i=1} A_i \Leftrightarrow e \in A_1 \lor ... \lor e \in A_n)$

$\forall e (e \in \displaystyle\bigcap^n_{i=1} A_i \Leftrightarrow e \in A_1 \land ... \land e \in A_n)$

## Indexing sets

we can index any set _I_: a family of sets $\{A_I\}_{i \in I}$
union & intersection $\bigcup _{i \in I}\{A_i\}$


e.g.
let I = {+, 0, -}
- define:
    - $\Z_+$ = {1, 2, 3}
    - $\Z_0$ = {0}
    - $\Z_-$ = {-1, -2, -3}
    - $\Z$ = $\bigcup _{i \in I}\Z_i$ (which means) $\Z_+ \cup \Z_0 \cup \Z_-$

## subset vs membership
$A = \{1\}\quad$
$B = \{1,2\}\quad$
$C = \{\{1\}, 1, 2\}\quad$
$D = \{\{1\}\}$

- $A \subseteq B \qquad A \not\in B$
- $A \subseteq C \qquad A \in C$
- $B \subseteq C \qquad B \not\in C$
- $A \not\subseteq D \qquad A \in D$

all combinations of $\subseteq$ and $\in$ are possible with the right sets

## Peano construction

the empty set can be an element of other sets:
- $\empty = \{\}$ contains 0 elements
- $\{\empty\}$ contains 1 element (the empty set)
- $\{\{\empty\}\}$ contains a set that contains the empty set

### peano Axioms
- starts with: 0, defined as the empty set
- $S(X)$ = $X \cup \{X\}$

so
- $0 = \empty$
- $1 = \{\empty\}$
- $2 = \{\empty, \{\empty\}\}$
- $3 = \{\empty, \{\empty, \{\empty\}\}\}$

## Cardinality
the number of elements

- $|\empty| = 0$
- $|A \cup B| \leqslant |A| + |B|$
- $|A \cup B| \leqslant \text{min}(|A|, |B|)$
- $|A \cup B| = |A| + |B| - |A \cap B|$

## Power Set
$\mathcal{P}(A)$ (or $2^A$)
the set that contains all subsets of $A$ (including $\empty$ and $A$)

$|\mathcal{P}(A)| = 2^{|A|}$

> like a truth table

## Cartesian Product

$A \times B$ is the set of ordered pairs $\{(x, y) | x \in A \land y \in B\}$

$A \times B \neq B \times A $

$|A \times B| = |A| \cdot |B|$

> like a 2 way table

## Set restriction

$\{x in D \mid P(x)\}$

## set projection

$\{f(x) \mid x \in D\}$