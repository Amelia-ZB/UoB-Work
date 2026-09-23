module ExpressionsLive where

square x = x*x

-- square_2 x y = x*x + y*y
square_2 x y = square x + square y

make_odd n = if mod n 2 == 0
                    then n+1
                    else n

-- >>> make_odd 6
-- 7




nums = [1, 33, 2, 7, 13, 8, 17, 26, 63]


more_nums = [3, 5]

all_nums = -1 : (nums ++ more_nums)

-- >>> all_nums
-- [-1,1,33,2,7,13,8,17,26,63,3,5]

-- ++ is slow, it must walk the entire left list, use : to insert at start O(1)

-- >>> all_nums !! 1
-- 1
-- accessing elements is done with !!

-- >>> [1, 3, 8] > [1, 3, 7]
-- True
-- when lists are compared, the first non-equal pair are used

-- >>> head nums -- the first element
-- >>> tail nums -- everything except the first element
-- >>> last nums -- the last element
-- >>> init nums -- everything except the last element
-- 1
-- [33,2,7,13,8,17,26,63]
-- 63
-- [1,33,2,7,13,8,17,26]

-- >>> length nums
-- 9

-- >>> null [1, 2, 3]
-- False

-- >>> null []
-- True

-- >>> take 1 [1, 2, 3, 7, 11, 32]
-- >>> take 2 [1, 2, 3, 7, 11, 32]
-- >>> take 100 [1, 2, 3, 7, 11, 32]
-- >>> take 0 [1, 2, 3, 7, 11, 32]
-- [1]
-- [1,2]
-- [1,2,3,7,11,32]
-- []


-- drop is the opposite

-- >>> drop 1 [1, 2, 3, 7, 11, 32]
-- >>> drop 2 [1, 2, 3, 7, 11, 32]
-- >>> drop 100 [1, 2, 3, 7, 11, 32]
-- >>> drop 0 [1, 2, 3, 7, 11, 32]
-- [2,3,7,11,32]
-- [3,7,11,32]
-- []
-- [1,2,3,7,11,32]


-- >>> maximum nums
-- >>> minimum nums
-- >>> sum nums
-- >>> product nums
-- 63
-- 1
-- 170
-- 1337944608

-- >>> elem 3 [1, 2, 3, 10]
-- >>> elem 7 [1, 2, 3, 10]
-- True
-- False
-- check if value is an element of a list

-- >>> [1..20]
-- >>> [2,4..20]
-- [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
-- [2,4,6,8,10,12,14,16,18,20]
-- specify [⟨start⟩,⟨next⟩..⟨max (inclusive)⟩]

-- >>> take 10 (cycle [1,2,3]) 
-- >>> take 10 (repeat 5)
-- [1,2,3,1,2,3,1,2,3,1]
-- [5,5,5,5,5,5,5,5,5,5]

-- >>> [x*2 | x <- [1..10]]
-- >>> [x*2 | x <- [1..10], x*2 >= 12]
-- [2,4,6,8,10,12,14,16,18,20]
-- [12,14,16,18,20]
