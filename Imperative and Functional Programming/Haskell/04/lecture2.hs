

filterOdd :: [Int] -> [Int]
filterOdd [] = []
filterOdd (x : xs)
    | odd x  = x : filterOdd xs
    | even x = filterOdd xs

-- >>> filterOdd [1,2,34,5,6,7,8,9]
-- [1,5,7,9]

filterEven :: [Int] -> [Int]
filterEven [] = []
filterEven (x : xs)
    | even x  = x : filterEven xs
    | odd  x = filterEven xs

-- >>> filterEven [1,2,3,4,5,6,7,8,9]
-- [2,4,6,8]


filterCond :: (a -> Bool) -> [a] -> [a]
filterCond _ [] = []
filterCond condition (x : xs)
    | condition x = x : filterCond condition xs
    | otherwise   =     filterCond condition xs

-- >>> filterCond [1,2,3,4,5,6,7,8,9] (\x -> not (even x))
-- [1,3,5,7,9]

filterEven' :: [Int] -> [Int]
filterEven' x = filterCond even x

filterOdd' :: [Int] -> [Int]
filterOdd' x = filterCond odd x



mapDouble :: [Int] -> [Int]
mapDouble [] = []
mapDouble (x : xs) = x * 2 : mapDouble xs

mapAddTwo :: [Int] -> [Int]
mapAddTwo [] = []
mapAddTwo (x : xs) = x + 2 : mapAddTwo xs

mapAny :: (a -> b) -> [a] -> [b]
mapAny _ [] = []
mapAny f (x : xs) = f x : mapAny f xs

mapShowable :: Show a => [a] -> [String]
mapShowable x = mapAny show x

------------------------------------------------------------------------------------------
