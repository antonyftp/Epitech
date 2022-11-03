module Main
    (
        main
    ) where

import System.Environment
import System.Exit
import Image
import Data
import Utils
import Print
import Args

main :: IO ()
main = do
    argv <- getArgs
    let end = len argv :: Int
    if end == 1 && ((argv!!0) == "-h" || (argv!!0) == "-help")
        then putStrLn "USAGE: ./imageCompressor -n N -l L -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconvergence limit\n\tF\tpath to the file containing the colors of the pixels" >>
        exitSuccess 
    else if end /= 6
        then failure "USAGE: ./imageCompressor -n N -l L -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconvergence limit\n\tF\tpath to the file containing the colors of the pixels"
    else checkArgs end 0 argv
    args <- getArguments end argv
    case args of
        Right   option -> do
                c <- readFile (pathImage option)
                printCluster (imgCompressor (parseFile c, colorsNb option, convergLimit option) [])
        Left    invalid -> exitWith $ ExitFailure 84