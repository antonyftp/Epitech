module Cluster
    (
        mean,
        distance,
        distanceF,
        eqCluster,
        newCluster,
        chunks,
        applyKmean,
        linkKneighbor,
        createClustering,
        findPixel,
        minimalDist
    ) where

import Data

import Data.List

mean :: [Pixel] -> Cluster
mean pixel = Cluster { pos = [ sum r / y',  sum g / y',  sum b / y'] }
        where
            r = [fromIntegral (color (pixel !! i) !! 0) | i <- take y [0,1..]]
            g = [fromIntegral (color (pixel !! i) !! 1) | i <- take y [0,1..]]
            b = [fromIntegral (color (pixel !! i) !! 2) | i <- take y [0,1..]]
            y = length pixel
            y' = fromIntegral (y)

distance :: [Int] -> [Float] -> Float
distance x y = sqrt (x'*x' + y'*y' + z'*z')
    where
        x' = fromIntegral (x !! 0) - y !! 0
        y' = fromIntegral (x !! 1) - y !! 1
        z' = fromIntegral (x !! 2) - y !! 2

distanceF :: [Float] -> [Float] -> Float
distanceF x y = sqrt (x'*x' + y'*y' + z'*z')
    where
        x' = x !! 0 - y !! 0
        y' = x !! 1 - y !! 1
        z' = x !! 2 - y !! 2

eqCluster :: Cluster -> Cluster -> Float -> Bool
eqCluster clusterA clusterB e
        | x > e     = False
        | otherwise = True
            where
                a = pos clusterA
                b = pos clusterB
                x = distanceF a b

newCluster :: [Pixel] -> Int -> [Cluster]
newCluster img n = [mean (y !! i) | i <- take n [0,1..]]
    where
        y = chunks (length img `div` n) img
        
chunks :: Int -> [a] -> [[a]]
chunks _ [] = []
chunks n xs =
    let (ys, zs) = splitAt n xs
    in  ys : chunks n zs

applyKmean :: [Pixel] -> [Cluster] -> [Clustering]
applyKmean a b =  linkKneighbor a b

linkKneighbor :: [Pixel] -> [Cluster] -> [Clustering]
linkKneighbor img clusterList = [createClustering img clusterList i | i <- take (length clusterList) [0,1..]]

createClustering :: [Pixel] -> [Cluster] -> Int -> Clustering
createClustering img list x = Clustering { cluster = if length choosenPixel > 0 then mean choosenPixel else list !! x, pixels = choosenPixel}
            where choosenPixel = findPixel img list x

findPixel :: [Pixel] -> [Cluster] -> Int -> [Pixel]
findPixel img list counter = [img !! i | i <- take (length img) [0,1..], minimalDist (img !! i) list == counter]

minimalDist :: Pixel -> [Cluster] -> Int
minimalDist pix list = findMinimum [distance (color pix) (pos (list !! i)) | i <-  take (length list) [0,1..]]

findMinimum :: [Float] -> Int
findMinimum x = n
        where
            n = case elemIndex y x of
                Nothing -> -1
                Just n  -> n
            y = minimum x