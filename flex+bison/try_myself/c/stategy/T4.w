function T(gameRows, Ones, pre, prePre){\
	if (gameRows == 1) then{\
		print(1);\
	}\
	else{\
		i = random(9);\
		if (i == 9) then{\
			print(0);\
		}\
		else{\
			print(pre);\
		};\
	};\
}
