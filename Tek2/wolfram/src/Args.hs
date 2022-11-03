module Args 
    (
        loopCheckSame,
        otherErrors,
        getOther,
        loopCheckArgs,
        checkArgs,
        move,
        noMove,
        checkNumber,
    ) where

import Rules
import Utils

loopCheckSame :: String -> Int -> Int -> Int -> [String] -> IO()
loopCheckSame search count end i args | i == (end+1) = return()
loopCheckSame search count end i args | count == 2 =
    failure ("The argument \"" ++ search ++ "\" is present more than one time")
loopCheckSame search count end i args | i < end && (args!!i) == search =
    loopCheckSame search (count+1) end (i+1) args
loopCheckSame search count end i arg = loopCheckSame search count end (i+1) arg

otherErrors :: Int -> String -> IO()
otherErrors 66766985 searched  =
    failure ("It isn't any value after \"--" ++ searched ++ "\" !")
otherErrors value searchedelse = putStr ""

getOther :: String -> Int -> Int -> Int -> [String] -> Int
getOther search def end i args | i == end = def
getOther search def end i args | (args!!i) == search && i == (end-1) = 66766985
getOther search def end i args | (args!!i) /= search && i == (end-1) = def
getOther search def end i args | (args!!i) == search = read(args!!(i+1))
getOther search def end i args = getOther search def end (i+1) args

loopCheckArgs :: Int -> Int -> [String] -> IO()
loopCheckArgs end i args | i == end = return()
loopCheckArgs end i args | isPair i = checkRule (args!!i) i
loopCheckArgs end i args = checkNumber (args!!(i-1)) (args!!i) i

checkArgs :: Int -> Int -> [String] -> IO()
checkArgs end i args =
    loopCheckArgs end i args >>
    loopCheckSame "--rule" 0 end i args >>
    loopCheckSame "--start" 0 end i args >>
    loopCheckSame "--lines" 0 end i args >>
    loopCheckSame "--window" 0 end i args >>
    loopCheckSame "--move" 0 end i args

move :: String -> Int -> IO()
move str n | isNb(removeMoins str) = return()
move str n =
 failure ("The arg " ++ show n ++ "-->\"" ++ str ++ "\" isn't a valid value !")

noMove :: String -> Int -> IO()
noMove str n | isNb str = return()
noMove str n =
 failure ("The arg " ++ show n ++ "-->\"" ++ str ++ "\" isn't a valid value !")

checkNumber :: String -> String -> Int -> IO()
checkNumber "--move" str n | head str == '-' = move str n
checkNumber prec str n = noMove str n