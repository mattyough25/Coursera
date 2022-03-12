# -*- coding: utf-8 -*-
"""
Created on Fri Mar 11 20:03:41 2022

@author: mgy0003
"""

# This file reads a file given by the user
# Use words.txt as the file name

fname = input("Enter file name: ")

try:
    fh = open(fname)
except:
    print('File cannot be opened:',fname)
    quit()
    
for line in fh:
    line = line.rstrip()
    line = line.upper()
    print(line)
