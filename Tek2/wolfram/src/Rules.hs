module Rules 
    (
        rule30,
        rule90,
        rule110,
        ruleErrors,
        isValidRule,
        getRuleNext,
        getRule,
        checkRule,
    ) where

import Utils

rule30 :: Char -> Char -> Char -> String
rule30 '*' ' ' ' ' = "*"
rule30 ' ' '*' '*' = "*"
rule30 ' ' '*' ' ' = "*"
rule30 ' ' ' ' '*' = "*"
rule30 a b c       = " "

rule90 :: Char -> Char -> Char -> String
rule90 '*' '*' ' ' = "*"
rule90 '*' ' ' ' ' = "*"
rule90 ' ' '*' '*' = "*"
rule90 ' ' ' ' '*' = "*"
rule90 a b c       = " "

rule110 :: Char -> Char -> Char -> String
rule110 '*' '*' ' ' = "*"
rule110 '*' ' ' '*' = "*"
rule110 ' ' '*' '*' = "*"
rule110 ' ' '*' ' ' = "*"
rule110 ' ' ' ' '*' = "*"
rule110 a b c       = " "

ruleErrors :: Int -> IO()
ruleErrors (-1) = failure "No --rule detected !"
ruleErrors (-2) = failure "It isn't any value after --rule !"
ruleErrors (-3) = failure "The value after --rule must be 30, 90 or 110 !"
ruleErrors rule = putStr ""

isValidRule :: Int -> Int -> String -> [String] -> Int
isValidRule i end search tab | i == (end-1) && (tab!!i) /= search = -3
isValidRule i end search tab | (tab!!i) == search = read (tab!!i)
isValidRule i end search tab = isValidRule (i+1) end search tab

getRuleNext :: Int -> [String] -> Int
getRuleNext i args = do
    let tab = ["30", "90", "110"]
    isValidRule 0 (len tab) (args!!(i+1)) tab

getRule :: Int -> Int -> [String] -> Int
getRule end i args | i == end = -1
getRule end i args | (args!!i) == "--rule" && i == (end-1) = -2
getRule end i args | (args!!i) /= "--rule" && i == (end-1) = -1
getRule end i args | (args!!i) == "--rule"                 = getRuleNext i args
getRule end i args = getRule end (i+1) args

checkRule :: String -> Int -> IO()
checkRule str n | str /= "--rule" && str /= "--move" && str /= "--window" &&
    str /= "--start" && str /= "--lines"
        = failure
 ("The argument " ++ show n ++ "->" ++ str ++ "\" isn't a valid instruction")
checkRule str n = return()