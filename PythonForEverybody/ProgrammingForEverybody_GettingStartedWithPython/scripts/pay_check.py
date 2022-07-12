# -*- coding: utf-8 -*-
"""
Created on Wed Mar  2 11:26:26 2022

@author: mgy0003
"""
# This script calculates a workers pay

hrs  = input("Enter Hours:")
rate = input("Enter Rate:")

hrs  = float(hrs)
rate = float(rate)

gPay = hrs * rate
print('Pay:',gPay)