import pandas as pd
import numpy as py
print("hello")

patients = pd.read_csv("C:\dev\code\datascience\patients.csv")
treatments = pd.read_csv("C:\dev\code\datascience/treatments.csv")

treatments_cuts = pd.read_csv("C:\dev\code\datascience/treatments_cut.csv")
adverse_reactions = pd.read_csv("C:\dev\code\datascience/adverse_reactions.csv")

print(patients.head())
print(treatments.head())
print(adverse_reactions.head())
print(treatments_cuts.head())

print(patients.describe()) 
            
                        
                        

#ASSESSMENT
#export to excel
#with pd.ExcelWriter("C:\dev\code\datascience/clinical_trial.xslx") as writer:
#    patients.to_excel(writer, sheet_name="patients")
##    treatments.to_excel(writer, sheet_name="treatments")
#    treatments_cuts.to_excel(writer, sheet_name="treatments_cut")
#    adverse_reactions.to_excel(writer, sheet_name="adverse_reactions")

#automatic assessment
patients.info()

#patients[patients["address"]].isnull

print(patients[patients.duplicated(subset=['given_name','surname'])])


print(patients.describe())
print(patients.isnull().sum())

patients_df = patients.copy()
print(patients_df)

treatments_df = treatments_cuts.copy()
print(treatments.info())



