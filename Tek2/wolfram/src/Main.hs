module Main where
import System.Environment
import System.Exit
import Data.Char
import Wolfram
import Utils
import Args

main :: IO()
main = do
    args <- getArgs
    let end = len args :: Int
    if end < 2
        then failure "It must be a --rule followed by 30, 90 or 110 number"
    else checkArgs end 0 args
    getArguments end args
    exitSuccess