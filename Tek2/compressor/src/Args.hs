module Args
    (
        loopCheckSame,
        checkRule,
        check,
        loopCheckArgs,
        checkArgs
    ) where

import Utils
import Check

loopCheckSame :: String -> Int -> Int -> Int -> [String] -> IO()
loopCheckSame search count end i args | i == (end+1) = return()
loopCheckSame search count end i args | count == 2 =
    failure ("The argument \"" ++ search ++ "\" is present more than one time")
loopCheckSame search count end i args | i < end && (args!!i) == search =
    loopCheckSame search (count+1) end (i+1) args
loopCheckSame search count end i arg = loopCheckSame search count end (i+1) arg

checkRule :: String -> Int -> IO()
checkRule str n | str /= "-n" && str /= "-l" && str /= "-f" = failure
    ("The argument " ++ show (n+1) ++ " --> \"" ++ str ++ "\" isn't a valid instruction")
checkRule str n = return()

check :: Int -> Int -> [String] -> IO()
check end i args | isPair i = checkRule (args!!i) i
check end i args | (args!!(i-1)) /= "-f" && (isNb (args!!i)) =
    failure ("The argument " ++ show (i+1) ++ " --> \"" ++ (args!!i) ++ "\" must be a number")
check end i args = return()

loopCheckArgs :: Int -> Int -> [String] -> IO()
loopCheckArgs end i args | i == end = return()
loopCheckArgs end i args = check end i args >>
    loopCheckArgs end (i+1) args

checkArgs :: Int -> Int -> [String] -> IO()
checkArgs end i args =
    loopCheckArgs end i args >>
    loopCheckSame "-n" 0 end i args >>
    loopCheckSame "-l" 0 end i args >>
    loopCheckSame "-f" 0 end i args