# Bit Manipulation

DISCLAIMER: If you don't know what a binary number is, then don't read the rest of this page.

---

## Basics

<details>
    <summary>1s Complement</summary>

- Flip all the bits of a binary number
</details>

<details>
    <summary>2s Complement</summary>

- Calculate 1s Complement
- Add `1` to it
</details>

<details>
    <summary>How are negative numbers stored in memory?</summary>

[Read this](https://www.geeksforgeeks.org/how-the-negative-numbers-are-stored-in-memory/)
</details>

---
## Tricks
<details>
    <summary>Multiplication by 2^x</summary>

- Lets calculate 0110 * 2
- which is 0110 + 0110 = 1100
- observe that all the bits are shifted by 1 bit to the left
- `binary_numer * 2` is equivalent to `binary_number << 1`
- Further results, what if I want to multiply binary number with 2^23 ?
- Simply, shift 23 bits to the left, which is `binary_number << 23`
</details>

<details>
    <summary>XOR with negated binary number</summary>

- `1100 ^ (~1100) = 1111`
- XORing with its negated value is a sequence of 1s

</details>

<details>
    <summary>Clearing bits from the right</summary>

- `1011 & (~0 << 2)`
- `~0` is a sequence of 1s
- So, left shifting by `2` will be 2 zeroes at the right, followed by 1s
- ANDing it with a number will clear the last 2 bits
- ` = 1000`
</details>


