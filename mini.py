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

def f(x):
	mu = 1.0 # Constraint multiplier
	c = min(0.0, x) # Constraint function
	return 1.6*x**3 + 3.0*x**2 - 2.0*x + mu*c**2

xStart = 1.0
h = 0.01
x1,x2 = bracket(f,xStart,h)
x,fMin = search(f,x1,x2)
print "x =",x
print "f(x) =",fMin
raw_input ("\nPress return to exit")