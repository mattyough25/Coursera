# -*- coding: utf-8 -*-
"""
Created on Thu Mar 10 22:06:40 2022

@author: mgy0003
"""

# This script loops through a series
# of user input numbers

largest = None
smallest = None
while True:
    num = input("Enter a number: ")
    
    if num == "done":
        break
    
    try:
        num = int(num)
    except:
        print("Invalid input")
        continue
    
    if smallest is None and largest is None:
        smallest = num
        largest = num
    elif num > largest:
        smallest = smallest
        largest = num
    elif num < smallest:
        smallest = num
        largest = largest

print("Maximum is", largest)
print("Minimum is", smallest)