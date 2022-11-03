module Utils
    (
        len,
        getPath,
        getItInt,
        getItFloat,
        isPair,
        isNb,
        failure,
        separateBy,
        remove,
    ) where

import System.Exit
import Data.List
import Data.Char

len :: (Num b) => [a] -> b
len [] = 0
len xs = sum [1 | _ <- xs]

getPath :: String -> Int -> Int -> [String] -> String
getPath search end i args | (args!!i) == search = args!!(i+1)
getPath search end i args = getPath search end (i+1) args

getItInt :: String -> Int -> Int -> [String] -> Int
getItInt search end i args | (args!!i) == search = read (args!!(i+1)) :: Int
getItInt search end i args = getItInt search end (i+1) args

getItFloat :: String -> Int -> Int -> [String] -> Float
getItFloat search end i args | (args!!i) == search = read (args!!(i+1)) :: Float
getItFloat search end i args = getItFloat search end (i+1) args

isPair :: Int -> Bool
isPair n = mod n 2 == 0

isNb :: String -> Bool
isNb (xs:ys) | xs == '.' = isNb ys
isNb (xs:ys) | isNumber xs = isNb ys
isNb (xs:_) = True
isNb n = False

remove :: String -> Char -> String
remove [] r = []
remove (x:xs) r | x == r = remove xs r
remove (x:xs) r = x:remove xs r

separateBy :: Eq a => a -> [a] -> [[a]]
separateBy chr = unfoldr sep where
    sep [] = Nothing
    sep l  = Just . fmap (drop 1) . break (== chr) $ l

failure :: String -> IO()
failure str = putStrLn str >>
    exitWith (ExitFailure 84)