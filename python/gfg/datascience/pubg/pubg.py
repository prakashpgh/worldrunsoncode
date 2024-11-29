#importing
import numpy as np
import pandas as pd

import matplotlib.pylab as plt
#%matplotlib inline
plt.rcParams["figure.figsize"] = (16,6)


import seaborn as sn

import warnings
warnings.filterwarnings("ignore")

from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

import catboost as cb
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score
print("hello")

#reading
#
df = pd.read_csv("C:\dev\git\worldrunsoncode\python\data\PUBG_Game_Prediction_data.csv")
print("data read")
print(df.head())
print(df.info())

print(df.shape)

#data wrangling
#winPlacePerc
print(df[df['winPlacePerc'].isna()])
df.drop(2744604, inplace=True)

print('after dropping')
df = pd.read_csv("C:\dev\git\worldrunsoncode\python\data\PUBG_Game_Prediction_data.csv")
print(df[df['winPlacePerc'].isna()])