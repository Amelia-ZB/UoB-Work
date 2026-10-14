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


# algebraic data types (ADTs)

- algebraic data types

types and constructors are always capitalised

## Sum types

```hs
data Bool = True | False

-- chess example

data Player = White | Black
white :: Player
white = White
black :: Player
black = Black

data PieceType = Pawn | Knight | Bishop | Rook | Queen | King

data Suit = Hearts | Diamonds | Spades | Clubs

showSuit :: Suit -> String
showSuit Hearts = "Hearts"
showSuit Diamonds = "Diamonds"
showSuit Spades = "Spades"
showSuit Clubs = "Clubs"

```

## Product types

- generalisation over tuples

```hs
data Piece = MakePiece Player PieceType
MakePiece :: Player -> PieceType -> Piece

whiteQueen = MakePiece White Queen

promoteToQueen :: Piece -> Piece
promoteToQueen (MakePiece player, Pawn) -> (MakePiece player, Queen)

```


## Record syntax

allows you to name each component

```hs
data Piece' = Piece'_ {player :: Player, pieceType :: PieceType}

promoteToQueen' :: Piece' -> Piece'
promoteToQueen' p = p {pieceType = Queen}
```
## ADTs

combines sum & product types

```hs
data Suit = Hearts | Diamonds | Spades | Clubs
data Value = A | Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten | J | Q | K
data Card = Card_ Suit Value | Joker
```

## Inhabitants

the possible values of a type

```hs
data Unit = MkUnit
unitInhabitant :: Unit
unitInhabitant = MkUnit

data BoolOrUnit = B Bool | U Unit

boolOrUnitInhabitantOne,boolOrUnitInhabitantTwo,boolOrUnitInhabitantThree :: BoolOrUnit
boolOrUnitInhabitantOne = B True
boolOrUnitInhabitantTwo = B False
boolOrUnitInhabitantThree = U MkUnit


data BoolAndUnit = BU Bool Unit

boolAndUnitInhabitantOne,boolAndUnitInhabitantTwo :: BoolAndUnit
boolAndUnitInhabitantOne = BU True MkUnit
boolAndUnitInhabitantTwo = BU False MkUnit
```

sum types add to the number of inhabitants inhabitants
product types multiply the number of inhabitants
a -> b has |b| ^ |a| inhabitants

## Recursive ADTs

```hs
data RobotInstr
    = Dance
    | Move Int
    | Teleport {x :: Int, y :: Int}

data RobotSequence = Stop | AddInstr RobotInstr RobotSequence

doNothing = Stop
danceThenStop = AddInstr Dance Stop
danceThenMove = AddInstr Dance (AddInstr (Move 2) Stop)
```

## Monomorphic Lists

```hs
data IntList = IntEmpty | IntCons Int IntList
```


## misc

to hide from an import use `hiding (Bool(..))` the `(..)` is to also ignore the constructor as well as the type.

# Polymorphism and Type Classes

polymorphic is the opposite of monomorphic

## Polymorphic ADT

```hs
-- any lowercase latter is allowed for generic types
data List a = Empty | Cons a (List a)
```

```hs
data Either a b = Left a | Right b

exampleEitherL :: Either Int Char
exampleEitherL = Left 8

exampleEitherR :: Either Int Char
exampleEitherR = Right 'A'
```

```hs
data Maybe a = Nothing | Just a

exampleMaybeI :: Maybe Int
exampleMaybeI = Just 1

exampleMaybeJ :: Maybe Int
exampleMaybeJ = Nothing
```

## Polymorphic -> Monomorphic

you can put specific types into a polymorphic ADT to make it monomorphic

```hs
data Pair a b = MkPair a b

egPair :: Pair Int Bool
egPair = MkPair 5 True
```


## Isomorphic Types

```hs

data Bool   = True  | False
data Player = White | Black
```

Bool $\cong$ Player

sum types are isomorphic if they have the same number of inhabitants

## Polymorphic Functions

```hs

data IntList = IntEmpty | IntCons Int IntList
data CharList = CharEmpty | CharCons Char CharList

lengthIntList :: IntList -> Int
lengthIntList IntEmpty = 0
lengthIntList (IntCons i is) = 1 + lengthIntList is

lengthCharList :: CharList -> Int
lengthCharList CharEmpty = 0
lengthCharList (CharCons i is) = 1 + lengthCharList is

length :: List a -> Int
length Empty = 0 -- how does it know that IntEmpty == Empty???
length (Cons _ xs) = 1 + length xs
```


## Type Classes

```hs

data Player = P1 | P2
data Colour = Red | Green

data List a = Empty | Cons a (List a)

class Equality a where
    (===) :: a -> a -> Bool

instance Equality Player where
    P1 === P1 = True
    P2 === P2 = False
    _  === _  = False

instance Equality Colour where
    Red  === Red    = True
    Green === Green = False
    _     === _     = False

eqList :: Equality a => List a -> List a -> Bool
eqList Empty Empty = True
eqList (Cons x xs) (Cons y ys) = x === y && eqList xs ys

-- >>> eqList (Cons P1 Empty) (Cons P1 Empty)
-- True
-- >>> eqList (Cons P1 Empty) (Cons P2 Empty)
-- False

-- >>> eqList (Cons Red Empty) (Cons Red Empty)
-- True
{-
eqListPairs :: (Equality a, Equality b) => List (a, b) -> list (a, b) -> Bool
eqListPairs = undefined

eqListTris :: (Equality a, Equality b, Equality c) => List (a, b, c) -> list (a, b, c) -> Bool
eqListTris = undefined


instance Equality a => Equality (list a) where
    (===) = eqList

-- ????????????????????????

-}


```



### Show (Built in)

```hs
data Player = White | Black

instance Show Player where
    show :: Player -> String
    show White = "White"
    show Black = "Black"

data CarOrInt = I int | C Char deriving (Show, Eq)

-- >>> show (I 8)
-- "I 8"
-- >>> (C 'a') == (C 'a')
-- True
-- >>> (C 'a') == (C 'b')
-- False
-- >>> (C 'a') == (I 2)
-- False

```

## idk

**use :i in ghci**