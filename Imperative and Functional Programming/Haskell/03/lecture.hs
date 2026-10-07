module Lecture where

import Prelude hiding (head, tail, sum, reverse)
import Data.Char (toLower, toUpper)

is123 :: [Int] -> Bool
is123 x = case x of
    1 : 2 : 3 : [] -> True
    _ -> False

{-

>>> is123 (1:2:3:[])
True

-}

head xs = case xs of
    x : xs' -> x

tail (_ : x) = x

{-

>>> head (1:2:3:[])
1
>>> tail (3:2:1:[])
[2,1]

-}

-- >>> tail [1, 2, 3, 4]
-- [2,3,4]


foo :: [Int] -> Int
foo [x, y, z] = x + z
foo _ = 0

-- >>> foo [1, 2, 3]
-- 4

-- >>> foo [1, 4]
-- 0


isLength3 [_, _, _] = True
isLength3 _ = False

-- >>> isLength3 [1, 2]
-- False

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



-- toLower :: Char -> Char


lower :: String -> String
lower [] = []
lower (c : s') = ((toLower c) : (lower s'))

upper :: String -> String
upper [] = []
upper (c : s') = ((toUpper c) : (upper s'))


{-

>>> lower "HIIII!"
"hiiii!"

>>> upper "Hello World!"
"HELLO WORLD!"
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
        -- helper acc (c : cs) = helper (c : acc) cs
        -- helper acc [] = acc
        helper acc str = case str of
            [] -> acc
            _ -> 


-- >>> reverse "Hello World!"
-- "!dlroW olleH"