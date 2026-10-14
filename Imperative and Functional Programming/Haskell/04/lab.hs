
-- 1

isJust :: Maybe a -> Bool
isJust Nothing = False
isJust _ = True

fromMaybe :: a -> Maybe a -> a
fromMaybe val Nothing = val
fromMaybe _ (Just val) = val

forget :: Either String a -> Maybe a
forget (Left _) = Nothing
forget (Right val) = Just val

test = Just (Right True)
test :: Maybe (Either a Bool)

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (div x y)

safeDiv' :: Int -> Int -> Either String Int
safeDiv' _ 0 = Left "Error can't divide by 0"
safeDiv' x y = Right (div x y)

checkForErrors :: [Either String a] -> Either String [a]
checkForErrors [] = Right [] -- empty
checkForErrors (Left x : xs) = Left x -- error
checkForErrors (Right x : xs) = case checkForErrors xs of
    Left y -> Left y
    Right y -> Right (x : y)

{-
>>> checkForErrors [Right 10, Right 9]
>>> checkForErrors [Right 10, Left "Error!", Right 9]
>>> checkForErrors [Right 10, Left "First error!", Right 9, Left "Second error!"]
Right [10,9]
Left "Error!"
Left "First error!"
-}


-- 2

data Expr = Lit Int
    | Add Expr Expr
    | Mul Expr Expr
    | Sub Expr Expr

size :: Expr -> Int
size (Lit _) = 1
size (Add  x y) = size x + size y
size (Mul  x y) = size x + size y
size (Sub  x y) = size x + size y

eval :: Expr -> Int
eval (Lit x) = x
eval (Add  x y) = eval x + eval y
eval (Mul  x y) = eval x * eval y
eval (Sub  x y) = eval x - eval y

pretty :: Expr -> String
pretty (Lit x) = show x
pretty (Add  x y) = (pretty x) ++ " + " ++ (pretty y)
pretty (Mul  x y) = (pretty x) ++ " * " ++ (pretty y)
pretty (Sub  x y) = (pretty x) ++ " - " ++ (pretty y)

{-
>>> pretty (Sub (Lit 5) (Lit 3))
"5 - 3"

-}

-- 3.1

addTwo :: Int -> Int
addTwo x = x + 2

addTwo' :: Num a => a -> a
addTwo' x = x + 2

-- addTwo' 'a'

-- >>> addTwo' 3.5
-- 5.5
-- >>> addTwo' 3
-- 5

-- 3.2

data RPS = Rock | Paper | Scissors deriving (Eq, Show)

-- instance Eq RPS where
--     (==) Rock Rock = True
--     (==) Paper Paper = True
--     (==) Scissors Scissors = True
--     (==) _ _ = False


shoot :: RPS -> RPS -> Bool
shoot Rock Scissors = True
shoot Scissors Paper = True
shoot Paper Rock = True
shoot _ _ = False

-- >>> shoot Rock Paper
-- False

-- 3.3

instance Ord RPS where
    (<=) Rock Scissors = False
    (<=) Scissors Paper = False
    (<=) Paper Rock = False
    (<=) _ _ = True


-- 4.1

data Colour = Black|White
data Crowned = Y|N
data Draught = MkDraught Colour Crowned

-- a) 1

-- b)
data Checker = Checker {colour :: Either () (), crowned :: Either () ()}

-- c)
t1 = Checker {colour = Left (), crowned = Left ()}
t2 = Checker {colour = Left (), crowned = Right ()}
t3 = Checker {colour = Right (), crowned = Left ()}
t4 = Checker {colour = Right (), crowned = Right ()}

-- d)
to :: Draught -> Checker
from :: Checker -> Draught

to (MkDraught Black Y) = Checker {colour = Left (), crowned = Left ()}
to (MkDraught Black N) = Checker {colour = Left (), crowned = Right ()}
to (MkDraught White Y) = Checker {colour = Right (), crowned = Left ()}
to (MkDraught White N) = Checker {colour = Right (), crowned = Right ()}

from Checker {colour = Left (), crowned = Left ()}   = MkDraught Black Y
from Checker {colour = Left (), crowned = Right ()}  = MkDraught Black N
from Checker {colour = Right (), crowned = Left ()}  = MkDraught White Y
from Checker {colour = Right (), crowned = Right ()} = MkDraught White N

-- 5

data Suit = Hearts|Diamonds|Clubs|Spades deriving (Show, Eq)

type Pip = Int
data Court = Ace | Jack | Queen | King deriving (Show, Eq, Ord)

type Rank = Either Pip Court

data Card = Joker | MkCard Suit Rank deriving Show

instance Eq Card where
    (==) Joker Joker = True
    (==) (MkCard s1 r1) (MkCard s2 r2) = s1 == s2 && r1 == r2

snap :: Card -> Card -> String
snap (MkCard _ r1) (MkCard _ r2) = if r1 == r2
    then "SNAP"
    else "..."
snap _ _ = "..."

instance Ord Suit where
    (<=) Spades _ = False
    (<=) _ Clubs = False
    (<=) _ Diamonds = False
    (<=) _ _ = True

instance Ord Card where
    (<=) Joker (MkCard _ _) = False
    (<=) (MkCard s1 r1) (MkCard s2 r2)
        | s1 < s2 = True
        | otherwise = r1 < r2


-- 6

data NotSoPerfectTree a = Tip a | Node (NotSoPerfectTree a) (NotSoPerfectTree a) deriving Show

copy :: a -> (a, a)
copy x = (x, x)

quadple :: a -> ((a, a), (a, a))
quadple x = copy (copy x)

