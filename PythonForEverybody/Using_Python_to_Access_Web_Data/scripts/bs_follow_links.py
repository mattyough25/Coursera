# To run this, download the BeautifulSoup zip file
# http://www.py4e.com/code3/bs4.zip
# and unzip it in the same directory as this file

import urllib.request, urllib.parse, urllib.error
import re
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter URL: ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')

count = input('Enter Count: ')
count = int(count)
pos = input('Enter Position: ')
pos = int(pos)

# Retrieve all of the anchor tags
tags = soup('a')
restart = True

ix3 = 0
while restart:
    ix = 0
    ix3 = ix3 + 1
    if ix3 == count + 1:
        break
    restart = False
    for tag in tags:
        ix = ix + 1
        if ix == pos:
            url2 = tag.get('href', None)
            name = re.findall('by_([^ ]*)\.', url2)
            print(name)
            html2 = urllib.request.urlopen(url2, context=ctx).read()
            soup2 = BeautifulSoup(html2, 'html.parser')
            tags = soup2('a')
            ix = 0
            restart = True
            break
    
