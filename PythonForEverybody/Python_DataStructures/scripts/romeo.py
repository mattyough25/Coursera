# -*- coding: utf-8 -*-
"""
Created on Sat Mar 12 12:50:52 2022

@author: mgy0003
"""
#This code sorts through words in a file
#and puts unique words in a list

fname = input("Enter file name: ")

try:
    fh = open(fname)
except:
    print('File cannot be opened:',fname)
    quit()
    
lst = list() 
for line in fh:
    line.rstrip()
    for words in line.split():
        if words not in lst:
            lst.append(words)
            
lst.sort()
print(lst)
