module Wolfram 
    (
        getArguments,
    ) where

import System.Environment
import System.Exit
import Data.Char

import Rules
import Utils
import Args

loop :: Int -> Int -> String -> Int -> String -> Int -> String
loop a z second pos firstPrint rule | a == z = second
loop a z second pos firstPrint 90   =
    loop (a+1) z (second++rule90 (checkChar firstPrint (pos-1))
    (checkChar firstPrint pos) (checkChar firstPrint (pos+1)))
    (pos+1) firstPrint 90
loop a z second pos firstPrint 30   =
    loop (a+1) z (second++rule30 (checkChar firstPrint (pos-1))
    (checkChar firstPrint pos) (checkChar firstPrint (pos+1)))
    (pos+1) firstPrint 30
loop a z second pos firstPrint rule =
    loop (a+1) z (second++rule110 (checkChar firstPrint (pos-1))
    (checkChar firstPrint pos) (checkChar firstPrint (pos+1)))
    (pos+1) firstPrint rule

fillSpaces :: Int -> String -> Int -> String
fillSpaces i str window | i == window = str
fillSpaces i str window = fillSpaces (i+1) (str++" ") window

otherString :: Int -> Int -> String -> String
otherString start end text = take (end - start) (drop start text)

specialNbSup :: Int -> Int -> String -> String
specialNbSup specialNb window str | specialNb > window = fillSpaces 0 "" window
specialNbSup specialNb window str =
    fillSpaces 0 "" specialNb ++ otherString 0 (window-specialNb) str ++
    fillSpaces 0 "" (window-length (fillSpaces 0 "" specialNb ++
    otherString 0 (window-specialNb) str))

specialNbInf :: Int -> Int -> String -> String
specialNbInf specialNb window str | length str <= (-specialNb) =
    fillSpaces 0 "" window
specialNbInf specialNb window str |
    length (otherString (-specialNb) ((-specialNb)+window) str) < 80 =
    otherString (-specialNb)
    ((-specialNb)+window) str++fillSpaces 0 ""
    (window-length (otherString (-specialNb) ((-specialNb)+window) str))
specialNbInf specialNb window str =
    otherString (-specialNb) ((-specialNb)+window) str

specialPrint :: String -> Int -> Int -> Int -> String
specialPrint str window move specialNb | specialNb >= 0 =
    specialNbSup specialNb window str
specialPrint str window move specialNb = specialNbInf specialNb window str

wolfram :: Int -> Int -> Int -> Int -> Int -> String -> Int -> Int -> Int ->IO()
wolfram rule start 0 window move firstPrint pos z i = return()
wolfram rule start line window move firstPrint pos z i | i >= start = do
    let secondPrint = loop 0 z "" (-1) firstPrint rule
    let specialNb = ((window `div` 2)-length secondPrint`div`2) + move
    putStrLn (specialPrint secondPrint window move specialNb)
    wolfram rule start (line-1) window move secondPrint (-1) (z+2) (i+1)
wolfram rule start line window move firstPrint pos z i = do
    let secondPrint = loop 0 z "" (-1) firstPrint rule
    wolfram rule start line window move secondPrint (-1) (z+2) (i+1)

getArguments :: Int -> [String] -> IO()
getArguments end args = do
    let rule = getRule end 0 args
    ruleErrors rule
    let start = getOther "--start" 0 end 0 args
    otherErrors start "start"
    let line = getOther "--lines" (-2) end 0 args
    otherErrors line "lines"
    let window = getOther "--window" 80 end 0 args
    otherErrors window "window"
    let move = getOther "--move" 0 end 0 args
    otherErrors move "move"
    wolfram rule start line window move "*" (-1) 1 0