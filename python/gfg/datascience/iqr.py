import numpy as np

# Generate example data
data = np.array([23, 25, 22, 27, 21, 24, 26, 100, 23, 28, 22, 29])

# Calculate first and third quartiles
q1 = np.percentile(data, 25)
q3 = np.percentile(data, 75)

# Calculate the IQR
iqr = q3 - q1

# Set IQR multiplier
iqr_multiplier = 1.5

# Define lower and upper bounds
lower_bound = q1 - iqr_multiplier * iqr
upper_bound = q3 + iqr_multiplier * iqr

# Identify outliers
outliers = [x for x in data if x < lower_bound or x > upper_bound]

print("Original Data:", data)
print("Outliers detected using IQR:", outliers)