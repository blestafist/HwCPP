f (i)

если i < 3 → вернуть 1
иначе →
    если i % 2 = 0 → 
        f (i - 3) + f (i - 1) + 1
    иначе → вернуть f (i - 1) mod 7

четное - 3 → нечетное
нечетное - 1 → четное, число между 0 и 7, включительно, исключая четные числа, которые не делятся на 7


---

1.1

2 → 1
3 → 1
4 → 3
5 → 3
6 → 5
7 → 5
8 → 9


---

1.2

0 → 1
3 → 1
5 → 2
7 → 3
9 → 5
10 → 8

E (<3) → 1
E (i) → parzyste → E (i - 3) + E (i - 1)
E (i) → nieparzyste → E (i - 1)

---

1.3

W[0] <- 1
W[1] <- 1
W[2] <- 1
max_wart <- 1
dla i = 3, 4 ..., 1000 wykonuj
    jezeli i mod 2 = 0
        W[i] <- W[i-3] + W[i-1] + 1
    w przeciwnym razie
        W[i] <- W[i - 1] mod 7
    jezeli W[i] > max_wart
        max_wart <- W[i]
zwroc max_wart

