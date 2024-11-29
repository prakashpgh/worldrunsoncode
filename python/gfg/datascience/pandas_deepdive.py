import pandas as pd
import matplotlib.pyplot as plt
#apache arrow

#from json
df = pd.DataFrame( {  "Name": ["aa", "bb"],   "Age":[1,2]   })
print(df)
print(type(df))

#pandas series is a column.  each column of DF is called series

#Series is a one-dimensional labeled array capable of holding any data type

#read functions
df = pd.read_csv("C:\dev\git\worldrunsoncode\python\data\\titanic_data.csv")

#head
print(df.head())
#tail

#describe

#agg
    #

#shape

#info

#dtypes

#slicing
#subseting
print(df["Age"] > 35)
print(df[df["Age"] > 35])

#nonna() => exclude na

#loc[condition,  columns]  column and row based sub setting
print(df.loc[df["Age"] > 35, ["Name", "Age"]])

#iloc
#row and column indexes

df = pd.read_csv("C:\dev\git\worldrunsoncode\python\data\AirQuality.csv")
#https://www.kaggle.com/datasets/sagargupta323/airquality
print(df.head())
print(df.info())
#df.plot.box()


#groupby
#groupby - select - apply aggregation

#value_counts

#joining 2 df
#pd.merge