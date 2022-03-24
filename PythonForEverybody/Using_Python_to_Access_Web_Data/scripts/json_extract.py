import json
import urllib.request, urllib.parse, urllib.error

url = input('Enter URL: ')
uh = urllib.request.urlopen(url)
data = uh.read().decode()

try:
    info = json.loads(data)
    print('User count:', len(info))
except:
    print('=== Failure To Retrieve ===')

ix = 0
sum = 0
for item in info['comments']:
    try:
        print('Name', info['comments'][ix]['name'])
        print('Count', info['comments'][ix]['count'])
        count = info['comments'][ix]['count']
        ix = ix + 1
        sum = sum + count
    except:
        continue
    
print('===================')
print('Total Comments:', sum)
