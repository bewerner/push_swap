## Rules

The goal ist to sort a list of random numbers using two stacks with as few operations as possible.

The only operations allowed are:

```
pa: Push the number on top of stack a to the top of stack b.
pb: Push the number on top of stack b to the top of stack a.

sa: Swap the two numbers on top of stack a.
sb: Swap the two numbers on top of stack b.
ss: sa and sb at the same time. Only counts as one operation.

ra: Shift the position of each number on stack a up by one. The number on the top gets moved to the bottom.
rb: Shift the position of each number on stack b up by one. The number on the top gets moved to the bottom.
rr: ra and rb at the same time. Only counts as one operation.

rra: Shift the position of each number on stack a down by one. The number on the bottom gets moved to the top.
rrb: Shift the position of each number on stack b down by one. The number on the bottom gets moved to the top.
rrr: rra and rrb at the same time. Only counts as one operation.
```

---

## Example

<table>
<tr><td>

> ⠀

| 6 | ⠀ |
|---|---|
| 3 |   |
| 8 |   |
| 7 |   |
| 1 |   |

| a | b |
|---|---|

</td><td>

> pb

|   | ⠀ |
|---|---|
| 3 |   |
| 8 |   |
| 7 |   |
| 1 | 6 |

| a | b |
|---|---|

</td><td>

> pb

|   | ⠀ |
|---|---|
|   | ⠀ |
| 8 |   |
| 7 | 3 |
| 1 | 6 |

| a | b |
|---|---|

</td><td>

> ss

|   | ⠀ |
|---|---|
|   | ⠀ |
| 7 |   |
| 8 | 6 |
| 1 | 3 |

| a | b |
|---|---|

</td><td>

> pa

|   | ⠀ |
|---|---|
| 6 |   |
| 7 |   |
| 8 |   |
| 1 | 3 |

| a | b |
|---|---|

</td><td>

> pa

| 3 | ⠀ |
|---|---|
| 6 |   |
| 7 |   |
| 8 |   |
| 1 |   |

| a | b |
|---|---|

</td><td>

> ra

| 1 | ⠀ |
|---|---|
| 3 |   |
| 6 |   |
| 7 |   |
| 8 |   |

| a | b |
|---|---|

</td></tr> </table>

---

## My results

Average moves for 100 numbers:  559

Average moves for 500 numbers: 3856

---

## push_swap

`make`

`./push_swap <random numbers>`

---

## checker (push_swap_bonus)

`make bonus`

`./checker <random numbers>` or `ARG="<random numbers"; ./push_swap $ARG | ./checker $ARG`

---
