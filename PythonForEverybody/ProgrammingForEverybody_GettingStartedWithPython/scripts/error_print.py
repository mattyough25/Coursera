# -*- coding: utf-8 -*-
"""
Created on Wed Mar  2 18:25:52 2022

@author: mgy0003
"""

# This script prints error if input
# is not between 0 and 1.0

score = input('Enter a score between 0 and 1.0:')

try:
    score = float(score)
except:
    print('Error, input must be a number')

if score > 1:
    print('Error, Input must be between 0 and 1')
elif score < 0:
    print('Error, Input must be between 0 and 1')
elif score >= 0.9:
    print('A')
elif score >= 0.8:
    print('B')
elif score >= 0.7:
    print('C')
elif score >= 0.6:
    print('D')
elif score < 0.6:
    print('F')