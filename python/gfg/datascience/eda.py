
import pandas as pd
import seaborn as sns

df = pd.read_csv("C:\dev\git\worldrunsoncode\python\data\imdb.csv");

#dimensions of data
print("shape: " + str(df.shape))

#head
print(df.head())
print(df.tail())

print(df.sample(10))

#data type of columns

df.info()

#missing values
print(df.isna().sum())


#mathematically - statistics
print(df.describe())

#duplicate values
print(df.duplicated().sum())

#unique values
print(print(df.nunique()))

#outliers => box plot





