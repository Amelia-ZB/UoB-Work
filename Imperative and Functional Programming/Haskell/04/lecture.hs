import Prelude hiding(Either(..), Maybe(..), length)
import System.Console.Terminfo (Color(Black))
import Language.Haskell.TH (FamilyResultSig(KindSig))

-- poly


data Either a b = Left a | Right b

exampleEitherL :: Either Int Char
exampleEitherL = Left 8

exampleEitherR :: Either Int Char
exampleEitherR = Right 'A'


data Maybe a = Nothing | Just a

exampleMaybeI :: Maybe Int
exampleMaybeI = Just 1

exampleMaybeJ :: Maybe Int
exampleMaybeJ = Nothing



------------------

data Pair a b = MkPair a b

egPair :: Pair Int Bool
egPair = MkPair 5 True



-----------------

data IntList = IntEmpty | IntCons Int IntList
data CharList = CharEmpty | CharCons Char CharList

lengthIntList :: IntList -> Int
lengthIntList IntEmpty = 0
lengthIntList (IntCons i is) = 1 + lengthIntList is

lengthCharList :: CharList -> Int
lengthCharList CharEmpty = 0
lengthCharList (CharCons i is) = 1 + lengthCharList is

length :: List a -> Int
length Empty = 0 -- how does it know that IntEmpty == Empty
length (Cons _ xs) = 1 + length xs

-----------------

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
