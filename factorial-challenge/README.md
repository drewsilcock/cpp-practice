factorial-challenge
===================

Program to find the number of trailing zeros in the factorial of any given number.

Compilation
-----------

Just run `make`.

Usage
-----

Input any non-negative integer as the first argument, with no other arguments:

```bash
factorial-challenge 17856
> The number of trailing zeros in 17856! is 4461
```

Trust me, [it does work!](http://www.wolframalpha.com/input/?i=trailing+zeros+in+17856%21)

How It Works
------------

The trick to calculating how many trailing zeros any factorial has is first realising that the number of trailing zeros corresponds to the number of factors of 10 in the factorial. For every multiple of 10, you get a trailing zero.

The second step is to realise that every factor of 10 can be split into its prime factors, 2 and 5. Because factorials count down anti-sequentially in the product, there will always be more factors of 2 than factors of 5.

Thus, the number of trailing zeros is simply the number of factors of 5!

The final important thing to note is that 5\*5 = 25 needs to be counted as two factors of 5 (as that's exactly what it is), as opposed to other numbers like 5\*3 = 15 and 5\*4 = 20. The same applied to counting 125 three times, and so on.

Thus you simply count the number of times 5 goes into the number, plus the number of times 25 goes into the number (thereby counting these again a second time) plus the number of times 125 goes in to the number (thereby counting these thrice) and so on until our number is smaller than the power of 5.
