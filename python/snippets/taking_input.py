import sys
from datetime import date
from dateutil import parser

city_temps_map = {}
max_city = ""
max_avg = float('-inf')
for line in sys.stdin:
    #print(line.strip())
    line = line.strip()
    #print(line)
    tokens = line.split(",")
    if len(tokens) < 3:
        continue
    city = tokens[0]
    dt = parser.parse(tokens[1])
    if not (dt.month ==4 and dt.year == 2018):
        continue
    temp = float('-inf')
    #print("city: " + city)
    #print("date: " + str(dt) )
    try:
        temp = float(tokens[2])
    except ValueError as ve:
        print("ve: " + str(ve))
        continue
    #print("city: " + city )
    #print("date: " + date )
    #print("ctemp: " + temp )
    if city in city_temps_map:
        city_temps_map[city] = (city_temps_map[city][0] + temp, city_temps_map[city][1] + 1)
    else:
        city_temps_map[city] = (temp, 1)
    #print("city_temps_map: " + str(city_temps_map))

    for k,v in city_temps_map.items():
        avg = v[0]/v[1]
        if max_avg < avg:
            max_avg = avg
            max_city = k
    
print(max_city)
        
