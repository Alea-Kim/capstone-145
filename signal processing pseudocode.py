#signal processing @ one certain second per sensor:





#arduino
 int arr[10] = [59,208,32,102,1000,121,132,112,1000,41] #kunware cm then convert to 1,0's BINARY

 MAX = 1000 #from sensor

 for i in len(arr):
 	if(arr[i] < MAX)	arr[i] = 1
 	else arr[i] = 0



#webapp
 int arr[60] = [1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,] #1 may tao, 0 walang tao
 count1 = 0
 count2 = 0
 count3 = 0
 count4 = 0
 count5 = 0

 for i in len(arr):
	if arr[i] == 0: 		#count ilang beses nag empty/gumalaw ung pila in 60 seconds/1min
		count1++		   		#from 1-->0 or 0--1
						   		# e.g. count1 = 59, isa lang dumaan sa sensor. Lol. 
 for i in len(arr):		   		
	if arr[i] == 0:
		count2++
 
 for i in len(arr):
	if arr[i] == 0:
		count3++
 
 for i in len(arr):
	if arr[i] == 0:
		count4++
 
 for i in len(arr):
	if arr[i] == 0:
		count5++


MinuteAve =(count1+count2+count3+count4+count5)/5

#Is the line moving?
#for 60 seconds, average rate na nagmomove yung line. 

#range: 0-10 		Not Much 	   (around 0 - 5 person move/s forward per minute)
#range: 11-30   	Moderately (around 5 - 10 person move forward per minute)
#range 31 - 60 0's 	Continuously   (around 10 - 15 person move forward per minute)

print "Is the line moving?"
if(MinuteAve <= 10):
	print "Not much."
	print "around 0 - 5 person move/s forward per minute"
else if(MinuteAve >=11 or MinuteAve <= 30):
	print "Moderately."
	print "around 5 - 10 person move forward per minute"
else if(MinuteAve >=31 or MinuteAve <= 60):
	print "Continuously."
	print "around 10 - 15 person move/s forward per minute"

