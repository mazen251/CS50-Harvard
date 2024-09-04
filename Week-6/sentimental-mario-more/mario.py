from cs50 import get_int
while(True):
    height = get_int("Height: ")
    if (height > 0 and height <= 8):
        break

n1 = height - 1
n2 = 2
for i in range(height):
    print(" " * n1, end = "")
    for j in range(n2):
        if(j  == (n2 / 2)):
            print("  ", end = "")
            print("#", end = "")
        else:
            print("#", end = "")
    n1 -= 1
    n2 += 2
    print()


