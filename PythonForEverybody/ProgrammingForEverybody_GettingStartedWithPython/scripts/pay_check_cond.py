# -*- coding: utf-8 -*-
"""
Created on Wed Mar  2 18:13:51 2022

@author: mgy0003
"""

# This code prints out a pay check
hour = input('Enter hours worked:')
rate = input('Enter pay per hour:')

try:
    hour = float(hour)
    rate = float(rate)
    flag = 1;
except:
    flag = -1;
    
if flag > 0:
    if hour <= 40:
        gPay = hour * rate
    else:
        rPay = 40 * rate
        xHours = hour - 40
        oPay = xHours * (rate*1.5)
        gPay = rPay + oPay
    print(gPay)
elif flag < 0:
    print('Not valid input')
        