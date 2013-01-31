from numpy import identity,array,dot,zeros,argmax
from goldSearch import *
from math import sqrt
from math import log

def bracket(f,x1,h):
	c = 1.618033989
	f1 = f(x1)
	x2 = x1 + h; f2 = f(x2)

	if f2 > f1:
		h = -h
		x2 = x1 + h; f2 = f(x2)

		if f2 > f1: return x2,x1 - h

	for i in range (100):
		h = c*h
		x3 = x2 + h; f3 = f(x3)
		if f3 > f2: return x1,x3
		x1 = x2; x2 = x3
		f1 = f2; f2 = f3
	print "Bracket did not find a minimum"
	
def search(f,a,b,tol=1.0e-9):
	nIter = -2.078087*log(tol/abs(b-a)) # Eq. (10.4)
	R = 0.618033989
	C = 1.0 - R

	x1 = R*a + C*b; x2 = C*a + R*b
	f1 = f(x1); f2 = f(x2)

	for i in range(nIter):
		if f1 > f2:
			a = x1
			x1 = x2; f1 = f2
			x2 = C*a + R*b; f2 = f(x2)
		else:
			b = x2
			x2 = x1; f2 = f1
			x1 = R*a + C*b; f1 = f(x1)
	if f1 < f2: return x1,f1
	else: return x2,f2
	
def powell(F,x,h=0.1,tol=1.0e-6):
	def f(s): return F(x + s*v) # F in direction of v

	n = len(x) # Number of design variables
	df = zeros(n) # Decreases of F stored here
	u = identity(n) # Vectors v stored here by rows
	for j in range(30): # Allow for 30 cycles:
		xOld = x.copy() # Save starting point
		fOld = F(xOld)
		# First n line searches record decreases of F
		for i in range(n):
			v = u[i]
			a,b = bracket(f,0.0,h)
			s,fMin = search(f,a,
			df[i] = fOld - fMin
			fOld = fMin
			x = x + s*v
		# Last line search in the cycle
		v = x - xOld
		a,b = bracket(f,0.0,h)
		s,fLast = search(f,a,b)
		x = x + s*v
		# Check for convergence
		if sqrt(dot(x-xOld,x-xOld)/n) < tol: return x,j+1
		# Identify biggest decrease & update search directions
		iMax = argmax(df)
		for i in range(iMax,n-1):
			u[i] = u[i+1]
		u[n-1] = v
	print "Powell did not converge"
	
	
def F(x): return 100.0*(x[1] - x[0]**2)**2 + (1 - x[0])**2
xStart = array([-1.0, 1.0])
xMin,nIter = powell(F,xStart)

print "x =",xMin
print "F(x) =",F(xMin)
print "Number of cycles =",nIter
raw_input ("Press return to exit")