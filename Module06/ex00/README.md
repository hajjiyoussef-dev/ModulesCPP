# Module06 ex00 - ScalarConverter

## What I changed

This exercise converts a string input into the scalar types:
- `char`
- `int`
- `float`
- `double`

I fixed the conversion logic in `ScalarConverter.cpp` so it handles edge cases more safely and matches the expected subject behavior better.

## Fixes made

- Handled pseudo-literals first:
  - `nan`
  - `nanf`
  - `+inf`
  - `-inf`
  - `+inff`
  - `-inff`
- Removed invalid `isnan` checks from `char` and `int` printing.
- Added range checks before casting floating-point values to `int`.
- Used the original parsed numeric value to decide whether the `int` conversion is valid, so rounded float values do not produce wrong results.

## Behavior examples

- `./convert nan` prints:
  - `char: impossible`
  - `int: impossible`
  - `float: nanf`
  - `double: nan`

- `./convert 2147483647.f` prints:
  - `int: 2147483647`

- `./convert 2147483650.f` prints:
  - `int: impossible`

- `./convert -2147483650.f` prints:
  - `int: impossible`

## Verification

I built the project with:

```bash
make fclean && make
```

I also tested these inputs:

```bash
./convert nan
./convert nanf
./convert +inf
./convert -inff
./convert 42
./convert a
./convert 0
./convert 0.0f
./convert 1e309
./convert 2147483647.f
./convert -2147483650.f
```

## Hard Tests

These edge cases were used to stress the conversion logic:

- `./convert 2147483647.f`
  - `char: Non displayable`
  - `int: 2147483647`
  - `float: 2147483648.0f`
  - `double: 2147483648.0`

- `./convert -2147483650.f`
  - `char: Non displayable`
  - `int: impossible`
  - `float: -2147483648.0f`
  - `double: -2147483648.0`

- `./convert 2147483648`
  - `char: impossible`
  - `int: impossible`
  - `float: 2147483648.0f`
  - `double: 2147483648.0`

- `./convert -2147483649`
  - `char: impossible`
  - `int: impossible`
  - `float: -2147483648.0f`
  - `double: -2147483649.0`

- `./convert 999999999999999999999`
  - `char: impossible`
  - `int: impossible`
  - `float: 1000000020040877342720.0f`
  - `double: 1000000000000000000000.0`

Notes:
- `float` can lose precision on very large inputs, so the printed `float` value may differ from the original string.
- The `int` conversion is now checked against the original parsed value, so rounded floating-point values do not overflow silently.
