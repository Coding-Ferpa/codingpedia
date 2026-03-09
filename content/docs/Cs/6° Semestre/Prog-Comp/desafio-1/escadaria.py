def main():
    N = int(input())
    if N == 0:
        print(0)
        return

    A = list(map(int, input().strip().split()))
    B = A
    
    for i in range(N):
        if B[i] == -1:
            B[i] = 1000001

    for i in range(1, N):
        B[i] = min(B[i], B[i-1] + 1)

    for i in range(N - 2, -1, -1):
        B[i] = min(B[i], B[i+1] + 1)

    print(*(B))

if __name__ == "__main__":
    main()
