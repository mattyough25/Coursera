# -*- coding: utf-8 -*-
"""
Created on Sat Mar 12 14:56:48 2022

@author: mgy0003
"""

#This code sorts through words in a file

fname = input("Enter file name: ")

try:
    fh = open(fname)
except:
    print('File cannot be opened:',fname)
    quit()
    
num = 0
for line in fh:
    line = line.rstrip()
    if not line.startswith('From '):
        continue
    num = num + 1
    words = line.split()
    print(words[1])
print('There were', num, 'lines in the file with From as the first word')