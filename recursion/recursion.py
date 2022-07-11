def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n*factorial(n-1)
    
def reverseString(str):
    if(len(str)!=0):
        reverseString(str[:-1])
        print(str[-1])
        

# v(i, j) = v(i - 1, j - 1) + v(i - 1, j) 
def pascal(i, j):
    if(j==1 or i==j):
        return 1
    else:
        return pascal(i-1,j-1) + pascal(i-1,j)

    
if __name__ == "__main__":
    print(factorial(4))
