def oddEvenSort(arr):
    n = len(arr)
    isSorted = 0
    
    while isSorted == 0:
        isSorted = 1
        for i in range(1, n-1, 2):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                isSorted = 0
        for i in range(0, n-1, 2):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                isSorted = 0

def printArray(arr):
    for num in arr:
        print(num, end=" ")
    print()

def main():
    with open("input.txt", "r") as file:
        numTestCases = int(file.readline())
        for _ in range(numTestCases):
            n = int(file.readline())
            arr = list(map(int, file.readline().split()))
            oddEvenSort(arr)
            printArray(arr)

if __name__ == "__main__":
    main()
