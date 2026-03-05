# real time Data warehouse 

import random
import time
from datetime import datetime

print("=== Data Warehousing Process Started ===")

warehouse = []

regions = ['East', 'West', 'South', 'North']

for i in range(15):
  
  new_data = {
    'region': random.choice(regions),
    'amount': random.randint(100, 1000),
    'time': datetime.now().strftime("%H:%M:%S")
  }
  
  warehouse.append(new_data)
  
  print("New data added -> ", new_data)
  
  total_sales = {}
  
  for record in warehouse:
    
    region = record["region"]
    
    if region in total_sales:
      total_sales[region] += record["amount"]
    else:
      total_sales[region] = record["amount"]
      
  print("Updated total sales by region")
  
  for r, amt in total_sales.items():
    print(f"{r} : {amt}")
    
  print('-' * 50)
  
  time.sleep(1)
  
print("=== Data Warehousing Process Ended ===")