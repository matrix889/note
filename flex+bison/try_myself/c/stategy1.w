function T(gameRows, Ones, pre, prePre){\
	i = 1;\
	k = 1;\
	if (gameRows == 1) then{\
		print(1);\
	}\
	else{\
		if (Ones > 0) then{\
			print(0);\
		}\
		else{\
			print(1);\
		};\
	};\
}
T(10,1,0,0)
