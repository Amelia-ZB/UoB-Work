import Prelude hiding (length, sum, product, zip, take, repeat, cycle, (++))
import Distribution.Simple.Utils (xargs)
import Language.Haskell.TH.Ppr (bar)

-- 1.1

expression :: Bool -> Int -> Int -> Int
expression = \x -> \y -> \z -> if x then y + 1 else z + 1

-- 1.2

{-
Bool, Int, Int
-}

-- 2.1

headOrZero :: [Int] -> Int
headOrZero [] = 0
headOrZero (x : _) = x

-- 2.2

length :: [Int] -> Int
length [] = 0
length (_ : x) = 1 + length x

-- 2.3

{-
>>> length (1:2:[])
> 1 + length 2:[]
> 1 + 1 + length []
> 1 + 1 + 0
> 1 + 1
> 2
2
-}

-- 2.4

sum :: [Int] -> Int
sum [] = 0
sum (x : xs) = x + sum xs

-- 2.5

product :: [Int] -> Int
product [] = 0
product (x : xs) = x * product xs

-- 2.6

snoc :: Int -> [Int] -> [Int]
snoc y xs = case xs of
    [] -> [y]
    (x : x')  -> x : (snoc y x')
-- >>> snoc 2 [1, 3]
-- [1,3,2]

-- 2.7

take :: Int -> [Int] -> [Int]
take n xs
    | n == 0 = xs
    | otherwise = take (n-1) (tail xs)

-- 2.8

insert :: Int -> [Int] -> [Int] 
insert n xs
    | xs == [] = [n]
    | n < head xs = (n : xs)
    | otherwise = head xs : insert n (tail xs)

-- 2.9

isort :: [Int] -> [Int]
isort l = case l of
    (x : l') -> insert x (isort l')
    [] -> []


-- 2.10

merge :: [Int] -> [Int] -> [Int] 
merge a [] = a
merge [] b = b
merge (a : as) (b : bs) = 
    if a < b
        then a : merge as (b : bs)
        else b : merge (a : as) bs
-- >>> merge [1, 3, 5] [2, 4, 6]
-- [1,2,3,4,5,6]

-- 2.11
-- discards the longer part of the array
zip :: [Int] -> [Int] -> [(Int, Int)]
zip (a : as) [b]      = [(a, b)]
zip [a] (b : bs)      = [(a, b)]
zip (a : as) (b : bs) = (a, b) : zip as bs
-- >>> zip [2, 3, 1] [1, 4, 4]
-- [(2,1),(3,4),(1,4)]

-- 2.12

(++) :: [a] -> [a] -> [a]
(++) [] b = b
(++) (a : as) b = a : as ++ b
-- >>> (++) [1, 2] [3, 4] 
-- [1,2,3,4]

-- 2.13
bitString :: Int -> [String]
bitString 1 = ["0", "1"]
bitString n = prependAll '0' (bitString (n-1)) ++ prependAll '1' (bitString (n-1))
    where
        prependAll :: Char -> [String] -> [String]
        prependAll c [str] = [c : str]
        prependAll c (str : strs) = (c : str) : prependAll c strs

-- >>> bitString 3
-- ["000","001","010","011","100","101","110","111"]
