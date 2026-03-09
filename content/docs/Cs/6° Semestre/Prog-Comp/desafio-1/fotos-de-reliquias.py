def count_photos():
    N = int(input())
    if N == 0:
        print(0)
        return

    A = list(map(int, input().strip().split()))[:N]
    
    total_count = 0 

    for i in range(0, N):
        if A[i] == 1:
            left_count = 1
            for j in range(i - 1, -1, -1):
                if A[j] == 1:
                    break 
                left_count += 1

            right_count = 1
            for j in range(i + 1, N):
                if A[j] == 1:
                    break
                right_count += 1

            total_count += (left_count * right_count)

    return total_count

if __name__ == "__main__":
    result = count_photos()
    print(result)
