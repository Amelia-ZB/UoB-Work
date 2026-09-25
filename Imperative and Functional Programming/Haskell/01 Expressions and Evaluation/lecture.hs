module ExpressionsLive where

-- >>> 1 + 1
-- 2

-- >>> (2 + 3) * (15 / 3)
-- 25.0

{-

(2 + 3) * (15 / 3)
==> 5 * (15 / 3)
==> 5 * 5.0
==> 25

-}

x = 1

-- in Haskell = actualy means =, its _not_ the assignment operator

-- >>> (x + x) * 3
-- 6

{-
(x + x) * 3
==> (1 + 1) * 3
==> 2 * 3
==> 6
-}

-- camelCase is convention

-- functions use a lambda
-- this aplies a function to the number 5
-- >>> (\y -> y) 5
-- 5


-- >>> (\y -> y+1) 5
-- 6

{-
(\y -> y+1) 5
==> (y = 5 -> y+1)
==> (5+1)
==> 6
-}

inc n = n + 1
-- >>> inc 7
-- 8



add x y = x + y

-- >>> add 4 5
-- 9

