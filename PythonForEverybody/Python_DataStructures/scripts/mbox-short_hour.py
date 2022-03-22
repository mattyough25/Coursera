# -*- coding: utf-8 -*-
"""
Created on Sun Mar 13 17:39:47 2022

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
    time = words[5]
    time_split = time.split(':')
    hrs = time_split[0]
    
    counts[hrs] = counts.get(hrs,0) + 1
    
sorted_tup = sorted([(k,v) for k,v in counts.items()])

for k, v in sorted_tup:
    print(k,v)
    
