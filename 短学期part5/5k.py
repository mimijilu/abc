import math
a=0
while True: 
    try:
        s = raw_input() 
        b=int(s)
        c=math.sqrt(b)
        print int(c)
    except:
        break