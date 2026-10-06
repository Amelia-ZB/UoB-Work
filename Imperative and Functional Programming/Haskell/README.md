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

- must pass exam 80%
- coursework 20%

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

# Misc Notes

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

# 01 - Expressions & Evaluation

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

## recap from minute sheet

- everything in haskell is an expression
- functions are a special type of expression, 

## environment and scope

- parameters to lambdas are scoped to only that lamda function

``` hs
foo = ((\x -> x) 5) + ((\x -> x) 2) -- the two x variables are different
-- y = 7
```

``` hs
bar = 5
baz = bar + bar
fizz = bar + (\bar -> bar) 2 -- the bar within the lambda is different to the global one
-- fizz = 7
```

# Branching (Pattern matching)

- all branches are done with pattern matching, using a case statement

```hs
foo x = case x of
    1 -> "bish"
    2 -> "bash"
    _ -> "bosh"
{-
>>> foo 1
"bish"

>>> foo 2
"bash"

>>> foo 3
"bosh"
-}
```

```hs
foo' x = case x of
    1 -> "bish"
        2 -> "bash" -- throws error (whitespace is significant)
    1 -> "bing" -- gets a yellow squiggle, repeted case
{-
>>> foo' 1
"bish"

>>> foo' 3
-- Exception: Non-exaustive patterns in case
-}
```

syntactic sugar allows for:
```hs
foo x = case x of
    1 -> "bish"
    2 -> "bash"
    _ -> "bosh"

-- to be written as

foo 1 = "bish"
foo 2 = "bash"
foo _ = "bosh"

```

## syntactic sugar

```hs
bar n = if n < 0
        then "negative"
        else if n <= 9 
            then "single digit"
            else "multi digit" -- must provide else

-- this is equivalent to

bar' n
    | n < 0     = "negative" -- the | is a guard, it will check a condition after the case matches
    | n <= 9    = "single digit"
    | otherwise = "multi digit" -- otherwise is just defined as True

-- is equivalent to

bar'' = \n ->
    case n < 0 of
        True -> "bigger than 10"
        False -> case n <= 9 of
            True -> "single digit"
            False -> "multi digit"
```

you can use let to create local varables

```hs
baz x =
    let
        xSquared = x*x
        twox = 2*x
        result = twox + xSquared
    in result

-- or

baz x = result
    where
        xSquared = x*x
        twox = 2*x
        result = twox + xSquared

```

# Recursion

- there are not loops, only recursion

```hs
triangle n = if n == 1
             then 1 -- base case
             else n + triangle (n - 1) -- recurse

triangle' n = case n of
    1 -> 1
    _ -> n + triangle (n - 1)

triangle'' n
    | n == 1 = 1
    | otherwise = n + triangle (n - 1)

{-
>>> triangle 1
>>> triangle 2
>>> triangle 3
>>> triangle 4
1
3
6
10
-}


```

## examples

### [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)

```hs
fibonacci n = case n of
    1 -> 1
    2 -> 2
    _ -> fibonacci (n-1) + fibonacci (n-2)
```

### [Padovan Sequence](https://en.wikipedia.org/wiki/Padovan_sequence)

- 1 1 1 2 2 3 4 5 7 9 12 16 21 28 37 49 65 86 114 151 200 265 ...

```hs
padovan n = case n of
    1 -> 1
    2 -> 1
    3 -> 1
    -- 4 -> padovan 2 + padovan 1
    -- 5 -> (padovan (5 - 2)) + (padovan (5 - 3))
    _ -> padovan (n - 2) + padovan (n - 3)
```


### [Lucas Sequence](https://en.wikipedia.org/wiki/Lucas_sequence)

- 2 1 3 4 7 ...

```hs
lucas n = case n of
    1 -> 2
    2 -> 1
    _ -> lucas (n-1) + lucas (n-2)

-- or

lucas' 1 = 2
lucas' 2 = 1
lucas' _ = lucas' (n-1) + lucas' (n-2)

```

### [Perrin Sequence](https://en.wikipedia.org/wiki/Perrin_number)

