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
- A positive number is represented as itself while a negative number is represented as the 2s complement of its absolute value, with a 1 in its sign bit to indicate that a negative value
- In simple words, the binary representation of `-K` as a N-bit number is `concat(1, 2^(N-1) - K)`
- More simpler words, invert the bits in the positive representation and then add 1
- Example: +7 = 0 111
- Calculating -7 ?
- Flip the bits of +7 = 000
- Add 1 to it = 001
- Prefix with sign bit -7 = 1 001
</details>

<details>
    <summary>Rules</summary>

|Equation|Result|
| --- | --- |
|`x ^ 0`|`x`|
|`x ^ 1`|`~x`|
|`x ^ x`|`0`|
|`x & 0`|`0`|
|`x & 1`|`x`|
|`x & x`|`x`|
|`x \| 0`|`x`|
|`x \| 1`|`1`|


</details>

<details>
    <summary>Arithmetic vs. Logical Right Shift</summary>

- There are 2 types of right shift operators
- Arithmetic Right Shift essentially divides by 2 (shifts the bits to the right and fills the MSB with sign bit)
- Example, `-75 = 1 0110101`
- `-75 >> 1 = 1 1011010 = -38`
- Logical Right Shift does exactly what we think right shifting means (shifts the bits to the right and fills the MSB with 0)
- Example, `-75 = 1 0110101`
- `-75 >>> 1 = 0 1011010 = 90`

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

<details>
    <summary>Get Bit</summary>

- Shift 1 over by i bits (i = which bit you wanna get), creating a value that looks like `00100000`
- Then do logical AND with the number, and compare it with `0`
- If the ith bit was set, then the result won't be `0`
- Example, Check if 5th bit from right is set or not, `10110110`
- We take `00000001`, left shift by 5
- `00000001 << 5 = 00100000`
- logical AND with given number, `00100000 & 10110110 = 00100000`
- which is not equal to `0`, so the 5th bit from right was set


<code>

    bool getBit(int num, int i) {
        return ((num & (1 << i)) != 0);
    }

</code>
</details>


<details>
    <summary>Set Bit</summary>

- Setting a bit is quite easy
- Just shift the 1 to the desired location and do a logical OR


<code>

    int setBit(int num, int i) {
        return num | (1 << i);
    }

</code>
</details>

<details>
    <summary>Clear Bit</summary>

- Very similar to set bit, but here we negate the mask
- Create a number like `11011111`, then do logical AND

<code>

    int clearBit(int num, int i) {
        int mask = ~(1 << i);
        return num & mask;
    }
</code>

- Clearing bits from MSB to i (inclusive)

<code>

    int clearBitMSBThroughI(int num, int i) {
        int mask = (1 << i) - 1;
        return num & mask;
    }
</code>


- Clearing bits from i to 0 (inclusive)

<code>

    int clearBitIThrough0(int num, int i) {
        int mask = (-1 << (i + 1));
        return num & mask;
    }
</code>
</details>

<details>
    <summary>Update Bit</summary>

- It is a combination of clear bit and set bit

<code>

    int updateBit(int num, int i, bool bit) {
        int val = bit ? 1 : 0;
        int mask = ~(1 << i);
        return (num & mask) | (value << i);
    }
</code>
</details>