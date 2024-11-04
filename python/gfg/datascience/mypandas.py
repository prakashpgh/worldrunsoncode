#panda => Serires from array, list
#panda => DataFrame

import pandas as pd
import numpy as np


print("-"*30 + "Panda Series" + "-"*30)
# simple array
data = np.array(['g', 'e', 'e', 'k', 's'])

ser = pd.Series(data)
print(ser)

#read_csv





data = pd.Series(['a', 'b', 'c', 'd'])
print(data)

##DataFrame
# list of strings
print("-"*30 + "DataFrame" + "-"*30)
lst = ['Geeks', 'For', 'Geeks', 'is',
       'portal', 'for', 'Geeks']

# Calling DataFrame constructor on list
df = pd.DataFrame(lst)
print(df)

#DF from dictionary of lists
# intialise data of lists.
print("-"*30 + "Panda DF from dictionary" + "-"*30)
data = {'Name': ['Tom', 'nick', 'krish', 'jack'],
        'Age': [20, 21, 19, 18]}

# Create DataFrame
df = pd.DataFrame(data)

# Print the output.
print(df)

# reading csv file
print("-"*30 + "Reading csv" + "-"*30)
df = pd.read_csv("C:\\dev\\git\\worldrunsoncode\\python\\data\\customers1000.csv")
print(df.isnull().sum())
print (df)
print (df["Customer Id"])
print(df.columns)

#df = df.drop(["Index", "Customer Id","Email"], axis = 1)#
print(df)
print(df.columns)

#check nulls
print("-"*30 + "Null checks" + "-"*30)
print(df.isnull().sum())
df = df.dropna()
print(df.isnull().sum())


#data analysis
print("-"*30 + "data analysis" + "-"*30)
df = pd.read_csv("C:\\dev\\git\\worldrunsoncode\\python\\data\\google_playstore.csv")
print(df.head())

print(df["Rating"])

#unique 
print(df['Category'].unique())
print(df['Category'].nunique())

print(df.isnull().sum())
#print(df.isna())

#SimpleImputer
import numpy as np
from sklearn.impute import SimpleImputer
imputer = SimpleImputer(missing_values = np.nan, strategy = 'most_frequent')
df.iloc[:,1:13]=imputer.fit_transform(df.iloc[:,1:13].values)
print(df.isnull().sum())
#print(df.columns())

df.describe()

