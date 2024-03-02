Image transformations are scaling, translation, rotation and shearing are affine transformations.


O--------------------->Y Axis
|
|
|
|
|
|
|
|
|
v
X axis


for all pixels X (x,y) /in Img,

a) scaling
	X' = (x',y') = TX
where T is transformation matris and

	X'=   =  |x'|   =   |Cx  0  0||x|
	         |y'|  	    |0   Cy 0||y|
	         |1 |       |0   0  1||1|

/implies
	x' = Cx * x
	y' = Cy * y

b) translations

	X'=   =  |x'|   =   |1  0  Cx||x|
	         |y'|  	    |0  1  Cy||y|
	         |1 |       |0  0   1||1|

c) Rotation:

	X'=   =  |x'|   =   |/cos(/theta)  -/sin(/theta)  0||x|
	         |y'|  	    |/sin(/theta)   /cos(/theta)  0||y|
	         |1 |       |     0             0         1||1|

d) Shearing
	i) Horizontal

		X'=   =  |x'|   =   |1  0  0||x|
		         |y'|  	    |Sh 1  0||y|
	        	 |1 |       |0  0  1||1|


	ii) Vertical

		X'=   =  |x'|   =   |1  Sv 0||x|
		         |y'|  	    |0  1  0||y|
		         |1 |       |0  0  1||1|


