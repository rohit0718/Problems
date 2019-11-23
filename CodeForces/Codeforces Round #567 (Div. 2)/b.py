def solve_left(s, l):
    x = s[0:(l+1)//2]
    y = s[(l+1)//2:l]
    if (l % 2 == 0 and not y.startswith('0')):
        return int(x) + int(y)
    elif (l % 2 != 0):
        x1 = s[0:l//2]
        y1 = s[l//2:l]
        if not y1.startswith('0') and not y.startswith('0'):
            return min(int(x) + int(y), int(x1)+ int(y1))
        elif y1.startswith('0'):
            return int(x) + int(y)
        elif y.startswith('0'):
            return int(x1) + int(y1)
        else:
            ptr = 1
            while not y.startswith('0'):
                x = s[0:(l+1)//2]
                y = s[(l+1)//2:l]



def solve_right():
    x = s[0:(l+1)//2]
    y = s[(l+1)//2:l]
    if (l % 2 == 0 and not y.startswith('0')):
        return int(x) + int(y)
    elif (l % 2 != 0):
        x1 = s[0:l//2]
        y1 = s[l//2:l]
        if not y1.startswith('0') and not y.startswith('0'):
            return min(int(x) + int(y), int(x1)+ int(y1))
        elif y1.startswith('0'):
            return int(x) + int(y)
        elif y.startswith('0'):
            return int(x1) + int(y1)
        else:
            ptr = 1
            while not y.startswith('0'):
                x = s[0:(l+1)//2]
                y = s[(l+1)//2:l]




def main():
    l = int(input())
    s = input()

    print(solve_left(s, l))



if __name__ == "__main__":
    main()
