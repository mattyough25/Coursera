# %% Calculate Total Savings

# Define Variables
C = 100000
r = .07

# Calculate Payments
# Total Saved = C/r
PV = C/r

print('Total Savings Needed: ', PV)

# %% Calculate Monthly Savings

# Define Variables
n = 30

# Calculate Payments
ACF = (((1+r)**n)-1)/r
P = PV/ACF
print('Yearly Savings: ', P)
print('Monthly Savings: ', P/12)
