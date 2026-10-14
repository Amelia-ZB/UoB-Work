import Prelude hiding (Bool(..))

data Bool = True | False


data Player = White | Black
data PieceType = Pawn | Knight | Bishop | Rook | Queen | King
data Piece = Piece_ Player PieceType

data Piece' = Piece'_ {player :: Player, pieceType :: PieceType}



whiteQueen = Piece_ White Queen
blackQueen = Piece'_ {player = Black, pieceType = Queen}

promoteToQueen :: Piece -> Piece
promoteToQueen (Piece_ player Pawn) = (Piece_ player Queen)

promoteToQueen' :: Piece' -> Piece'
promoteToQueen' p = p {pieceType = Queen}


data Suit = Hearts | Diamonds | Spades | Clubs
data Value = A | Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten | J | Q | K
data Card = Card_ Suit Value | Joker

-- full ADT




robotCode :: RobotInstr
robotCode = Dance



data Unit = MkUnit
unitInhabitant :: Unit
unitInhabitant = MkUnit

data Element = Water | Fire | Earth | Air

data BoolOrUnit = B Bool | U Unit

boolOrUnitInhabitantOne,boolOrUnitInhabitantTwo,boolOrUnitInhabitantThree :: BoolOrUnit
boolOrUnitInhabitantOne = B True
boolOrUnitInhabitantTwo = B False
boolOrUnitInhabitantThree = U MkUnit


data BoolAndUnit = BU Bool Unit

boolAndUnitInhabitantOne,boolAndUnitInhabitantTwo :: BoolAndUnit
boolAndUnitInhabitantOne = BU True MkUnit
boolAndUnitInhabitantTwo = BU False MkUnit

-- Recursive ADTs

data RobotInstr
    = Dance
    | Move Int
    | Teleport {x :: Int, y :: Int}

data RobotSequence = Stop | AddInstr RobotInstr RobotSequence

doNothing = Stop
danceThenStop = AddInstr Dance Stop
danceThenMove = AddInstr Dance (AddInstr (Move 2) Stop)

-- monomorphic Lists


data IntList = IntEmpty | IntCons Int IntList
