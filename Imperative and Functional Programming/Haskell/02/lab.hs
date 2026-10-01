import Distribution.Parsec (Parsec(parsec))
import Utils.Containers.Internal.BitUtil (highestBitMask)
-- 3
myNot b = case b of
    True -> False
    False -> True

myAnd a b = case a of
    True -> b
    False -> False

calcTip c
    | c <= 10 = c*1.1
    | otherwise = c*1.15

mysterious n = if even n
                then n `div` 2
                else 3*n + 1

mysterious' n
    | even n = n `div` 2
    | otherwise = 3*n + 1

grade p
    | p < 40 = "Fail"
    | p < 50 = "3rd"
    | p < 60 = "2:2"
    | p < 70 = "2:1"
    | otherwise = "1st"

clamp low n high
    | n < low = low
    | n > high = high
    | otherwise = n

evalOp opc a b
    | opc == "add" = a + b
    | opc == "sub" = a - b
    | opc == "mul" = a * b
    | opc == "div" = a / b
    | otherwise = 0

foo 
    | happiness > 10 = "Hello!"
    | otherwise = goodbye
    where
        happiness = 10
        goodbye = "Goodbye!"

-- 4

factorial n
    | n == 1 = 1
    | otherwise = n * factorial (n-1)

fibonacci n = case n of
    1 -> 1
    2 -> 2
    _ -> fibonacci (n-1) + fibonacci (n-2)

isPrime n = 
    let
        divisor n m = ((n `mod` m) == 0)
        
        anyDivisors n m = if m == 1
            then False
            else if divisor n m
                then True
                else (anyDivisors n (m-1))
    in
        not (anyDivisors n (n `div` 2))
    
root n = getRoot n 1
    where
        getRoot n r
            | r*r == n  = r
            | r*r > n   = r-1
            | otherwise = getRoot n (r+1)


collatz n = if n == 1
                then 0
                else if even n
                    then 1 + collatz (n `div` 2)
                    else 1 + collatz (3*n + 1)

-- >>> collatz 5
-- 5