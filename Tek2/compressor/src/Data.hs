module Data
    (
        Pixel(..),
        Cluster(..),
        Clustering(..),
        Options(..),
        ArgumentType(..)
    ) where

data Cluster = Cluster
    { pos :: [Float]
    } deriving (Eq, Show)

data Clustering = Clustering
    { cluster :: Cluster
    , pixels :: [Pixel]
    } deriving (Eq, Show)

data Pixel = Pixel
    { color    :: [Int]
    , position :: [Int]
    } deriving(Eq, Ord,Show)

data Options = Options
    { colorsNb     :: Int
    , convergLimit :: Float
    , pathImage    :: String
    } deriving Show

data ArgumentType =     Invalid
                    |   Version
                    |   Helper
                    |   Other
    deriving (Show, Enum)