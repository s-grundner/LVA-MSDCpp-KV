LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;

ENTITY tb IS
END tb;

ARCHITECTURE beh OF tb IS
	COMPONENT gm
	PORT (
		clk   : IN  bit;
		reset : IN  bit;
		xn    : IN  integer;
		yn    : OUT integer
		);
	END COMPONENT;

   SIGNAL clk, reset: bit := '0';
   SIGNAL y : integer;
   SIGNAL x : integer := 0;
   SIGNAL xn, yn : signed(31 downto 0);

BEGIN
	xn <= to_signed(x, 32);
	yn <= to_signed(y, 32);

	u1: gm PORT MAP(clk, reset, x, y);

	clk <= NOT clk after 5 ns;
	
	samples: PROCESS
	BEGIN
		reset <= '1';
		WAIT FOR 10 ns;
		reset <= '0';
		x <= 50;
		FOR i IN 1 TO 4 LOOP
			WAIT FOR 10 ns;
		END LOOP;
		x <= 10;
		WAIT FOR 10 ns;
		x <= 50;
		WAIT;

	END PROCESS samples;

END beh;