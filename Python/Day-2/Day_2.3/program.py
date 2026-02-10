import sys
import math

#User Input
#Num1=input("Enter a Number"), here the input will treated as string
Num1=int(input("Enter a Number: "))
print(math.sqrt(Num1))


#Command Line Argument
#sys.argv[0]= Script Name
Num2=sys.argv[1:]
print("The Commmand Line Args is: ", Num2)