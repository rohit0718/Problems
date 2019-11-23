def max_profit(arr):
  if len(arr) == 0:
    return
  profit, curr = 0, 0
  low = arr[0]
  for item in arr:
    if item <= low:
      profit += curr
      curr = 0
      low = item
    else:
      curr = max(curr, item - low)
  return profit + curr

def main():
  stock_data = [3,4,9,2,1,10,1,3]
  print(max_profit(stock_data))

if __name__ == "__main__":
  main()
