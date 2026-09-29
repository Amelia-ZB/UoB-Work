{-
Open this file in GHCi by running: ghci ExpressionsBP.hs

==============================
= Expressions and Evaluation =
==============================
Minute Sheet: https://forms.office.com/e/QZ62B9rgG8

Haskell file basics
-------------------

~demo of how to make and run a .hs file~

Module optional here, but necessary for projects. It goes at the start of your file before you write any code:
-}

module ExpressionsBP where


{-
Expressions Introduction
------------------------

Functional programming is all about *expressions and evaluation*.

In Haskell, we can evaluate expressions using GHCi (Glasgow Haskell Compiler (interactive)). GHCi is a 'REPL' (Read-Evaluate-Print-Loop). You can use it to evaluate code by using the terminal interface by running `ghci [path to Haskell file]` (e.g. `ghci ExpressionsBP.hs`) or using the HLS (Haskell Language Server) evaluation plugin to evaluate expressions in the file itself using the `>>>` syntax in a comment.

Single-line comments start with `--` and multi-line comments are enclosed by `{-` and `-}`. Comments are ignored by the compiler and let you write whatever non-code you like in the code file, usually to explain things about the code to another programmer and/or yourself in the future after you've forgotten what you wrote and why.
-}

-- this is a single line comment!
{-
this is a multiline comment!
-}

-- Your intuitions from maths and algebra will be very helpful for learning Haskell, so let's use arithmetic expressions as examples:

-- >>> 2 + 2
-- 4
-- >>> (4 + 2) * (8 + 2)
-- 60

