module Check
    (
        checkColor,
        checkIfDigit,
        checkSecondParenthese,
        checkFirstParenthese,
        checkLine,
        checkLines,
        checkFile
    ) where

import Utils
import Data.Char

checkColor :: Int -> IO()
checkColor i | i < 0 || i > 255 = failure ("The given file is wrong")
checkColor i = return()

checkIfDigit :: String -> Char -> IO()
checkIfDigit s c | all isDigit s == False = failure ("The given file is wrong")
checkIfDigit s c | c == 'c' = checkColor (read s :: Int)
checkIfDigit s c = return()

checkSecondParenthese :: String -> IO()
checkSecondParenthese [] = failure ("The given file is wrong")
checkSecondParenthese (x:[]) | x /= ')' = failure ("The given file is wrong")
checkSecondParenthese (x:[]) | x == ')' = return()
checkSecondParenthese (x:xs) = checkSecondParenthese xs

checkFirstParenthese :: String -> IO()
checkFirstParenthese p | (p!!0) /= '(' = failure ("The given file is wrong")
checkFirstParenthese p = return()

checkLine :: String -> IO()
checkLine s = do
    let splitSpace = separateBy ' ' s
    let splitPoint = separateBy ',' (splitSpace!!0)
    let splitColor = separateBy ',' (splitSpace!!1)
    checkFirstParenthese (splitPoint!!0)
    checkIfDigit (remove (splitPoint!!0) '(') 'p'
    checkSecondParenthese (splitPoint!!1)
    checkIfDigit (remove (splitPoint!!1) ')') 'p'
    checkFirstParenthese (splitColor!!0)
    checkIfDigit (remove (splitColor!!0) '(') 'c'
    checkIfDigit (splitColor!!1) 'c'
    checkSecondParenthese (splitColor!!2)
    checkIfDigit (remove (splitColor!!2) ')') 'c'

checkLines :: [String] -> IO()
checkLines [] = return()
checkLines (x:xs) = checkLine x >> checkLines xs

checkFile :: String -> IO()
checkFile f = do
    content <- readFile f
    let linesOfFiles = lines content
    checkLines linesOfFiles
