foo :: Double
foo = 3.14

bar :: Int -> Bool
bar n = (n `mod` 2 == 0)

baz :: Int -> Double -> (Int, Double)
baz x y = (x, y)


-- >>> :t baz 7
-- baz 7 :: Double -> (Int, Double)
