perrin n = case n of
    1 -> 3
    2 -> 0
    3 -> 2
    _ -> perrin (n-2) + perrin (n-3)