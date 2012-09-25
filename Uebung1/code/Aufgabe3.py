import sys
import re
    
data = sys.argv[1]

if re.search("^[01][01][01][01]$", data) == None:
    print ("FALSCHE -EINGABE.")
else:
    
    d3 = int(data[0])
    d5 = int(data[1])
    d6 = int(data[2])
    d7 = int(data[3])
    
    p1 = (d3 + d5 + d7) % 2
    p2 = (d3 + d6 + d7) % 2
    p4 = (d5 + d6 + d7) % 2
    
    print(str(p1) + "-" + str(p2) + "-" + str(d3) + "-" 
          + str(p4) + "-" + str(d5) + str(d6) + str(d7))
    