# 00 - Introduction

> functions are almost always pure

> [!IMPORTANT]
> run with `ghci *.hs`

- functional programming is a paradigm
- focus on applying, composing, manipulating, and functions

- multiple choice exam in December
- no coursework

- we get template files for each lecture
- live coded files avaliable after the lecture
    - 'blue peter files'
    - takeaways at the end

- worksheets every week in labs
    - there are lots of questions - not expected to do all of them in the 2hrs
- groups of >= 2

- xcel formulas are functional!
> [!IMPORTANT]
> paper: "chatGPT is bullshit"

## how to do well

- do the stared questions on the worksheets
- dont get stuck on the 'dagger' (extra hard) questions
- ask questions & discuss with peers, TAs, and Lecturers (in that order)
- compile & test code regularly; read the warnings & errors
- be inquisitive, take responaibility for own learning
- ~2.5hrs / week self directed study
- **experiment like a (computer) <u>scientist</u>**


## Haskell is a _Language_

- preactice reading, writing, speaking
- Haskell is not harder it is _different_
- steep learning curve
- dont try and translate from Imperative
- build from the ground up, on Haskell's terms
- Same syntax ≠ same semantics

# 01 - Expressions & Evaluation

```hs
(\y -> y + 2) 5
```

$(\lambda y.\ y+2)\ 5$

## List comprehensions

```hs
[x*2 | x <- [1..10]]
--> [2,4,6,8,10,12,14,16,18,20]
```

$\equiv$

$ S = \{ x\cdot 2\ |\ x \in \mathbb N,\; x \leqslant 10 \}$

```hs
[x*2 | x <- [1..10], x*2 >= 12]
--> [12,14,16,18,20]
```

$\equiv$

$ S = \{ x\cdot 2\ |\ x \in \mathbb N,\; x \leqslant 10\ \land x\cdot 2 \geqslant 12\}$

## evaluating functions

- **taken directly from lambda calculus**
    - sub the value in for every instance of the variable

## functions

- **church turing thesis -> turing machines**
- **church invented lambda calculus**

- lambdas are nameless function

```hs
f = \y -> y * 10

>>> f 2
--> (\y -> y * 10) 2
--> {y = 2} (2 * 10)
--> 20
```

you can nest lambdas to have multiple inputs
```hs
add = \x -> (\y -> x + y)

-- >>> add 4 5
-- 9
```

Haskell has some syntactic sugar to make it more readable than pure lambda calculus
```hs
add = \x y -> x + y
```
or even better

```hs
add x y = x + y
```

