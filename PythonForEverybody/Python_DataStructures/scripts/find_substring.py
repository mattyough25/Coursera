# -*- coding: utf-8 -*-
"""
Created on Fri Mar 11 16:45:56 2022

@author: mgy0003
"""

# This code finds substring and prints it out
text = "X-DSPAM-Confidence:    0.8475"

ix = text.find('0')
num_str = text[ix:]
num_flt = float(num_str)
print(num_flt)