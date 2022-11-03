module Utils 
    (
        checkChar,
        charToString,
        isNb,
        isPair,
        len,
        failure,
        removeMoins,
    ) where

import Data.Char

import System.Exit

checkChar :: String -> Int -> Char
checkChar str pos | pos < 0 || pos >= length str = ' '
checkChar str pos = (str!!pos)

charToString :: Char -> String
charToString c = [c]

isNb :: String -> Bool
isNb ""  = False
isNb "." = False
isNb xs  =
    case dropWhile isDigit xs of
        ""       -> True
        ('.':ys) -> all isDigit ys
        _        -> False

isPair :: Int -> Bool
isPair n = mod n 2 == 0

len :: (Num b) => [a] -> b
len [] = 0
len xs = sum [1 | _ <- xs]

failure :: String -> IO()
failure str = putStrLn str >>
    exitWith (ExitFailure 84)

removeMoins :: String -> String
removeMoins str = [ x | x <- str, notElem x "-"]