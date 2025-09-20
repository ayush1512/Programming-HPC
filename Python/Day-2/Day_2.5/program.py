str="Malkeet"       #Array of chracters

for x in str:
    print(x)
count=0
for x in str:
    if(x=='e'):
        count=count+1

print(count)

#Accessing String in different ways
print(str[0])
print(str[0:3])     #3rd index is excluded
print(str[1:3])
print(str[-1])
