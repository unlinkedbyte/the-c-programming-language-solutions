# Exercise 1.10 - Making Control Characters Visible (Personal Notes)

## 🧪 Proof of Concept (PoC) & How to Test It

At first glance, typing into the terminal won't show the `\b` (backspace) because the OS deletes the letters in memory before the program even sees them. To actually test this without the keyboard getting in the way, we can feed a raw file directly into the program using Unix input redirection.

Run these commands in your terminal to check (you can see what actually looks the test.txt with a cat before running the code):

```bash
# 1. Compile
gcc main.c -o replace

# 2. Create a test file with a real hardware tab and backslash
echo -e "Hello\tWorld\b\\C-programming" > test.txt

# 3. Stream the file into the binary using input redirection (<)
./replace < test.txt
```

---

## 📝 Technical Notes (How it works under the hood)

1. **The Input Redirection (`<`):**
   The `<` operator is a switch at the Kernel level. It completely disconnects the keyboard from `stdin` and plugs in the `test.txt` file instead. Our program doesn't know (or care) about this switch; `getchar()` just keeps reading bytes from the file one by one until it hits the automatic `EOF` (End-Of-File) signal and stops.

2. **The Terminal vs. Raw Bytes (`echo -e`):**
   Usually, when you press Backspace, the terminal cleans up your mistakes interactively. By using `echo -e`, we bypass this and inject raw control bytes (like ASCII 9 for tabs) straight into the file payload. This forces the C loop to intercept them sequentially.

3. **Output Multiplexing (The "Replacement" Illusion):**
   We don't need fancy string replacement functions. The Unix way here is to trick the output stream. When the program catches a target character (like a tab), it simply skips printing the tab and runs two `putchar()` commands back-to-back (printing `\` and then `t`). To print a single backslash on the screen, we must type `\\` because a single `\` is reserved as the escape character.

