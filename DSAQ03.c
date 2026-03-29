def linear_search(arr, n, k):
    comparisons = 0
        
    for i in range(n):
        comparisons += 1
        if arr[i] == k:
            print(f"Found at index {i}")
            print(f"Comparisons = {comparisons}")
            return
    
    print("Not Found")
    
        print(f"Comparisons = {comparisons}")

# Input
n = int(input())
arr = list(map(int, input().split()))
k = int(input())

# Function call
linear_search(arr, n, k)
