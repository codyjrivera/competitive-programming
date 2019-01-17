from functools import reduce

def primes(x):
    return list(filter(None,map(lambda y:y*reduce(lambda x,y:x*y!=0,map(lambda x,y=y:y%x,range(2,int(pow(y,0.5)+1))),1),range(2,x))))

inputf = int(input())

count = 0
diff = inputf
while(diff > 2):
    count += 1
    primelist = primes(diff)
    diff = primelist[len(primelist) -1] - primelist[count]


print(count)
