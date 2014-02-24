# Division for Mikrosim
.DEF Dividend 12h
.DEF Divisor  13h
.DEF Quotient 14h
.DEF Rest     15h
.DEF Error    16h


Start:
	LDA Divisor		# If Divisor == 0
	JNZ Division
	CLR					# Set Error Flag
	DEC
	STA Error
	JMP End
Division:			# Else
	CLR					# Clear Error Flag
	STA Error
	LDA Dividend		# Division
	DIV Divisor
	STA Quotient
	LDA Dividend		# Rest
	MOD Divisor
	STA Quotient
End:				# Stop
	JMP End


00h	LDA 13h
01h	JNZ 06h
02h	CLR
03h	DEC
04h	STA 16h
05h	JMP 0Eh
06h	CLR
07h	STA 16h
08h	LDA 12h
09h	DIV 13h
0Ah	STA 14h
0Bh	LDA 12h
0Ch	MOD 13h
0Dh	STA 15h
0Eh	JMP 0Eh





# Division: 
# Akkumulator / Operand