```hs
perrin n = case n of
    0 -> 3
    1 -> 0
    2 -> 2
    _ -> perrin (n-2) + perrin (n-3)
```

# Types

- Values
    - bools
        - Bool
    - numbers
        - Int
        - Double
    - text
        - Char (')
        - String (")
    - tuples
        - (⟨Any⟩, ⟨Any⟩, ...)

- Functions
    - ⟨input type⟩ -> ⟨output type⟩

## Type Annotations

```hs
foo :: Double
foo = 3.14

bar :: Int -> Bool
bar n = (n `mod` 2 == 0)

baz :: Int -> Double -> (Int, Double)
baz x y = (x, y)

{-
>>> :t baz
       baz        :: Int -> Double -> (Int, Double)

>>> :t baz 7
       baz 7      :: Double -> (Int, Double)

>>> :t baz 7 3.14
       baz 7 3.14 :: (Int, Double)
-}
```

```hs
selectSecond :: Int -> String -> Bool -> String
selectSecond a b c = b
```

## Type Synonyms

identical to a c typedef

```hs
type Price = Double
```

makes the code much more readable by indicating your intentions

## Type Safety

- types stop you from doing something wrong accidentialy



# Lists

in every haskell file 'include Prelude' is included implicitly

strings are just lists of characters, the prelude has `type String = [Char]`

## list vs tuple

could be implemented as a tuple `egTuple::(int, char, bool)`
- fixed length
- fixed type

```hs
egList::[int]
egList = 1;2;3;[]
```

lists hare homogeneous, tuples are hererogeneous

## constructors

empty constructor:
```hs
foo::[Int]
foo = []
```

cons:
```hs
foo'::[Int]
foo' = 1 : []
```

- this does not modify the list, it creates a new one

## pattern matching with lists

```hs
is123 :: [Int] -> Bool
is123 x = case x of
    1 : 2 : 3 : [] -> True
    _ -> False

head xs = case xs of
    x : xs' -> x

tail (_ : x) = x

{-

>>> head (1:2:3:[])
1
>>> tail (3:2:1:[])
[2,1]

-}

```
these are partial functions

### syntactic sugar

```hs
-- >>> tail [1, 2, 3, 4]
-- [2,3,4]

foo :: [Int] -> Int
foo [x, y, z] = x + z
foo _ = 0

-- >>> foo [1, 2, 3]
-- 4

-- >>> foo [1, 4]
-- 0

```

## lists + recursion

```hs
sum :: [Int] -> Int
sum l = case l of
    [] -> 0
    x : l' -> x + sum l'


-- >>> sum [1, 2, 3]
-- 6


allTrue l = case l of
    [] -> True
    True : l' -> allTrue l'
    False : l' -> False

-- >>> allTrue [True, True, False]
-- >>> allTrue [True, True, True]
-- False
-- True


```

## strings

(lists of characters)

```hs

lower :: String -> String
lower [] = []
lower (c : s') = ((toLower c) : (lower s'))

upper :: String -> String
upper [] = []
upper (c : s') = ((toUpper c) : (upper s'))
-- 


{-
    >>> lower "HIIII!"
    "hiiii!"

    >>> upper "Hello World!"
    "HELLO WORLD!"


>>> upper "abc"
> toUpper 'a' : upper "bc"
>     toUpper 'b' : upper "c"
>         toUpper 'c' : upper ""
>             -- base case --
>             ""
>         "C"
>     "BC"
"ABC"

-}


strcmp :: String -> String -> Int
strcmp [] [] = 0
strcmp [] (r:rs) = -1
strcmp (l:ls) [] = 1
strcmp (l:ls) (r:rs)
    | l < r = -1
    | r < l = 1
    | l == r = strcmp ls rs

{-

>>> strcmp "apple" "aardvark"
>>> strcmp "apple" "apples"
>>> strcmp "apple" "apple"
1
-1
0

-}


reverse :: String -> String
reverse str = helper [] str
    where
        helper :: String -> String -> String
        helper acc (c : cs) = helper (c : acc) cs
        helper acc [] = acc


-- >>> reverse "Hello World!"
-- "!dlroW olleH"

```