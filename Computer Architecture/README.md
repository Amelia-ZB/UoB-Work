# Overview


# 00 - Intro

- From electronics to how it is used by people and software
- electronics → logic gates → e.g. ALU → CPU → FDE → ISA → programs
- how computers can be used more effectively / efficiently
- abstraction as a coping mechanism for complexity
- ISA is the line between hardware & software; interface
- Formative: (wk6 wk12), (wk18, wk24) – reading & revision weeks
- summative: (wk10 30%), (assessment period 70%)
- after reading week -1 lecture & optional Labs, more relaxed
- coursework deadline wk10
  - available now, but meant to start wk7
  - not just hardware oriented, e.g. how to write better software

# 01 - propositional Logic & Boolean Algebra

## propositional logic

propositions are basically statements e.g. 
_"the temperature is 20°C"_

1. can be evaluated ~~"theis statement is false"~~
2. must be unambiguous ~~"the temperature is too hot"~~
3. can include free variables "the temperature is $x$°C"
4. can be represented using a short-hand variable or function: f = ... or g(x) = ...


### Conectives can combine statements

- not $\neg$ NOT
- and $\land$ AND
- inclusive or $\lor$ OR
- exclusive or $\oplus$ XOR
- implication $\Rightarrow$
- equivalence $\equiv$ XNOR


### Data-flow Diagram

very similar to the mathematical tree approach

![data-flow diagram](./images/data%20flow%20diagram.png)


### Truth Tables

|$x$|$y$|$x \oplus y$|
|-|-|-|
|F|F|F|
|F|T|T|
|T|F|T|
|T|T|F|

- usefull as a lookup table

- or use it as a specification

![data-flow diagram with truth table](./images/data%20flow%20and%20truth%20table.png)

- it can be helpfull to ad intermediates to truth tables



## Boolean Algebra

$x \lor \text{false} \equiv x$

$x \land \text{true} \equiv x$

AND, OR, NOT are _native_ operators

XOR, NAND, NOR, XNOR are _derived_ operators

### Rules

1. $ \mathbb{B} = \{0, 1\} $
2. shorten every statement to either a _variable_ or _function_
3. use _unary operators_ and _binary operators_ to form expressions
4. manimulate expressions according to axioms


### New Truth Tables

|$x$|$y$|$x \oplus y$|
|-|-|-|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|


### Axioms

![axioms of boolean algebra](./images/axioms1.png)
![axioms of boolean algebra](./images/axioms2.png)
![axioms of boolean algebra](./images/axioms3.png)
![axioms of boolean algebra](./images/axioms4.png)

