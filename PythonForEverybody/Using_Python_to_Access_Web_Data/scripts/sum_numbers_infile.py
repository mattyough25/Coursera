# -*- coding: utf-8 -*-
"""
Created on Mon Mar 14 20:23:24 2022

@author: mgy0003
"""

#This code finds all the numbers in a text file
#and sums them

import re

name = input("Enter file:")
if len(name) < 1:
    name = "actual_sum_numbers.txt"
    
try:
    handle = open(name)
except:
    print('File cannot be opened:',name)
    quit()
    
num_lst = list()
for line in handle:
    if re.search('[0-9]+',line):
        sNumber = re.findall('[0-9]+',line)
        for num in sNumber:
            nNumber = int(num)
            num_lst.append(nNumber)
            
num_sum = sum(num_lst)
print(num_sum)
            