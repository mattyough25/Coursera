# -*- coding: utf-8 -*-
"""
Created on Wed Mar  2 20:36:06 2022

@author: mgy0003
"""

# This code prints out a pay check 
# using a function

def computepay(hour, rate):
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
        return(gPay)
    elif flag < 0:
        return('Not valid input')
    
hour = input('Enter hours worked:')
rate = input('Enter pay per hour:')

pay = computepay(hour, rate)
print('Pay', pay)    