{-
These expressions are evaluated more or less how you'd expect: evaluate (i.e. rewrite/simplify) subexpressions until there's nothing left to evaluate, e.g.

(4 + 2) * (8 + 2)
==> 6 * (8 + 2)
==> 6 * 10
==> 60

(NOTE: '==>' is *not* Haskell syntax, we're just using it informally to mean 'evaluates to')

Simple, right? So simple, you might be wondering why we're even talking about it.

In fact, it turns out that expressions and evaluation are the fundamental basis of computation in functional programming. This is very different to imperative programming, which is all about *sequences of instructions*.

Variables
---------

This difference is immediately demonstrated by how variables are treated. In both C and Haskell, we can declare a variable `x` and make it equal to the value `1`. In Haskell we write it like this:
-}

x = 1

-- To evaluate the variable `x`, we simply look at its definition `x = 1` and replace it with the right-hand side (RHS), i.e. `1`:

-- >>> x
-- 1

-- We can use `x` in other expressions like it's any other number:

-- >>> x + x
-- 2

-- >>> (x + x) * 5
-- 10

{-
Evaluation works the same as before, but now we're also evaluating the variables:

(x + x) * 5
==> (1 + 1) * 5
==> 2 * 5
==> 10

So far, this is the same as variables in C or any other imperative programming language you might have used. Here's the difference. In C you can write:

```C
int x = 1;
x = 2;
```

In Haskell, this is *nonsense*. Why? Because in Haskell `=` *really does mean equal*. If you say `x = 1` *and* `x = 2`, then that would mean `1 = 2`, which is obviously incorrect. If we try to write this, we get an error:
-}

-- x = 2 -- Error: Multiple declarations of ‘x’

{-
TAKE AWAY: Variables in Haskell are like variables in algebra, *not* like variables in C or other imperative languages. They are defined *once* and are *immutable*, i.e. they cannot be mutated/changed.

You can use any name you want for a variable as long as it's alphanumeric (+ underscores and apostrophes) and starts with a lower case letter. camelCase is the preferred naming convention in Haskell. Examples:
-}

foo = 10
foo' = 20
thisIsCamelCase = foo + foo
this_is_snake_case = foo * foo'


{-
TAKE AWAY: The body of a Haskell file is a collection of variable declarations/definitions which can be freely rearranged in any order.

Functions and Application
-------------------------

Now for what gives functional programming its name: functions are also expressions!

The implications of this are numerous and profound, but we shall save most of them for future lectures. For now, let's get to the nitty-gritty details of using them.

There are two fundamental things you can do with functions: create them and apply them.


First, we can create functions using 'lambda' syntax (`\y` is like `λy`), e.g. `\y -> y + 2` takes an expression `y` as input and then returns `y + 2`. Each lambda takes only 1 input and produces 1 output.

Then, to apply functions, we use whitespace (i.e. any number of space characters), like so:
-}

-- >>> (\y -> y) 5
-- 5
-- >>> (\y -> y)              5
-- 5

{-
This applies `5` to the function `\y -> y`. To evaluate it, we locally declare `y = 5`, then evaluate the RHS of the `->` (a.k.a the 'body' of the lambda/function).

(\y -> y) 5
==> {- y = 5 -} y
==> 5

(NOTE: we're informally using '{- y = 5 -}' to mean 'y is equal to 5 *in this expression*, i.e. locally')
-}

-- >>> (\y -> y + 2) 5
-- 7

{-
Q: What are the evaluation steps for `(\y -> y + 2) 5`?
A:
(\y -> y + 2) 5
==> {- y = 5 -} y + 2
==> 5 + 2
==> 7



TAKE AWAY: Evaluation rules
---------------------------

1. Evaluating variables: Substitute the variable with its definition, e.g. if `x = 10`

{- x = 10 -} x
==> 10

2. Evaluating function application: Declare the input variable to be equal to the provided argument and evaluate the body e.g.

(\x -> x + x) 5
==> {- x = 5 -} x + x


Fun fact: These 3 kinds of expressions (variables, lambdas, and applications) + these 2 evaluation rules are enough to *compute anything which is computable*, i.e. they are 'Turing-complete'. See: https://en.wikipedia.org/wiki/Church-Turing_thesis

This is the 'lambda calculus' and it's the foundation of all functional programming. The rules are simple, yet more powerful than they may first appear.


Named Lambda
------------

Lambdas are also known as 'anonymous functions' because they don't have names. We can give them a name like we do any other expression, using a variable:
-}

f = \y -> y * 10


{-
Q: What are the evaluation steps for `f 2`?
A:
f 2
==> (\y -> y * 10) 2     -- Evaluate `f` variable
==> {- y = 2 -} y * 10   -- Evaluate function application
==> {- y = 2 -} 2 * 10   -- Evaluate `y` variable
==> {- y = 2 -} 20       -- Evaluate multiplication
-}

-- >>> f 2
-- 20


{-
Multiple inputs
---------------

Remember, a lambda only takes a single input and the function application rule only deals with a single input too.

What if we wanted 2 or 3 or 4 inputs? Do we need to change our rules?

Not at all! We have everything we need already. Yes, a lambda can only take 1 input at a time, but if we want another input... we can output another lambda!

((\y -> (\z -> y + z)) 1) 2
==> ({- y = 1 -} (\z -> y + z)) 2    -- Application rule
==> (\z -> 1 + z) 2                  -- Variable rule
==> {- z = 2 -} 1 + z                -- Application rule
==> 1 + 2                            -- Variable rule
==> 3
-}

-- >>> ((\y -> (\z -> y + z)) 1) 2
-- 3


{-
Redundant brackets
------------------

`((\y -> (\z -> y + z)) 1) 2` has a lot of redundant brackets. Let's try to clean them up.

Function application is *left-associative*, meaning that if no brackets are present, consecutive applications implicitly group to the left, e.g.

    foo 1 2
=== (foo 1) 2  -- Correct:   Grouping application to the left
=/= foo (1 2)  -- Incorrect: Grouping application to the right

The body of a lambda starts after the `->` and extends as far as possible to the right within the brackets enclosing it.

    (\y -> y + 2)
===  \y -> y + 2

    (\y -> y + 2) 5
=/=  \y -> y + 2  5

     \y -> y + 2 5
=== (\y -> y + 2 5)


Q: Remove as many brackets as you can from `((\y -> (\z -> y + z)) 1) 2` without changing the meaning.
A:
    ((\y -> (\z -> y + z)) 1) 2
===  (\y -> (\z -> y + z)) 1  2  -- Left-associative function application
===  (\y ->  \z -> y + z ) 1  2  -- Inner lambda already enclosed by outer lambda


Precedence is also important to consider when thinking about redundant brackets. Just like with arithmetic expressions and BIDMAS/Brackets>Indices>Divide>=Multiply>Add>=Subtract, Haskell syntax has a hierarchy of precedence. We won't exhaustively detail this hierarchy because Haskell has many infix operators with different precedences (in fact, anyone can make a new operator and specify its precedence), but it's important to know that brackets are at the top and prefix function application is the next highest, e.g.

     f  3  +  f  9
=== (f  3) + (f  3)
=/=  f (3  +  f) 9

The best way to get comfortable with this is to try to add or remove redundant brackets from expressions and test whether the expressions are still the same using GHCi. Remember: praxis, praxis, praxis!

Shortcuts and Syntactic Sugar
-----------------------------

`\y -> \z -> y + z` is reasonably concise, but since it's very common to write functions with multiple inputs, Haskell has special syntax for it: `\y z -> y + z`

We can do this with any number of variables, e.g.
-}

-- >>> (\x y z -> x + z) 1 3 5
-- 6

{-
This is 'syntactic sugar' for `(\x -> \y -> \z -> x + z) 1 3 5`. We call it 'syntactic sugar' because it's a shorter and 'sweeter' syntax for writing something else. As an analogy, you can think of 'can't' as syntactic sugar for 'can not'.

'Desugaring' is when you go the other direction, e.g. expanding `\y z -> y + z` to `\y -> \z -> y + z`.

NOTE: Even though we have multi-input lambda syntax, lambdas still only take 1 input at a time. That might sound contradictory, but it's not. `\y z -> y + z` is *always* translated to `\y -> \z -> y + z` as if that's what you'd written in the first place, and that's how it's evaluated. This distinction isn't that relevant now, but it will be important later in the unit when we 'partially apply' functions.


Another common thing we want to do is give a lambda a name, e.g.
-}

addFirstLast = \x y z -> x + z

-- However, we almost always use the following syntactic sugar instead:

addFirstLast' x y z = x + z


{-
Q: What is the desugaring of `buzz x y = x * y`?
A: `buzz = \x -> \y -> x * y`


We can evaluate the same way we did before by replacing the variable with the desugared lambda:

buzz 2 3
==> (\x -> \y -> x * y) 2 3
==> {- x = 2 -} (\y -> x * y) 3
==> {- x = 2, y = 3 -} x * y
==> 2 * 3
==> 6

Or, more conveniently, we can take a shortcut:

buzz 2 3
==> {- x = 2, y = 3 -} x * y
==> 2 * 3
==> 6

Or, even shorter, we can do the substitution in the same step:

buzz 2 3
==> 2 * 3
==> 6


Environment and Scope
---------------------

It's important to note that the `y = 5` in `{- y = 5 -} y + 2` is a *local* definition. Its *scope* is limited to the body of the function. This is very similar to C or any other programming language.

Consider this example: `((\y -> y) 5) + ((\y -> y) 2)`

The `y` in `(\y -> y) 5` and the `y` in `(\y -> y) 2` are *completely unrelated*, they just happen to have the same name. For all intents and purposes, `((\y -> y) 5) + ((\y -> y) 2)` is exactly equivalent to `((\z -> z) 5) + ((\j -> j) 2)`.

The set of definitions which are in scope is called the *environment*.

These are implicit in the code, but to help with local variables and function evaluation, in this lecture, we're annotating local variables that are in the environment as above with {- y = 5 -}. This will be of particular help when there are two local variables with the same name, like in our current example:

((\y -> y) 5) + ((\y -> y) 2)
==> ({- y = 5 -} y) + ((\y -> y) 2)
==> ({- y = 5 -} y) + ({- y = 2 -} y)
==> 5 + ({- y = 2 -} y)
==> 5 + 2
==> 7

When we define a 'top level' variable, it's in scope *everywhere* in the file (unless it's 'shadowed' by a local variable of the same name), e.g.
-}

bar = 5
baz = bar + bar
fizz = bar + (\bar -> bar) 2
-- >>> baz
-- 10
-- >>> fizz
-- 7

{-
This is *not* the same as mutating variables in C. The local `bar` in `(\bar -> bar) 2` changes nothing about the top-level `bar`. They are different variables which share the same name.

Q: What does `(\y -> y + (\y -> y) 2) 10` evaluate to?
A:
(\y -> y + (\y -> y) 2) 10
==> {- y = 10 -} y + (\y -> y) 2
==> 10 + (\y -> y) 2             -- *not* `10 + (\y -> 10) 2`, that's a different `y`!
==> 10 + ({- y = 2 -} y)
==> 10 + 2
==> 12


TAKE AWAYS
===============================================================
Key:
KNOW = a fact that you have memorised / written down in a place you can find it again
UNDERSTAND = something you can explain to another, where you don't just know what, but why and how
BE ABLE TO = something you can replicate again on your own and without guidance


Haskell file basics:

KNOW .hs is the file extension for Haskell code
BE ABLE TO interpret a program with GHCi (e.g. `ghci ExpressionsBP.lhs`) and reload the code when it changes (`:r`).
KNOW Haskell files start by declaring the `module` name.

Variables:

KNOW Haskell variables are immutable.
UNDERSTAND what an immutable variable is.
UNDERSTAND the difference between variables in C and Haskell.
KNOW the body of a Haskell file is a collection of variable declarations/definitions which can be freely rearranged in any order.

Functions and application:

KNOW a lambda introduces a function and is written as a backslash: `\`.
KNOW the syntax for function application is whitespace.
BE ABLE TO create and apply functions/lambdas.

Expressions and evaluation:

BE ABLE TO add and remove redundant brackets to expressions.
UNDERSTAND functional programming performs computation by evaluating expressions, not executing instructions.
BE ABLE TO break down the evaluation of a Haskell expression (involving variables, functions, and application) into steps.

Shortcuts and Syntactic Sugar:

BE ABLE TO use the syntactic sugar for multi-input lambdas.
BE ABLE TO use the syntactic sugar for named functions.

Environment and Scope:

KNOW what an environment is.
BE ABLE TO recognise where a variable is scoped.
UNDERSTAND the difference between variable shadowing and mutation.
-}

