module Primes where

is_prime :: [Bool] -> Bool
is_prime l = 
    let test_num = length l in
    any (\x -> (index_of_x `mod` test_num) == 0) l


search :: [Bool] -> Int -> [Bool]
search l n = 
    if length l > n+1
        then l
        else search ((is_prime l) : l) n

primes_up_to n = 
    let
        sieve = [True, False, False]
    in
    search sieve n

-- >>> primes_up_to 10
-- [True,True,True,True,True,True,True,True,True,True,False,False]


-- >>> [1, 2, 3] !! 3
-- Prelude.!!: index too large
