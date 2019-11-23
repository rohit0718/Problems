def main():
    while (True):
        n = int(input())
        if (n == 0):
            break
        n = n - 1
        ptr = 0
        start = False
        print("{ ", end = "")
        while (n > 0):
            if (n % 2 != 0):
                if start == True:
                    print(",", 3**ptr, end = "")
                else:
                    print(3**ptr, end = "")
                    start = True
            n = n // 2
            ptr = ptr + 1
        if start == True:
            print(" }")
        else:
            print("}")


if __name__ == "__main__":
    main()


    
