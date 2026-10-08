import GHC.Conc (ThreadStatus(ThreadDied))
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


data Card = Card_ Suit Value {-| Joker-} -- adding this makes it a full ADT

