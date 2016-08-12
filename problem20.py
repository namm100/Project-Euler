#!/usr/bin/env python

'''
find the sum of the digits 
in the number 100!
'''

def fac(n):
	if n == 0 or n == 1:
		return 1;
	return n * fac(n-1)

def sum_dig(n):
	n_str = str(n)
	rolling_sum = 0
	for i in n_str:
		rolling_sum += int(i)
	return rolling_sum

if __name__ == "__main__":
	print "10: " + str(sum_dig(fac(10)))
	print "100: " + str(sum_dig(fac(100)))	
	
