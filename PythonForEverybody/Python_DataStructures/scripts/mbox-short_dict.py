# -*- coding: utf-8 -*-
"""
Created on Sun Mar 13 12:34:14 2022

@author: mgy0003
"""

#This script counts the number of emails sent in mbox-short.txt
name = input("Enter file:")
if len(name) < 1:
    name = "mbox-short.txt"
    
try:
    handle = open(name)
except:
    print('File cannot be opened:',name)
    quit()
    
num = 0
counts = dict()
for line in handle:
    line = line.rstrip()
    if not line.startswith('From '):
        continue
    num = num + 1
    words = line.split()
    adrs = words[1]
    counts[adrs] = counts.get(adrs,0) + 1
    
bigcount = None
bigword = None
for word,count in counts.items():
    if bigcount is None or count > bigcount:
        bigword = word
        bigcount = count
        
print(bigword,bigcount)