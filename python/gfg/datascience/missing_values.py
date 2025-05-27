
import pandas as pd
import numpy as np
from sklearn.impute import KNNImputer


from sklearn.impute import SimpleImputer


#data analysis
print("-"*30 + "data analysis" + "-"*30)
df = pd.read_csv("C:\\dev\\git\\worldrunsoncode\\python\\data\\google_playstore.csv")
print(df.head())

print(df["Rating"])

#unique 
#print(df['Category'].unique())
#print(df['Category'].nunique())

print("-"*30 + "check null data and drop na" + "-"*30)
print(df.isnull().sum())
df_deleted = df.dropna()
print(df_deleted.isnull().sum())
#print(df.isna())

df.isnull()
#SimpleImputer
# Impute missing values with mean
print(df.isnull().sum())
df['Rating'].fillna(df['Rating'].mean(), inplace=True)

# Impute missing values with median
df['Rating'].fillna(df['Rating'].median(), inplace=True)
print(df.isnull().sum())

#K-nearest neighbours
imputer = KNNImputer(n_neighbors=5)
#data_imputed = imputer.fit_transform(df)
#print(data_imputed.isnull().sum())


#duplicate data
duplicates = df[df.duplicated()]
print(duplicates)
data_cleaned = df.drop_duplicates()
data_cleaned = df.drop_duplicates(keep='first')
data_cleaned = data_cleaned.reset_index(drop=True)


