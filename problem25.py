#!/usr/bin/env python
import math

def Phi():
	return (math.sqrt(5.0) + 1.0) / 2.0;

def fib(n):
	num = 0
	try:
		num = math.pow(Phi(), n) - (math.pow(-1.0, n)/math.pow(Phi(), n))
	except OverflowError:
		print("with n:%s pow failed" % (str(n)))
	
	denom = math.sqrt(5.0)
	return int(num/denom)

def numDigits(n):
	return len(str(n))

def endDig(stop):
	print("{")
	currDig = 0
	count = 1
	while currDig != stop:
		currF = fib(count)
		currDig = numDigits(currF)
		print "%s: %s: %s" % (str(count), str(currF), str(currDig))
		count += 1
	print("}\n");

if __name__ == "__main__":
	endDig(1000)	
