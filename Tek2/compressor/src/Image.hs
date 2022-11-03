module Image
    ( 
        startOption,
        programUsage,
        programInvalidArgs,
        imgCompressor,
        getConvergeance,
        parseFile,
        removeEmptyLine,
        containEmptyLine,
        lineToPixel,
        getPosition,
        getColor,
        replaceComma,
        getArguments,
    ) where

-- My Files

import Data
import Check
import Utils
import Args
import Cluster

-- System Files

import Data.List

getArguments :: Int -> [String] -> IO (Either ArgumentType Options)
getArguments end args = do
    let n = getItInt "-n" end 0 args
    let l = getItFloat "-l" end 0 args
    let f = getPath "-f" end 0 args
    checkFile f
    return $ Right Options { colorsNb = n, convergLimit = l, pathImage = f }

startOption :: Options
startOption = Options
    { colorsNb          = 0
    , convergLimit  = 0
    , pathImage         = ""
    }

programUsage :: IO ()
programUsage = putStrLn "USAGE: ./imageCompressor -n N -l L -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconvergence limit\n\tF\tpath to the file containing the colors of the pixels"

programInvalidArgs :: IO ()
programInvalidArgs = do putStrLn "the given arguments are invalid, please use the --help option"

imgCompressor :: ([Pixel], Int, Float) -> [Clustering] -> [Clustering]
imgCompressor (img, n, e) [] =  imgCompressor (img, n', e) (applyKmean img (newCluster img n'))
            where
                n' = if n > x then x else n
                x = length img
imgCompressor (img, n, e) clustering
        | getConvergeance clustering newClustering e == False = imgCompressor (img, n, e) newClustering
        | otherwise = newClustering
            where
                newClustering = applyKmean img newCluster
                newCluster = [cluster (clustering !! i) | i <- take n [0,1..]]

getConvergeance :: [Clustering] -> [Clustering] -> Float -> Bool
getConvergeance old new e
        | length x == length old    = True
        | otherwise                 = False
            where
                x = [function i | i <- take (length old) [0,1..] , function i == True]
                function i = eqCluster (cluster (old !! i)) (cluster (new !! i)) e

parseFile :: String -> [Pixel]
parseFile s = map lineToPixel (removeEmptyLine (lines s))

removeEmptyLine :: [String] -> [String]
removeEmptyLine arr
        | containEmptyLine arr  = delete "" arr
        | otherwise             = arr

containEmptyLine :: [String] -> Bool
containEmptyLine []     = False
containEmptyLine (x:xs)
        | null x        = True
        | otherwise     = containEmptyLine xs

lineToPixel :: String -> Pixel
lineToPixel l = Pixel { position = (getPosition (word1Position, word2Position)), color = (getColor (word1Color, word2Color, word3Color)) }
        where   positionOnly    = (((words l) !! 0) \\ "()")
                colorOnly       = (((words l) !! 1) \\ "()")
                word1Position   = (words (map replaceComma positionOnly)) !! 0
                word2Position   = (words (map replaceComma positionOnly)) !! 1
                word1Color      = (words (map replaceComma colorOnly)) !! 0
                word2Color      = (words (map replaceComma colorOnly)) !! 1
                word3Color      = (words (map replaceComma colorOnly)) !! 2

getPosition :: ([Char], [Char]) -> [Int]
getPosition a = [(read (fst a) :: Int), (read (snd a) :: Int)]

getColor :: ([Char], [Char], [Char]) -> [Int]
getColor (a,b,c) = [(read a :: Int), (read b :: Int), (read c :: Int)]

replaceComma :: Char -> Char
replaceComma ','        = ' '
replaceComma c          = c
