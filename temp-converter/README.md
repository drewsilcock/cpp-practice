temp-converter
==============

Simple program that takes from the command line arguments a temperature, e.g. `24.7C`, and outputs that temperature converted to Fahrenheit and Kelvin temperature scales.

Compilation
-----------

As per usual, a simple `make` should suffice.

Usage
-----

Just run the binary, with the temperature you want as the final character.

It supports Celsius:

```bash
$ ./temp-converter 67.2C
> The converted temperature is: 152.96F or 340.35K
```

As well as Fahrenheit:

```bash
$ ./temp-converter 99.3F
> The converted temperature is: 37.3889C or 310.539K
```

And also Kelvin:

```bash
$ ./temp-converter 300.1K
> The converted temperature is: 26.95C or 80.51F
```
