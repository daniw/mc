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
	DEC
	STA Error
	LDA Dividend		# Division
	DIV Divisor
	STA Quotient
	LDA Dividend		# Rest
	MOD Divisor
	STA Quotient
End:
	JMP End


00h	LDA 13h
01h	JNZ 06h
02h	CLR
03h	DEC
04h	STA 16h
05h	JMP 0Fh
06h	CLR
07h	DEC
08h	STA 16h
09h	LDA 12h
0Ah	DIV 13h
0Bh	STA 14h
0Ch	LDA 12h
0Dh	MOD 13h
0Eh	STA 14h
0Fh	JMP 0Fh





# Division: 
# Akkumulator / Operand