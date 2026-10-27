
// modulo counter
SC_MODULE(counter)
{
    sc_in_clk clock;
    sc_in<bool> reset;
    sc_in<bool> enabled;
    sc_in<bool> increment_mode;
    sc_out< T > out;

    // counter value
    T count_val;

    void do_count() {
        if (reset.read()) {
            count_val = 0;  // if reset set counter to zero
        } else {
            if (enabled.read()) {
                if (increment_mode.read())
                    count_val = count_val + 1;
                else
                    count_val = count_val - 1;
            }
        }
        out = count_val;
    }

    SC_CTOR(counter) {
        // process sentitive to positive clock edge
        SC_METHOD(do_count);
        sensitive << clock.pos();
    }
};
