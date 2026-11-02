LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY gm IS
PORT (
	clk   : IN  bit;
	reset : IN  bit;
	xn    : IN  integer;
	yn    : OUT integer
	);
END gm;

ARCHITECTURE beh OF gm IS
   SIGNAL xn1, xn2, xn3, result : integer;
BEGIN
   regs: PROCESS (clk, reset)
	BEGIN
		IF reset = '1' THEN
			xn1 <= 0;
			xn2 <= 0;
			xn3 <= 0;
			yn  <= 0;
		ELSIF clk'event AND clk = '1' THEN 
			xn1 <= xn;
			xn2 <= xn1;
			xn3 <= xn2;
			yn <= result;
		END IF; 
	END PROCESS regs;
	
	comb: PROCESS (xn, xn1, xn2, xn3)
		VARIABLE i1, i2, i3 : integer := 0;
	BEGIN
		i1 := xn + xn1;
		i2 := i1 + xn2;
		i3 := i2 + xn3;
		result <= i3 / 4;
	END PROCESS comb;

END beh;