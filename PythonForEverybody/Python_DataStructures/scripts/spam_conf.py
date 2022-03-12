# -*- coding: utf-8 -*-
"""
Created on Fri Mar 11 20:12:06 2022

@author: mgy0003
"""

# Use the file name mbox-short.txt as the file name
fname = input("Enter file name: ")

try:
    fh = open(fname)
except:
    print('File cannot be opened:',fname)
    quit()

ix = 0
tot = 0
for line in fh:
    if not line.startswith("X-DSPAM-Confidence:"):
        continue
    sp_conf_str = line[20:]
    sp_conf_flt = float(sp_conf_str)
    ix = ix + 1
    tot = tot + sp_conf_flt
    
print("Average spam confidence:", tot/ix)